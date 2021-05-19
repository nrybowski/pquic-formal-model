#! /bin/bash

MAIN_DIR="/mount"
DATA="${MAIN_DIR}/data"

BPF_OPTS="--bmc=mono --inline --track=mem --dsa=sea-cs --log=cex --bv-cex -m64 --cpu=600 --mem=4000 -g -DDISABLE_PROTOOP_PRINTF -DDISABLE_QLOG -DSEAHORN_VERIFICATION -I/opt/picoquic /opt/picoquic/*.c /opt/model/verifier/verifier.c"
VALGRIND_OPTS="--tool=massif --trace-children=yes --pages-as-heap=yes"

loop () {
	local fun=${1}

	# Main loop on the tests cases for each protoop
	local plugins=($(ls "${MAIN_DIR}"))
	for plugin in ${plugins[@]}
	do
		local curdir="${MAIN_DIR}/${plugin}"
		if [[ -d "${curdir}" && "${plugin}" != "data" ]]
		then
			echo "Testing protoop <${plugin}>"

			pluglets=($(ls ${curdir} | grep -E '\.c'))
			for pluglet in ${pluglets[@]} 
			do
				((COUNT++))
				echo "-> Test (${COUNT}) <${pluglet}>"
				local outdir="${DATA}/${plugin}/${pluglet}"
				mkdir -pv "${outdir}"
				cd "${outdir}"
				${fun} "${plugin}" "${pluglet}" "${outdir}"
				cd "${outdir}"
			done
		fi
	done
}

collect_data() {
	local plugin="${1}"
	local pluglet="${2}"
	local outdir="${3}"
	
	local rundir="/tmp/${plugin}/${pluglet}"
	mkdir -pv "${rundir}"
	cd "${rundir}" || return
	
	for i in {0..4}
	do
		echo "Run $i"

		# Test and time first pass
		/usr/bin/time -o "duration${i}.txt" -f "%e" sea bpf ${BPF_OPTS} "/mount/${plugin}/${pluglet}" "/opt/model/checks/specs_check__${pluglet}" > output.txt 2>&1
		grep "unsat" output.txt > /dev/null
		if [[ $? -ne 0 ]]
		then
			echo "didn't get unsat on first run"
			return
		fi

		echo "Got unsat"
		cat "duration${i}.txt" >> "${outdir}/durations.txt"

		# Test if legit unsat on first run
		if [[ ${i} -eq 0 ]]
		then
			sea bpf ${BPF_OPTS} "/mount/${plugin}/${pluglet}" "/opt/model/checks/specs_check__${pluglet}" -DSASSERT_FALSE > output.txt 2>&1
			grep "unsat" output.txt > /dev/null
			if [[ $? -eq 0 ]]
			then
				echo "unsat on sassert(0)"
				return
			fi

			grep "sat" output.txt > /dev/null
			if [[ $? -ne 0 ]]
			then
				# didn't get sat
				echo "unknown state"
				return
			fi
		fi

		# Got sat, measure memory consumption
		local run="run${i}"
		mkdir -pv "${run}"
		cd "${run}" || return

		valgrind ${VALGRIND_OPTS} sea bpf ${BPF_OPTS} "/mount/${plugin}/${pluglet}" "/opt/model/checks/specs_check__${pluglet}" > /dev/null 2>&1
		#mv $(ls massif.out.* | tail -n 1) "${outdir}/massif_horn${i}.out"

		local peak peak_line massif massif_print
		massif="$(find massif.out.* | tail -n 1)"
		massif_print="$(ms_print "${massif}")"
		echo "${massif_print}" | grep -E "/home/usea/seahorn/bin/seahorn --horn-bmc --keep-shadows=true --sea-dsa=cs --horn-solve -horn-inter-proc -horn-sem-lvl=mem --horn-step=large -log cex" > /dev/null
		if [[ $? -eq 0 ]]
		then
			peak=$(echo "${massif_print}" | grep -o -E "[0-9]* \(peak\)" | grep -o "[0-9]*")
			IFS=" " read -ra peak_line <<< "$(echo "${massif_print}" | grep -E " ${peak} * [0-9]*,[0-9]*")"
			echo "${peak_line[2]}" >> "${outdir}/peaks.txt"
		else
			echo "Consider wrong massif output"
		fi

		cd ..

	done

}

loop collect_data

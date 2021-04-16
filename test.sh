#! /bin/bash

BPF_OPTS="--bmc=mono --inline --track=mem --dsa=sea-cs --log=cex --bv-cex"
OPTS="-m64 --cpu=300 --mem=500 -g -DDISABLE_PROTOOP_PRINTF -DDISABLE_QLOG -DSEAHORN_VERIFICATION -I/opt/pquic/picoquic /opt/pquic/picoquic/*.c /opt/model/verifier/verifier.c"

run_test() {
	local pluglet="${1}"
	local test_case="${2}"
	local unsat_bug="${3}"

	local out=$(mktemp --tmpdir="/tmp")
	local files="/mount/${pluglet}/${test_case} /opt/model/checks/specs_check__${pluglet}.c"

	# Launch SH verification on the test case
	if [[ ${unsat_bug} -eq 1 ]]
	then
		sea bpf ${BPF_OPTS} --cex="${test_case}".ll -DSASSERT_FALSE ${OPTS} ${files} > ${out} 2>&1
	else
		sea bpf ${BPF_OPTS} --cex="${test_case}".ll ${OPTS} ${files} > ${out} 2>&1
	fi

	# If output file exists (seahorn did something)
	if [[ -f "${out}" ]]
	then
		# Search if false negtive result
		grep -E "unsat" "${out}" > /dev/null
		if [[ $? -eq 0 ]]
		then
			if [[ ${unsat_bug} -eq 1 ]]
			then
				echo "* got unsat with sassert(0). Something is wrong."
			else
				echo "* got false negative. Verifying if SeaHorn bug"
				#cat "${out}"
				rm "${out}"
				run_test "${CE}" "${TEST_CASE}" 1
			fi
		else
			# not false negative, check if got a positive result
			grep -E "sat" "${out}" > /dev/null
			if [[ $? -eq 0 ]]
			then
				# got a positive result, verify it with CEX
				echo "* sat (expected). Verifying sat validity."
				if [[ ${unsat_bug} -eq 1 ]]
				then
					sea exe -DSASSERT_FALSE ${OPTS} ${files} "${test_case}.ll" -o "${test_case}.out" > /dev/null 2>&1
				else
					sea exe ${OPTS} ${files} "${test_case}.ll" -o "${test_case}.out" > /dev/null 2>&1
				fi

				./run_expect.sh "${test_case}" > /dev/null

				# positive result found and proved
				if [[ $? -eq 0 ]]
				then
					echo "* sat is valid"
					if [[ ${unsat_bug} -eq 1 ]]
					then
						echo "* model didn't found the CE."
					fi
				else
					echo "* unable to reach the error location with CEX."
				fi
			# Should not happen, it means that seahorn TO or crashed for other reasons
			else
				echo -e "Unknown state\n"
				cat "${out}"
			fi
		fi
		# Remove intermediate output file
		rm "${out}"
	
	# Should not happen, SeaHorn is expected to return some logs whatever situation it encounters
	else
		echo -e "Some error occured\n"
	fi
}

# Main loop on the tests cases for each protoop
CE_DIR="/mount/"
CES=($(ls "${CE_DIR}"))

echo -e "\n\nBegin tests\n"

for CE in ${CES[@]}
do
	CURDIR="${CE_DIR}/${CE}"
	if [[ -d "${CURDIR}" ]]
	then
		echo "Testing protoop <${CE}>"

		CASES=($(ls ${CURDIR} | grep -E '\.c'))
		for TEST_CASE in ${CASES[@]} 
		do
			echo "-> Test <${TEST_CASE}>"
			run_test "${CE}" "${TEST_CASE}" 0
		done
		echo -e "\n"
	fi
done

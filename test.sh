#! /bin/bash

CMD="sea bpf --cpu=300 --mem=500 -g --bmc=mono --inline --track=mem -m64 --dsa=sea-cs -DDISABLE_PROTOOP_PRINTF -DDISABLE_QLOG -DSEAHORN_VERIFICATION -Ipquic/picoquic pquic/picoquic/*.c model/verifier/verifier.c"

run_test() {
	local pluglet="${1}"
	local test_case="${2}"
	local out=$(mktemp --tmpdir="/tmp")

	${CMD} "/mount/${pluglet}/${test_case}" "model/checks/specs_check__${pluglet}.c" > ${out} 2>&1

	if [[ -f "${out}" ]]
	then
		grep -E "unsat" "${out}" >> /dev/null
		if [[ $? -eq 0 ]]
		then
			echo -e "unsat\n"
			cat "${out}"
		else
			grep -E "sat" "${out}" >> /dev/null
			if [[ $? -eq 0 ]]
			then
				echo "sat (expected)"
			else
				echo -e "Unkown state\n"
				cat "${out}"
			fi
		fi
		rm "${out}"
	else
		echo -e "Some error occured\n"
	fi
}

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
			run_test "${CE}" "${TEST_CASE}"
		done
	fi
	echo -e "\n"
done

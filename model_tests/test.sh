#! /bin/bash

POSITIVE="${1}"

BPF_OPTS="--bmc=mono --inline --track=mem --dsa=sea-cs --log=cex --bv-cex"
OPTS="-m64 --cpu=300 --mem=500 -g -DDISABLE_PROTOOP_PRINTF -DDISABLE_QLOG -DSEAHORN_VERIFICATION -I/opt/pquic/picoquic /opt/pquic/picoquic/*.c /opt/model/verifier/verifier.c"
COUNT=0
SAT=0
UNSAT_D_UNSAT=0
UNSAT_D_SAT=0
UNK_STATE=0
CEX_SOLVER=0

run_test() {
	local pluglet="${1}"
	local test_case="${2}"
	local unsat_bug="${3}"

	local out=$(mktemp --tmpdir="/tmp")
	if [[ "${POSITIVE}" == "1" ]]
	then
		local files="/mount/${test_case} /opt/model/checks/specs_check__${test_case}"
	else
		local files="/mount/${pluglet}/${test_case} /opt/model/checks/specs_check__${pluglet}.c"
	fi

	# Launch SH verification on the test case
	if [[ ${unsat_bug} -eq 1 ]]
	then
		# A first unsat has been experienced, we test if SeaHorn is able to detect sassert(0)
		sea bpf ${BPF_OPTS} --cex="${test_case}".ll -DSASSERT_FALSE ${OPTS} ${files} > ${out} 2>&1
	else
		# First SeaHorn run
		sea bpf ${BPF_OPTS} --cex="${test_case}".ll ${OPTS} ${files} > ${out} 2>&1
	fi

	# If output file exists (seahorn did something)
	if [[ -f "${out}" ]]
	then
		grep -E "unsat" "${out}" > /dev/null
		if [[ $? -eq 0 ]]
		then
			if [[ ${unsat_bug} -eq 1 ]]
			then
				# unsat with sassert(0) after unsat, SeaHorn is someway broken.
				echo "* got unsat with sassert(0). Something is wrong."
				((UNSAT_D_UNSAT++))
			else
				# First unsat
				if [[ "${POSITIVE}" == "1" ]]
				then
					echo "* unsat. (expected)"
				else
					echo "* unsat. (unexpected)"
				fi

				echo "* Verifying if SeaHorn bug"
				rm "${out}"
				if [[ "${POSITIVE}" == "1" ]] 
				then
					run_test "UNUSED" "${test_case}" 1
				else
					run_test "${pluglet}" "${test_case}" 1
				fi
			fi
		else
			grep -E "sat" "${out}" > /dev/null
			if [[ $? -eq 0 ]]
			then
				# Got sat, produce CEX
				if [[ ${unsat_bug} -eq 1 ]]
				then
					# sat after unsat bug test
					echo "* sat (expected)."
					sea exe -DSASSERT_FALSE ${OPTS} ${files} "${test_case}.ll" -o "${test_case}.out" > /dev/null 2>&1
				else
					# First sat
					if [[ "${POSITIVE}" == "1" ]]
					then
						echo "* sat (unexpected)."
					else
						echo "* sat (expected)."
					fi
					sea exe ${OPTS} ${files} "${test_case}.ll" -o "${test_case}.out" > /dev/null 2>&1
				fi

				# Test CEX
				echo "* Verifying sat validity"
				./run_expect.sh "${test_case}" > /dev/null

				if [[ $? -eq 0 ]]
				then
					# CEX reached the error found by solver
					echo "* sat is valid."
					if [[ ${unsat_bug} -eq 1 ]]
					then
						# Valid forced sat, thus valid first unsat
						if [[ "${POSITIVE}" == "1" ]]
						then
							echo "* [V] Model did a correct unsat."
						else
							echo "* [X] Invalid model: unsat when should sat."
						fi
						((UNSAT_D_SAT++))
					else
						# Valid first sat
						if [[ "${POSITIVE}" == "1" ]]
						then
							echo "* [X] Invalid model: sat when should unsat"
						else
							echo "* [V] Model did a correct sat."
						fi
						((SAT++))
					fi
				else
					# CEX and solver do not agree
					echo "* Unable to reach the error location with CEX."
					((CEX_SOLVER++))
				fi
			else
				# Should not happen, it means that seahorn TO or crashed for other reasons
				echo -e "* Unknown state\n"
				((UNK_STATE++))
				cat "${out}"
			fi
		fi

		if [[ -f "${out}" ]]
		then
			# Remove intermediate output file
			rm "${out}"
		fi
	
	else
		# Should not happen, SeaHorn is expected to return some logs whatever situation it encounters.
		echo "Some error occured. SeaHorn did not produced any logs."
	fi
}

# Main loop on the tests cases for each protoop
CE_DIR="/mount/"

if [[ "${POSITIVE}" == "1" ]]
then
	echo -e "\n\nTesting for simple false positives"
	echo "=================================="
	CES=($(ls "${CE_DIR}" | grep -E '\.c'))

	for CE in ${CES[@]}
	do
		echo "-> Testing protoop <${CE}>"
		((COUNT++))
		run_test "UNUSED" "${CE}" 0
	done

	cat <<EOF

Results:
- ${UNSAT_D_SAT}/${COUNT} correct unsat
- ${SAT}/0 sat when should unsat (Invalid model)
- ${UNSAT_D_UNSAT}/0 buggy unsat
- ${UNK_STATE}/0 unkown state. Test has probably timed out (memory/cpu)
- ${CEX_SOLVER}/0 CEX and Solver do not agree on sat.
EOF

else

	echo -e "\n\nTesting for simple false negatives"
	echo "=================================="
	CES=($(ls "${CE_DIR}"))

	for CE in ${CES[@]}
	do
		CURDIR="${CE_DIR}/${CE}"
		if [[ -d "${CURDIR}" ]]
		then
			echo "Testing protoop <${CE}>"

			CASES=($(ls ${CURDIR} | grep -E '\.c'))
			for TEST_CASE in ${CASES[@]} 
			do
				((COUNT++))
				echo "-> Test <${TEST_CASE}>"
				run_test "${CE}" "${TEST_CASE}" 0
			done
		fi
	done
	
	cat << EOF

Results:
- ${SAT}/${COUNT} correct sat.
- ${UNSAT_D_SAT}/0 incorrect unsat (Invalid model).
- ${UNSAT_D_UNSAT}/0 buggy unsat
- ${UNK_STATE}/0 unkown state. Test has probably timed out (memory/cpu)
- ${CEX_SOLVER}/0 CEX and Solver do not agree on sat.
EOF
fi

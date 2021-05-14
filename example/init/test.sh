#! /bin/bash

BPF="sea bpf -m64 -g --bmc=mono --inline --track=mem --dsa=sea-cs --cex=witness.ll --log=cex --bv-cex --horn-bv-part-mem /mount/init/init.c"
CEX="sea exe -DTEST"${TEST}" -g -m64 --alloc-mem /mount/init/init.c witness.ll -o out"

test() {
	local test="${1}"
	local case="${2}"

	rm tmp.txt witness.ll out > /dev/null 2>&1
	time ${BPF} -DTEST"${test}" ${case} > tmp.txt 2>&1 
	grep unsat tmp.txt
	if [[ $? -ne 0 ]]
	then
		grep sat tmp.txt
		if [[ $? -eq 0 ]]
		then
			${CEX} -DTEST"${test}" ${case} > /dev/null 2>&1
			valgrind ./out
		fi
	fi
}


for CASE in "-DNONE" -"DFAIL" "-DPTR" "-DPTR -DPTR_INIT" "-DFAIL -DPTR" "-DFAIL -DPTR -DPTR_INIT"
do
	echo  "0" "${CASE}"
	test "0" "${CASE}"
done

echo

for TEST in {1..10}
do
	for CASE in "-DNONE" "-DPTR" "-DPTR -DPTR_INIT"
	do
		echo  "${TEST}" "${CASE}"
		test "${TEST}" "${CASE}"
	done
	echo 
done

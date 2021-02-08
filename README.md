```console
cd "${PQUIC}"/
docker run -it $(pwd):/host
# inside container
cd /host
sea bpf --bmc=mono --inline --crab --track=mem --dsa=sea-cs -g -m64 -Ipicoquic -DDISABLE_PROTOOP_PRINTF -DDISABLE_QLOG picoquic/getset.c picoquic/verifier/verifier.c picoquic/verifier/verifier.c <plugin.c> [--cex=cex.ll]
sea exe -g -m64 -Ipicoquic -DDISABLE_PROTOOP_PRINTF picoquic/getset.c picoquic/verifier/verifier.c picoquic/verifier/verifier.c <plugin.c> cex.ll -o cex
gdb ./cex
# set disable-randomization off
```

`--bmc=mono --inline` = https://gitter.im/seahorn/seahorn?at=5c19166dc35a3002474430d9 => solved bitfield issue
`--track=mem` =  model both scalars, pointers, and memory contents
`--dsa=sea-cs` = context sensitive memory check => solved infinite seahorn run


#! /bin/bash -e

MOUNT="${1}"
DOCKERFILE=$(mktemp)
CONTAINERNAME="seahorn_base"

cat << EOF >> ${DOCKERFILE}
FROM seahorn/seahorn-llvm10:nightly
RUN echo horn | sudo -S apt-get update
RUN echo horn | sudo -S DEBIAN_FRONTEND=noninteractive su -p - -c "apt-get install -y --no-install-recommends --fix-missing libarchive-dev libssl-dev valgrind gdb time"
EOF

docker build -t "${CONTAINERNAME}" -f "${DOCKERFILE}" .
rm "${DOCKERFILE}"

BPF_OPTS="-m64 -g --bmc=mono --inline --track=mem --dsa=sea-cs \
	--cex=witness.ll --log=cex --bv-cex --horn-bv-part-mem \
	-I/opt/picoquic -DDISABLE_PROTOOP_PRINTF -DDISABLE_QLOG /opt/model/verifier/verifier.c /opt/picoquic/*.c"

EXE_OPTS="-g -m64 --alloc-mem -o out witness.ll"

#	--cap-add=SYS_ADMIN \
docker run \
	--rm -it \
	--tmpfs /tmp \
	-v "${PWD}/verifier:/opt/model/verifier" \
	-v $(pwd)/checks:/opt/model/checks \
	-v $(pwd)/pquic/picoquic:/opt/picoquic \
	-v "$(pwd)/${MOUNT}":/mount \
	-w /tmp \
	-e BPF_OPTS="${BPF_OPTS}" \
	-e EXE_OPTS="${EXE_OPTS}" \
	"${CONTAINERNAME}" bash

# Example (./simple_wrapper.sh plugins):
# * sea bpf ${BPF_OPTS} /mount/be.michelfra.disable_cc/congestion_algorithm_notify.c /opt/model/checks/specs_check__congestion_algorithm_notify.c
# * sea exe ${EXE_OPTS} /mount/be.michelfra.disable_cc/congestion_algorithm_notify.c /opt/model/checks/specs_check__congestion_algorithm_notify.c


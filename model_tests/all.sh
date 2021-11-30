#! /bin/sh -e

POSITIVE=0
NEGATIVE=0

while [[ "$#" -gt 0 ]]
do
	case "${1}" in
		-p|--positive)
			POSITIVE=1
		shift
		;;
		-n|--negative)
			NEGATIVE=1
		shift
		;;
	esac
done

CONTAINER_NAME="seahorn_counter_examples"
DOCKERFILE=$(mktemp --tmpdir="/tmp")

cat <<EOF >> ${DOCKERFILE}
FROM seahorn/seahorn-llvm10:nightly

RUN echo horn | sudo -S apt-get update
RUN echo horn | sudo -S DEBIAN_FRONTEND=noninteractive su -p - -c "apt-get install -y --no-install-recommends --fix-missing libarchive-dev libssl-dev expect"

WORKDIR /opt
COPY ./pquic/picoquic pquic/picoquic
RUN echo horn | sudo -S mv pquic/picoquic/frames.c pquic/picoquic/frames.c.old
RUN echo horn | sudo -S mv pquic/picoquic/quicctx.c pquic/picoquic/quicctx.c.old
RUN echo horn | sudo -S mv pquic/picoquic/memory.c pquic/picoquic/memory.c.old
RUN echo horn | sudo -S mv pquic/picoquic/tls_api.c pquic/picoquic/tls_api.c.old

COPY ./checks model/checks
COPY ./verifier model/verifier

WORKDIR /tmp
COPY model_tests/run_expect.sh  model_tests/test.sh ./
ENTRYPOINT ["./test.sh"]
CMD [""]
EOF

echo "Building test container"
docker build -t "${CONTAINER_NAME}" -f "${DOCKERFILE}" .. > /dev/null 2>&1
rm "${DOCKERFILE}"

if [[ $((${POSITIVE} && !${NEGATIVE} || !${POSITIVE} && !${NEGATIVE})) -eq 1 ]] 
then
	# Launch false positive tests
	docker run --rm -v $(pwd)/false_positive:/mount ${CONTAINER_NAME} 1
fi

if [[ $((!${POSITIVE} && ${NEGATIVE} || !${POSITIVE} && !${NEGATIVE})) -eq 1 ]] 
then
	# Launch false negative tests
	docker run --rm -v $(pwd)/false_negative:/mount ${CONTAINER_NAME} 0
fi

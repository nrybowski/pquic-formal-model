#! /bin/sh -e

CONTAINER_NAME="seahorn_counter_examples"
DOCKERFILE=$(mktemp --tmpdir="/tmp")

cat <<EOF >> ${DOCKERFILE}
FROM seahorn/seahorn-llvm10:nightly

RUN echo horn | sudo -S apt-get update
RUN echo horn | sudo -S DEBIAN_FRONTEND=noninteractive su -p - -c "apt-get install -y --no-install-recommends --fix-missing libarchive-dev libssl-dev expect"

WORKDIR /opt
COPY ./pquic/picoquic pquic/picoquic
#RUN echo horn | sudo -S mv pquic/picoquic/frames.c pquic/picoquic/frames.c.old
#RUN echo horn | sudo -S mv pquic/picoquic/quicctx.c pquic/picoquic/quicctx.c.old

COPY ./checks model/checks
COPY ./verifier model/verifier

WORKDIR /tmp
COPY model_tests/run_expect.sh ./
CMD /mount/test.sh
EOF

docker build -t "${CONTAINER_NAME}" -f "${DOCKERFILE}" ..
rm "${DOCKERFILE}"

echo -e "\n\nTesting for simple false positives"
echo "================================"
docker run --rm -v $(pwd)/false_positive:/mount ${CONTAINER_NAME}

# Launch false negative tests
echo -e "\n\nTesting for simple false negatives"
echo "================================"
#docker run --rm -v $(pwd)/false_negative:/mount ${CONTAINER_NAME}

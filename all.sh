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
COPY ./counter_examples /mount

WORKDIR /tmp
COPY test.sh run_expect.sh ./
CMD ./test.sh
EOF

docker build -t "${CONTAINER_NAME}" -f "${DOCKERFILE}" .
rm "${DOCKERFILE}"

# Launch all tests
docker run --rm ${CONTAINER_NAME}

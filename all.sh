#! /bin/sh -e

CONTAINER_NAME="seahorn_counter_examples"
DOCKERFILE=$(mktemp --tmpdir="/tmp")

cat <<EOF >> ${DOCKERFILE}
FROM seahorn/seahorn-llvm10:nightly

RUN DEBIAN_FRONTEND=NONINTERACTIVE echo horn | sudo -S apt-get update
RUN DEBIAN_FRONTEND=NONINTERACTIVE echo horn | sudo -S apt-get install -y --fix-missing libarchive-dev libssl-dev

WORKDIR /opt
COPY ./pquic/picoquic pquic/picoquic
RUN echo horn | sudo -S mv pquic/picoquic/frames.c pquic/picoquic/frames.c.old
RUN echo horn | sudo -S mv pquic/picoquic/quicctx.c pquic/picoquic/quicctx.c.old

COPY ./checks model/checks
COPY ./verifier model/verifier
COPY ./counter_examples /mount

COPY test.sh script.sh

CMD ./script.sh
EOF

docker build -t "${CONTAINER_NAME}" -f "${DOCKERFILE}" .
rm "${DOCKERFILE}"

# Launch all tests
docker run --rm ${CONTAINER_NAME}

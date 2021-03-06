FROM seahorn/seahorn-llvm10:nightly

WORKDIR /opt
COPY check.sh .

WORKDIR /host

ENTRYPOINT ["/opt/check.sh"]

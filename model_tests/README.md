# Model tests

The goal of this folder is to provide some automated tests to search for simple false positive and false negative outputs when using our model with seahorn.

> Note:
>
> We define `negative` as `unsat` and `positive` as `sat` answers from SeaHorn.
>
> By extension `false negative` is defined as receiving `unsat` rather than `sat` and `false positive` as receiving `sat` rather than `unsat`.

## Content

- `all.sh`: The main script used to run our automated testing procedure. It generates a docker container which is able to run all the test cases.
```console
./all.sh # Run all the test cases
./all.sh -n # Run all the false negative tests
./all.sh -p # Run all the false positive tests
```
- `run_expect.sh`: A `expect` script used to capture the output of the execution of SeaHorn CEX.
- `test.sh`: The bash script implementing our testing procedure.
- `false_negative`: Folder containing, for each protoop known to be supported by our model, some pluglets violating their specification. It is expected to obtain `sat` for each of them.
- `false_positive`: Folder containing, for each protoop known to be supported by our model, some pluglets **not** violating their specification. It is expected to obtain `unsat` for each of them.

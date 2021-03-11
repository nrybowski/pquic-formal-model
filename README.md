# PQUIC Formal model for formal verification of specific properties

The goal of this repository is to provide the necessary code to allow formal verification of specific properties on PQUIC pluglets.

The main idea is to, in some manner, annotate the pluglet's code to run properties verification with a formal model checker like SeaHorn or ESBMC.

The main tool used here is SeaHorn. As SeaHorn is only able to verify safety property, all properties specified in this repository are safety ones.

3 main problems arise when we consider code annotation :

- How to annotate ?
- Where to annotate ?
- With which annotations ?

Let's begin with the last consideration. To answer this question we first have to define the property we want to verify to derive the annotations required.

The first property we check is the __limitation of the side effects on the context given to the pluglets__. Indeed, each protoop is expected to have a well defined behavior and thus each pluglet is expected to only modify precise variables from the context.
So we want to verify that only the variables authorized by the protoop definition are modified by the pluglets.
It requires to somehow clone the entire context before the pluglet call and then verify that the context is left untouched except for some authorized fields.
This is a first answer to the "with which annotations" questions : we need helpers to clone a context and to assert that two context are the same except for some variables.
As the internal PQUIC structures are quite complex and in order to provide annotation able to adapt to future changes in PQUIC, it has been decided to generate those helpers automatically.
That is the role of the `gen.py` script.
It will first parse and generate an AST from the `picoquic_interal.h` header file containing the `picoquic_cnx_t` structure given as argument to all pluglets.
This AST will be parsed to provide an intermediate hashmap representation which is easier to handle for the next steps.
This intermediate AST will contain all the data on the fields of `picoquic_cnx_t` as well as of any structure that might be needed for a full context comparison (`picoquic_packet_context_t`, `picoquic_path_t`, ...).

From this intermediate representation we will generate 3 kind of helpers we will call 'constraints' in the rest of this document :
- the initialization of a given structure: it is mainly used to help SearHorn to make deduction on memory usage and variables "intempestive" updates.
- the cloning of a given structure : it tells to SeaHorn how to capture the whole state before a pluglet call and it is used later to compare the context after the pluglet call.
- the comparison of two structures : it tells to SeaHorn which values have to remain unchanged and which ones are authorized to change.

Those constraints are first expressed under the form of a new AST which is then used to automatically generate C code usable by SeaHorn

> This method is not limited to SeaHorn. In fact, the provided code should be easily adaptable to ESBMC notations since their concepts are quite the same. 

The second question which was "where to annotate" also depends of the property we want to check. For the current one, we declare a dummy main function which will tells to SeaHorn how to simulate a context initialization, how to clone all the required data before the plugin call and how to check that the property is respected.
This approach is far from being perfect. Indeed, we may think to cases where the context is changed between two helpers calls into the pluglet and then restored before its return. A more serious scenario might be a context change before an embedded pluglet call which may entirely change the pluglet behavior. So a next step should be the annotation of the inside of the pluglet code to check the context after each code line.
Obviously, the code annotation should also be automated.
While for the black-box case it is quite easy, it could be more difficult in the case of the pluglet's internals annotations. It might be solved using an AST representation of the pluglet code to add annotation and generate a new pluglet version.



```console
header file => AST => intermediate AST => annotation's AST => C code + header file
```



```console


.
├── example
│   ├── is_ack_needed_annotated.c
│   └── update_ack_delay_annotated.c
├── gen.py
├── README.md
└── verifier
    ├── verifier.c
    └── verifier.h
```

```console
# init submodules
ln -s ../../verifer pquic/picoquic
docker run -it $(pwd):/host seahorn/seahorn-llvm10:nightly
# inside container
cd /host
sea bpf -g --bmc=opsem --inline --crab --track=mem --dsa=sea-cs -m64 -DDISABLE_PROTOOP_PRINTF -DDISABLE_QLOG -Ipquic/picoquic pquic/picoquic/getset.c verifier/verifier.c pquic/plugins/ack_delay/update_ack_delay.c checks/specs_check__update_ack_delay.c 

sea exe -g -m64 -Ipicoquic -DDISABLE_PROTOOP_PRINTF picoquic/getset.c picoquic/verifier/verifier.c picoquic/verifier/verifier.c <plugin.c> cex.ll -o cex
gdb ./cex
# set disable-randomization off
```

`--bmc=mono --inline` = https://gitter.im/seahorn/seahorn?at=5c19166dc35a3002474430d9 => solved bitfield issue
`--track=mem` =  model both scalars, pointers, and memory contents
`--dsa=sea-cs` = context sensitive memory check => solved infinite seahorn run


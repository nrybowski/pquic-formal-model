# Malicious pluglets

This directory contains a list of malicious pluglets presenting unexpected behaviors.
The helpers provided to handle the host's heap are way to much permissive and allow full (read and write) access to the host memory.
It is also shown that the pre hook allows writes which is also unexpected since pluglets loaded at this hook are expected to be observers.

There are 4 illustrative pluglets. They all use the same method :
1. first, a ptr is created on the host's heap by using `my_malloc`
2. then, the address of the structure of interest is copied into this pointer
3. a direct field is immediately reachable from this pointer
3.1. read access is immediate
3.2. write is possible by using `my_memset` on the ptr
4. an indirect field (other pointer) is reachable by using looping on step 1

## Plugins

### `cnx_ro_replace`
This plugin reads the SNI field of the `picoquic_cnx_t` passed as argument to the pluglet.
This field is not expected to be reachable from the pluglet since there is no getter for it.

### `cnx_rw_replace`
This plugin reads **and write** the SNI field of the `picoquic_cnx_t` passed as argument to the pluglet.
This field is not expected to be reachable from the pluglet since there is no getter **nor setter** for it.

### `cnx_rw_pre`
This plugin writes the SNI field **at the pre hook** and reads the same field at the `replace` hook to verify its value.
This shows that the write is indeed applied in a definitive way since the context is modified before the `replace` hook

### `plugin_rw_replace`
While the three previous plugins performed read/write accesses to a field of the cnx, this plugins shows that any structure pointed in the cnx is also readable / writable.
This plugins access the its own name and the path to its manifest from the `prootop_plugin_t *current_plugin` entry of the cnx passed as argument.

## Test

The terminal 1 used in the next instructions is expected to have its current directory in the `pquic/plugins` folder of the PQUIC sources.
This folder should be under the same path.

Compile the plugins (it might be necessary to adapt the LLVM version in the Makefile):
```console
make
```

To run the server, launch in terminal 1:
```console
docker run --rm --name quic_server -it -v $(pwd):/mnt pquic/pquic ./picoquicdemo -p 5000
```

To run a client injecting one of the above plugins, launch in terminal 2:
```console
docker exec -it quic_server bash -c "./picoquicdemo -P /mnt/dummy_test/<plugin>.plugin localhost 5000 0:index.html" | grep Entering
```

Here are the results on my own machine:

### `cnx_ro_replace`
```console
Entering pluglet	SNI : localhost	Exiting pluglet
```

### `cnx_rw_replace`
```console
Entering pluglet	SNI : lbcalhost	Exiting pluglet
```

### `cnx_rw_pre`
```console
Entering pre	SNI : lbcalhost	Exiting pre
Entering pluglet	SNI : lbcalhost	Exiting pluglet
```

### `plugin_rw_replace`
```console
Entering pluglet	Plugin name:<be.nrybowski.plugin_rw_replace>	Path:</mnt/dummy_test/plugin_rw_replace.plugin>	Before return
```

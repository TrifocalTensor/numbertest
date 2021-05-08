# numbertest

Number test.

1. Install needed tools:

```
$ sudo apt install build-essential make cmake mingw-w64
```

2. Build project (e.g. if you have 4 cores):

```
$ mkdir -p build
$ cd build
$ cmake ..
$ make -j4
```

3. Run unit tests:

```
$ ctest --verbose -j4
```

4. Built executables:

```
build/linux/number_main
build/windows/number_main_win.exe
```

Tested in Ubuntu 20.04.2 @ x86_64.

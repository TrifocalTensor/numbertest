# numbertest

This project converts numbers from words to digits inside a paragraph.

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

## Details

This project must be built on Linux and it generates executables for Linux, and also for Windows via cross-compilation with Mingw-w64.

* `number.h|.cc`: Main class that splis the input into tokens, processes them, and assembles the output.
* `number_test.cc`: Unit tests for the number class. All tests are passed.
* `number_main.cc`: Command-line tool that processes a text paragraph. 
* `CMakeLists.txt`: Main build script.
* `linux|windows`: Build scripts for Linux and Windows.

The source code follows the Google C++ Style Guide. The code contains to-do comments in places where improvements could be made. 


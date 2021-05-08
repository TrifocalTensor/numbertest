# verbiotest
Verbio test

1. Install needed tools:

    $ sudo apt install build-essential make cmake mingw-w64

2. Build project (if you have 4 cores):

    $ cd build
    $ cmake ..
    $ make -j4

3. Run unit tests:

    $ CTEST_OUTPUT_ON_FAILURE=1 ctest -j4

4. Built executables:

    build/linux/number_main
    build/windows/number_main_win


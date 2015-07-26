# This is a C example project with unit tests
[check]: http://check.sourceforge.net/

This demonstrates using **[Check][check]** along with one of two build systems:
**autotools** and **CMake**.

## Autotools:

You need the following programs installed on your system:

* Autoconf 2.59
* Automake 1.9.6
* Libtool 1.5.22
* Check 0.9.9

Somewhat earlier versions of these programs might work.

Then, do as follows:
```
autoreconf --install
 mkdir build
 cd build
 ../configure
 make
 make check
```
Don't do `make install` unless you want to install the example.

*path.c* and *path.h* are built as a library.
*src/main.c:main()* is a client of **libpath.la**, just as *tests/test_path.c:main()* is a client of **libpath.la**

To use the autotools example in another project, start with the following
files:
```
example
   |--- configure.ac
   |--- Makefile.am
   |--- src
   |   	|--- Makefile.am
   |--- tests
   |   	|--- Makefile.am
   |--- Makefile.am
```
Please send bug reports to Chen Ye <ycchina@gmail.com>.


## CMake:

You need the following programs installed on your system:

* CMake 2.8
* Check 0.9.9
* (pkg-config 0.26 is optional)

Somewhat earlier versions of these programs might work.

**NOTE:** If **pkg-config** is not installed on the system, and MSVC is being used,
the install location of [Check][check] must be inserted manually into the
*tests/CMakeLists.txt* file, by setting the variable **CHECK_INSTALL_DIR**
to the install location. Look at the *tests/CMakeLists.txt* file for
a commented out example.

Then, do as follows for a Unix-compatible shell:
```
 mkdir build
 cd build
 cmake ..
 make
 make test
```
or the following for CodeBlocks
```
 mkdir build
 cd build
 cmake -G "CodeBlocks - Unix Makefiles" ..
 nmake
 nmake test
```
or the following for MSVC:
```
 mkdir build
 cd build
 cmake -G "NMake Makefiles" ..
 nmake
 nmake test
```
For other IDEs see http://www.cmake.org/

Don't do `make install` or `nmake install` unless you want to install the example.

*path.c* and *path.h* are built as a library.
*src/main.c:main()* is a client of **libpath.la**, just as *tests/test_path.c:main()* is a client of **libpath.la**

To use the CMake example in another project, start with the following files:
```
example
   |--- CMakeFiles.txt
   |--- cmake
   |    |--- config.h.in
   |    |--- FindCheck.cmake
   |--- src
   |    |--- CMakeFiles.txt
   |--- tests
        |--- CMakeFiles.txt
```
Please send bug reports to Chen Ye <ycchina@gmail.com>.

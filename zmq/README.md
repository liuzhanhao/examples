# ZeroMQ Example

ZeroMQ Example

## Prerequisite
- CMake (Version >= 3.0.2)
- A working C++ compiler (clang/gcc/icc/MSVC)
- ZeroMQ

## Build

Go to the project root and do an out-of-source build using CMake:
```sh
mkdir debug
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make help               # List all build target
make $ApplicationName   # Build application
make -j                 # Build all applications with all threads

GLOG_logtostderr=1 ./UnitTest  # Show the log information
GLOG_logtostderr=1 ./UnitTest --gtest_filter=TestEngine.*  # Show the log information for particular test
```

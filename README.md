# arrow-cmake-fetchcontent

Figuring out how to use CMake [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html) with [Apache Arrow](https://arrow.apache.org).
What I'd like to be able to do is make Arrow C++ examples where the user only has to:

1. `git clone $REPO`
2. `mkdir build`
3. `cd build`
4. `cmake ..`
5. `cmake --build .`
6. `Run $EXECUTABLE` where `$EXECUTABLE` is linked against one or more Arrow shared libraries.

Subscribe to this repository to watch me flail around at this!

## Status

I appear to be stuck on some Thrift and/or Protobuf issue:

```sh
> cmake ..
#...snip...
CMake Warning at build/_deps/arrow-src/cpp/cmake_modules/FindThriftAlt.cmake:56 (find_package):
  By not providing "FindThrift.cmake" in CMAKE_MODULE_PATH this project has
  asked CMake to find a package configuration file provided by "Thrift", but
  CMake did not find one.

  Could not find a package configuration file provided by "Thrift" (requested
  version 0.11.0) with any of the following names:

    ThriftConfig.cmake
    thrift-config.cmake

  Add the installation prefix of "Thrift" to CMAKE_PREFIX_PATH or set
  "Thrift_DIR" to a directory containing one of the above files.  If "Thrift"
  provides a separate development package or SDK, be sure it has been
  installed.
Call Stack (most recent call first):
  build/_deps/arrow-src/cpp/cmake_modules/ThirdpartyToolchain.cmake:280 (find_package)
  build/_deps/arrow-src/cpp/cmake_modules/ThirdpartyToolchain.cmake:1628 (resolve_dependency)
  build/_deps/arrow-src/cpp/CMakeLists.txt:504 (include)


-- Could NOT find Protobuf (missing: Protobuf_LIBRARIES) (found suitable version "3.21.12", minimum required is "2.6.1")
CMake Error at build/_deps/arrow-src/cpp/cmake_modules/ThirdpartyToolchain.cmake:1786 (message):
  libprotoc was set to Protobuf_PROTOC_LIBRARY-NOTFOUND
Call Stack (most recent call first):
  build/_deps/arrow-src/cpp/CMakeLists.txt:504 (include)
```

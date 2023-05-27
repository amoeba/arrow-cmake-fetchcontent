# arrow-cmake-fetchcontent

A minimal and fairly self-contained example of using CMake to use Arrow C++ in a
separate C++ project. This uses FetchContent instead of ExternalProject to
include Arrow C++.

## Pre-requisites

- git
- cmake
- A C++ compiler toolchain

## Building

1. `git clone https://github.com/amoeba/arrow-cmake-fetchcontent`
2. `cd arrow-cmake-fetchcontent`
3. `mkdir build`
4. `cd build`
5. `cmake ..` 
   This fetches Arrow from GitHub so it takes a bit and produces no output
6. `cmake --build .`
7. `./example`

## Next steps

- Make it easier to check out different versions of Arrow
- Document how to customize the Arrow build

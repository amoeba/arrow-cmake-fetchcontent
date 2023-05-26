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

I'm pretty close, I just have some sort of linking issue which doesn't make
sense to me yet:

```
$ ./main
dyld[34433]: symbol not found in flat namespace '__ZN5arrow3ipc17RecordBatchWriter16WriteRecordBatchERKNS_11RecordBatchERKNSt3__110shared_ptrIKNS_16KeyValueMetadataEEE'
fish: Job 1, './main' terminated by signal SIGABRT (Abort)
```

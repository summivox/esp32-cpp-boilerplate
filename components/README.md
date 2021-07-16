# Libraries / Dependencies

## How to add an external library

Usually for simple libraries with minimum-to-none dependencies, you may add the library as a git submodule, then use a simple `CMakeLists.txt` to plug it into ESP-IDF's build system. Please refer to [`fmtlib`](./fmtlib/CMakeLists.txt) as an example. Alternatively you can simply include the sources and headers and create a similar `CMakeLists.txt` for them.

Usually it's a good idea to retain the library name in the include path (e.g. `#include "fmt/core.h"`). This avoids conflict of header file names from different libraries.

## Reference

https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html#create-a-new-component


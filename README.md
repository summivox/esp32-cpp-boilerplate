# summivox's Opinionated ESP32 C++ Boilerplate

This repo provides a clean yet convenient starting point for a ESP32 firmware project using C++20 with [ESP-IDF][].

A set of minimal examples are included to guide code organization, both for user code and for dependencies,
as well as showcasing some C++ tricks that simplify firmware writing. These can be removed easily to make room for your code.


## Usage

- Start a new repo based on this template repo, or just fork it.
- Clone your new repo using `git clone --recursive` (**make sure you use the `--recursive` flag!**)
- Download and setup [ESP-IDF][]. Recommended to use the [official VSCode plugin][ESP-IDF-vscode].
- Use [ESP-IDF][] to build and flash this project to an ESP32 development board.
- Read the examples in [`main/example/hello.cpp`](./main/example/hello.cpp) called from [`main/app_main.cpp`](./main/app_main.cpp).
- Check out [`sdkconfig.defaults`](./sdkconfig.defaults).

When you are ready to write your own code:

- Rename the project in the root [`CMakeLists.txt`](./CMakeLists.txt) .
- Remove the example module. Places you need to touch (note that the reverse is how you add new source/header pairs):
    - [`main/example`](./main/example)
    - main component's [`CMakeLists.txt`](./main/CMakeLists.txt) .
    - reference in [`main/app_main.cpp`](./main/app_main.cpp) .
- Remove unused components (you may need to properly remove git submodules using `git submodule deinit` and `git rm`).


## Features

- C++20 support (up to the GCC version supported by ESP-IDF).
- Examples for external libraries / dependencies (see [components](./components)).
- Convenient utilities to reduce boilerplate (e.g. [FreeRTOS task wrapper](./main/common/task.hpp)). 


## Contribution

This repo adopts the [Google C++ Style Guide][gcpp].
Formatting should be enforced by [clang-format][]; its config file [`.clang-format`](.clang-format) is included.

Issues, pull requests, forking are all welcome.


## License

Everything in this repo is public domain / CC0, unless specified in a nested LICENSE file (e.g. in [`components`](./components)).
See [LICENSE](LICENSE).


[ESP-IDF]: https://github.com/espressif/esp-idf
[ESP-IDF-vscode]: https://marketplace.visualstudio.com/items?itemName=espressif.esp-idf-extension
[gcpp]: https://google.github.io/styleguide/cppguide.html
[clang-format]: https://clang.llvm.org/docs/ClangFormat.html

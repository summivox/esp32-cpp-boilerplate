#include <cstdio>

#include "example/hello.hpp"  // TODO: replace this with your own code

namespace {
constexpr char TAG[] = "main";
}

extern "C" void app_main(void) {
  // This is the entry point of user code.
  // It is okay to return from this function.

  // TODO: replace this with your own code

  printf("\n\n\nHello World!\n\n\n");
  example::StartExampleTask();
}

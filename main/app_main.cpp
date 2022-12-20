#include <cstdio>
#include <string>

#define USE_STR_CAT 0
#define USE_STR_FORMAT 1
#define USE_FMT 0

#if USE_STR_CAT
#include "absl/strings/str_cat.h"
#endif  // USE_STR_CAT
#if USE_STR_FORMAT
#include "absl/strings/str_format.h"
#endif  // USE_STR_FORMAT
#if USE_FMT
#include "fmt/core.h"
#endif  // USE_FMT



namespace {
constexpr char TAG[] = "main";
}

extern "C" void app_main(void) {
  std::string a =
#if USE_STR_CAT
      absl::StrCat("abc", 123, "def");
#else
      "";
#endif

  std::string aa =
#if USE_STR_FORMAT
      absl::StrFormat("abc%09ddef", 123);
#else
      "";
#endif

  std::string b =
#if USE_FMT
      fmt::format("{}{}{}", "abc", 123, "def");
#else
      "";
#endif

  printf("%s\n%s\n%s\n", a.c_str(), aa.c_str(), b.c_str());
}

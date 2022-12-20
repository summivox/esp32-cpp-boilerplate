set(root "abseil-cpp")
set(srcs
"${root}/absl/strings/ascii.cc"
"${root}/absl/strings/internal/str_format/arg.cc"
"${root}/absl/strings/internal/str_format/bind.cc"
"${root}/absl/strings/internal/str_format/extension.cc"
"${root}/absl/strings/internal/str_format/float_conversion.cc"
"${root}/absl/strings/internal/str_format/output.cc"
"${root}/absl/strings/internal/str_format/parser.cc"
"${root}/absl/strings/numbers.cc"
"${root}/absl/strings/str_cat.cc"
"${root}/absl/strings/string_view.cc"
"${root}/absl/time/civil_time.cc"
"${root}/absl/time/clock.cc"
"${root}/absl/time/duration.cc"
"${root}/absl/time/format.cc"
"${root}/absl/time/internal/cctz/src/civil_time_detail.cc"
"${root}/absl/time/internal/cctz/src/time_zone_fixed.cc"
"${root}/absl/time/internal/cctz/src/time_zone_format.cc"
"${root}/absl/time/internal/cctz/src/time_zone_if.cc"
"${root}/absl/time/internal/cctz/src/time_zone_impl.cc"
"${root}/absl/time/internal/cctz/src/time_zone_info.cc"
"${root}/absl/time/internal/cctz/src/time_zone_libc.cc"
"${root}/absl/time/internal/cctz/src/time_zone_lookup.cc"
"${root}/absl/time/internal/cctz/src/time_zone_posix.cc"
"${root}/absl/time/internal/cctz/src/zone_info_source.cc"
"${root}/absl/time/time.cc"
)
set(includedirs
"${root}"
)
set(requires
)
set(priv_requires
)
idf_component_register(
    INCLUDE_DIRS ${includedirs}
    SRCS ${srcs}
    REQUIRES ${requires}
    PRIV_REQUIRES ${priv_requires}
)

list(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_LIST_DIR}/abseil-cpp/CMake
    ${CMAKE_CURRENT_LIST_DIR}/abseil-cpp/absl/copts
)

target_compile_options(${COMPONENT_LIB} PRIVATE -std=gnu++2a)

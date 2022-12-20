set(srcs
"app_main.cpp"

# TODO: add new source (.c/.cc/.cpp) files here (best if kept in lexical order)
)

set(requires
# System
spi_flash

# Project
absl
fmtlib
scope_guard
)

idf_component_register(
    SRCS ${srcs}
    INCLUDE_DIRS "."
    REQUIRES ${requires}
)

# compiler flags for the `main` component can be specified here
target_compile_options(${COMPONENT_LIB} PRIVATE -std=gnu++2a)

# compiler flags to be applied to all components can be specified here
target_compile_options(${COMPONENT_LIB} PUBLIC -DFMT_USE_FLOAT=0 -DFMT_REDUCE_INT_INSTANTIATIONS=1)

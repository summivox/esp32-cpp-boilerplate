set(srcs
"app_main.cpp"

"example/hello.cpp"
# TODO: add new source (.c/.cc/.cpp) files here (best if kept in lexical order)
)

idf_component_register(
    SRCS ${srcs}
    INCLUDE_DIRS "."
)

# compiler flags for the `main` component can be specified here
target_compile_options(${COMPONENT_LIB} PRIVATE -std=gnu++2a)

# compiler flags to be applied to all components can be specified here
# target_compile_options(${COMPONENT_LIB} PUBLIC)

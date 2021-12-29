cmake_minimum_required(VERSION 3.5)

# enable explicit components requirements specification
# comment out if you want to implicitly include all esp-idf components
set(COMPONENTS esptool_py main)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(your-project-name-here)  # TODO: change to your project name

cmake_minimum_required(VERSION 3.10)
project("cppgames")
set_embt_target(VCL DynamicRuntime)

file(GLOB SOURCES
    "*.h"
    "*.cpp"
)

add_executable("cppgames"   ${SOURCES})


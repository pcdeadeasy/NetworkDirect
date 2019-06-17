cmake_minimum_required(VERSION 3.0.0)

add_subdirectory(libraries)
set(PLATFORM_TOOLSET OFF CACHE STRING "v141" FORCE)
add_subdirectory(examples)

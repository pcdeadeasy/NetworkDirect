cmake_minimum_required(VERSION 3.0.0)

include(ExternalProject)

ExternalProject_Add(ndutillib
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/libraries
  CMAKE_GENERATOR "Visual Studio 15 2017 Win64"                  
  CMAKE_GENERATOR_TOOLSET "WindowsUserModeDriver10.0"
  CMAKE_ARGS -DCMAKE_C_COMPILER_WORKS=1 -DCMAKE_CXX_COMPILER_WORKS=1
  STEP_TARGETS   build
)

add_subdirectory(examples)

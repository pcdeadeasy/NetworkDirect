cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# Include modules in the CMake directory.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake")

# Define custom configuration types for Visual Studio
if(CMAKE_CONFIGURATION_TYPES)
  # Copy important configuration info from Release config to new Documentation config  
  list(APPEND CMAKE_CONFIGURATION_TYPES Documentation)
  set(CMAKE_CXX_FLAGS_DOCUMENTATION ${CMAKE_CXX_FLAGS_RELEASE})
  set(CMAKE_C_FLAGS_DOCUMENTATION ${CMAKE_C_FLAGS_RELEASE})
  set(CMAKE_EXE_LINKER_FLAGS_DOCUMENTATION ${CMAKE_EXE_LINKER_FLAGS_RELEASE})
  set(CMAKE_EXE_LINKER_FLAGS_DOCUMENTATION ${CMAKE_EXE_LINKER_FLAGS_RELEASE})
  set(CMAKE_SHARED_LINKER_FLAGS_DOCUMENTATION ${CMAKE_SHARED_LINKER_FLAGS_RELEASE})
  set(CMAKE_MODULE_LINKER_FLAGS_DOCUMENTATION ${CMAKE_MODULE_LINKER_FLAGS_RELEASE})
endif()

# Include modules in the CMake directory.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")

# Turn on ability to create folders to organize projects
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Set C++ version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
  add_definitions(-DUNICODE)
  add_compile_options(/MP)
endif()

# include(PrecompiledHeader)

enable_testing()

add_subdirectory(src)
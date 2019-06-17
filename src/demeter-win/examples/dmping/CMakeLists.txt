cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

set(PROJ_NAME dmping)
project(${PROJ_NAME})

# Check platforms
if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif(CMAKE_HOST_APPLE)
    set(MACOS 1)
elseif(CMAKE_HOST_UNIX)
    set(LINUX 1)
endif()

# Set RPATH
if(WINDOWS)
  set(CMAKE_INSTALL_PREFIX "./${PROJ_NAME}")
  set(WINSDK_VER "10.0.17134.0")
else()
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
    message( STATUS "CMAKE_INSTALL_RPATH: " "${CMAKE_INSTALL_PREFIX}/lib" )
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()

message( STATUS "CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE: " "${CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE}" )

if(NOT CMAKE_BUILD_TYPE)
  set (PROJECTNAME_ARCHITECTURE "x64")
else()
  if (${CMAKE_SIZEOF_VOID_P} EQUAL "8")
      set (PROJECTNAME_ARCHITECTURE "x64")
  else ()
      set (PROJECTNAME_ARCHITECTURE "x86")
  endif ()
endif()
message( STATUS "Building for Proc Arch: " "${PROJECTNAME_ARCHITECTURE}" )

message( STATUS "Current Source Dir: " "${CMAKE_CURRENT_SOURCE_DIR}" )
message( STATUS "Current BINARY Dir: " "${CMAKE_CURRENT_BINARY_DIR}" )

# find path to mc.exe
if (WIN32)
  message( STATUS "CMAKE_INSTALL_RPATH: " "${CMAKE_INSTALL_PREFIX}/lib" )
  message( STATUS "CMAKE_GENERATOR: " "${CMAKE_GENERATOR}" )
  
  # cmake has CMAKE_RC_COMPILER, but no message compiler
  if ("${CMAKE_GENERATOR}" MATCHES "^Visual Studio")
    # this path is only present for 2008+, but we currently require PATH to
    # be set up anyway
    get_filename_component(sdk_dir "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Microsoft SDKs\\Windows\\v7.1A;InstallationFolder]" REALPATH)
    get_filename_component(kit10_dir "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows Kits\\Installed Roots;KitsRoot10]" REALPATH)    
    if (${PROJECTNAME_ARCHITECTURE} STREQUAL "x64")
      set(sdk_bindir "${sdk_dir}/bin/x64")
      set(kit10_bindir "${kit10_dir}/bin/${WINSDK_VER}/x64")      
    else ()
      set(sdk_bindir "${sdk_dir}/bin")      
      set(kit10_bindir "${kit10_dir}/bin/${WINSDK_VER}/x86")
    endif ()
  endif ()
  
  message( STATUS "sdk_bindir: " "${sdk_bindir}" )
  message( STATUS "kit10_bindir: " "${kit10_bindir}" )
  
  find_program(CMAKE_MC_COMPILER mc.exe HINTS "${sdk_bindir}" "${kit10_bindir}"
    DOC "path to message compiler")
  if (NOT CMAKE_MC_COMPILER)
    message(FATAL_ERROR "message compiler not found: required to build")
  endif (NOT CMAKE_MC_COMPILER)
  message(STATUS "Found message compiler: ${CMAKE_MC_COMPILER}")
  mark_as_advanced(CMAKE_MC_COMPILER)
endif(WIN32)

################### Variables. ####################
# Change if you want modify path or other values. #
###################################################

# Output Variables
set(OUTPUT_DEBUG Debug/bin)
set(OUTPUT_RELEASE Release/bin)
# Folders files
set(SRC 
  ./dmping.cpp 
  ./csv.cpp
  ./pch.cpp
)

set(INCLUDE
  ./csv.h
  ./pch.h
)

source_group("src" FILES ${SRC})
source_group("include" FILES ${INCLUDE})

set_source_files_properties(${SRC}
    PROPERTIES
    COMPILE_FLAGS "/Ycpch.h /c"
)

# Define Release by default.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message(STATUS "Build type not specified: Use Release by default.")
endif(NOT CMAKE_BUILD_TYPE)

############## Artefacts Output #################
# Defines outputs , depending Debug or Release. #
#################################################

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_DEBUG}")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_DEBUG}")
  set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_DEBUG}")
else()
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_REL}")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_REL}")
  set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_REL}")
endif()

################# Flags ################
# Defines Flags for Windows and Linux. #
########################################

if(MSVC)
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /EHsc")
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /EHsc")
   set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ignore:4099")
   set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ignore:4075")
   set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Yupch.h")
    
   add_definitions(-DUNICODE)
   message( STATUS "CMAKE_BUILD_TYPE: " "${CMAKE_BUILD_TYPE}" )
   if(CMAKE_BUILD_TYPE STREQUAL "Debug")
      add_compile_options(/MTd)
   else()
	    add_compile_options(/MT)
   endif()
   set(CMAKE_GENERATOR_TOOLSET "v141" CACHE STRING "Platform Toolset" FORCE)
   message( STATUS "CMAKE_GENERATOR_TOOLSET: " "${CMAKE_GENERATOR_TOOLSET}" )
endif(MSVC)
if(NOT MSVC)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
   if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
   endif()
endif(NOT MSVC)

# Add /Qspectre and /guard:cf
message(STATUS "MSVC_VERSION: " ${MSVC_VERSION})
if (MSVC AND (MSVC_VERSION GREATER 1900))
    if (${use_control_flow_guard})
        message("Setting CONTROL FLOW GUARD") 
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /guard:cf")
        SET(CMAKE_EXE_LINKER_FLAGS  "/guard:cf /DYNAMICBASE")
    endif()
    if (${use_qspectre})
        message("Setting QSPECTRE")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Qspectre")
    endif()
endif()

#set(CMAKE_GENERATOR "Visual Studio 15 2017 Win64" CACHE INTERNAL "" FORCE)
#set(CMAKE_GENERATOR_TOOLSET "v141" CACHE INTERNAL "" FORCE)
message("generator is set to ${CMAKE_GENERATOR}")

# Add library to build.
add_executable(${PROJ_NAME} ${SRC} ${INCLUDE})
target_link_libraries(${PROJ_NAME} Logger ndutil winshim)
#set_target_properties(${PROJ_NAME} PROPERTIES PLATFORM_TOOLSET "v141")

#target_link_libraries(${PROJ_NAME} ndutil)
set_property(TARGET ${PROJ_NAME} PROPERTY FOLDER "private/libraries")
#install (TARGETS Logger DESTINATION bin)



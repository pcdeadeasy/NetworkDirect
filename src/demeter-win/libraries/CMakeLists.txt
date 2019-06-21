cmake_minimum_required(VERSION 3.0.0)

set(PROJ_NAME rdma-win)

project(${PROJ_NAME})

add_subdirectory(logger)
add_subdirectory(winshim)
add_subdirectory(ndutil)
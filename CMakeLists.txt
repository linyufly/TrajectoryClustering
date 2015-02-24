cmake_minimum_required(VERSION 2.8)

project(TrajectoryClustering)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(VectorTest vector_test.cc)

target_link_libraries(VectorTest ${VTK_LIBRARIES})

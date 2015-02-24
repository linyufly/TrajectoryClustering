cmake_minimum_required(VERSION 2.8)

project(TrajectoryClustering)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(VectorTest vector_test.cc)
target_link_libraries(VectorTest ${VTK_LIBRARIES})
target_link_libraries(VectorTest ${PCL_LIBRARIES})

add_executable(PCLTest pcl_test.cc)
target_link_libraries(PCLTest ${VTK_LIBRARIES})
target_link_libraries(PCLTest ${PCL_LIBRARIES})

add_executable(MathTest math_test.cc
                        math.cc)
target_link_libraries(MathTest ${VTK_LIBRARIES})
target_link_libraries(MathTest ${PCL_LIBRARIES})

add_executable(TrajectorySimilarityTest trajectory_similarity_test.cc
                                        math.cc)
target_link_libraries(TrajectorySimilarityTest ${VTK_LIBRARIES})
target_link_libraries(TrajectorySimilarityTest ${PCL_LIBRARIES})


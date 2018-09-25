cmake_minimum_required(VERSION 3.0.0)
project(RandomWalker VERSION 0.1.0)


include(CTest)
enable_testing()

# PCL
find_package(PCL 1.7.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(RandomWalker src/main.cpp)

target_link_libraries (RandomWalker ${PCL_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

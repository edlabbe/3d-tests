cmake_minimum_required(VERSION 3.0.0)
project(3d-tests VERSION 0.1.0)

include(CTest)
enable_testing()

# set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# add include folder to the list include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

add_definitions(-std=c++11)



# PCL
find_package(PCL 1.7.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# TViewer
#add_subdirectory(third-party/tviewer)

add_library(random_walker_segmentation
  src/random_walker_segmentation.cpp
)
target_link_libraries(random_walker_segmentation
  ${PCL_LIBRARIES}
)
set_target_properties(random_walker_segmentation
  PROPERTIES COMPILE_DEFINITIONS "PCL_ONLY_CORE_POINT_TYPES"
)

#adds library io
add_library(io src/io.cpp)
target_link_libraries(io ${PCL_LIBRARIES})

add_executable(3d-tests src/main.cpp)

#target_link_libraries (3d-tests ${PCL_LIBRARIES} tviewer io)
target_link_libraries (3d-tests ${PCL_LIBRARIES} io)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

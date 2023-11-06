cmake_minimum_required(VERSION 3.0)

project(PCLTest)

# Find the PCL package
find_package(PCL 1.10 REQUIRED)

# Find the Eigen package
find_package(Eigen3 REQUIRED)

# Include directories
include_directories(${PCL_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIR})

# Add the source file
add_executable(main src/main.cpp src/interactive_icp.cpp src/pcl_test.cpp src/interactive_icp.h
src/csv_functions.cpp src/csv_functions.h)

# Link PCL libraries
target_link_libraries(main ${PCL_LIBRARIES})

cmake_minimum_required(VERSION 3.0)
project(mapping)

# Policies
cmake_policy(SET CMP0057 NEW) # Consider removing if not necessary

# Packages
find_package(ament_cmake REQUIRED)
find_package(PCL 1.10 REQUIRED ) # Specify needed components
# find_package(PCL REQUIRED COMPONENTS common io visualization filter)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(Eigen3 REQUIRED NO_MODULE) # NO_MODULE to use Eigen3::Eigen
find_package(rclcpp REQUIRED)

# Global include directories
include_directories(
  include
  ${PCL_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
)

link_directories(
  ${PCL_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
)

add_definitions(${PCL_DEFINITIONS})

# ROS_comms executable
add_executable(ROS_comms 
  src/ROS_comms.cpp 
)
ament_target_dependencies(ROS_comms 
  rclcpp 
  sensor_msgs 
  PCL 
)
target_link_libraries(ROS_comms 
  ${PCL_LIBRARIES} 
  ${rclcpp_LIBRARIES}
)

# Install targets
install(TARGETS 
  ROS_comms
  DESTINATION lib/${PROJECT_NAME}
)


# Package the project as a ROS2 package
ament_package()

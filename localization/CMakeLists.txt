cmake_minimum_required(VERSION 3.0)
project(localization)

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

add_executable(odom_subscriber src/odom_subscriber.cpp)

ament_target_dependencies(odom_subscriber rclcpp nav_msgs)

install(TARGETS
odom_subscriber
  DESTINATION lib/${PROJECT_NAME}/
)


ament_package()

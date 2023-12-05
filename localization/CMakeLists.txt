cmake_minimum_required(VERSION 3.5)
project(localization)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies

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
  /home/simteamq/Desktop/SEAL/localization/include/localization
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

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

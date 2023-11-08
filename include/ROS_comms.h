#ifndef ROS_COMMS_H
#define ROS_COMMS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include <interactive_icp.h>
#include <pcl/console/time.h>   // TicToc
#include <pcl/point_cloud.h>
#include <vector>
#include <pcl/io/pcd_io.h>


pcl::PointCloud<pcl::PointXYZ>::Ptr convertPointCloud2ToPCL(const sensor_msgs::msg::PointCloud2::SharedPtr msg);
class PointCloudSubscriberNode;

#endif  //ROS_COMMS_H
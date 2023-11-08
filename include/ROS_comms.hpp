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


class PointCloudMapper : public rclcpp::Node {
public:
    PointCloudMapper();
    ~PointCloudMapper();

private:
    void pointCloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg);
    void saveMap();
    void publishMap();
    // ... other member variables and methods ...

    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscription_;
    pcl::PointCloud<pcl::PointXYZ>::Ptr map_;
    // ... other ROS and PCL related member variables ...
};


#endif  //ROS_COMMS_H
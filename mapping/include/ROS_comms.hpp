#ifndef ROS_COMMS_H
#define ROS_COMMS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <pcl/PCLPointCloud2.h> // Include for pcl::PCLPointCloud2
#include <interactive_icp.h>
#include <pcl/console/time.h> // TicToc
#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <vector>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>


class PointCloudMapper : public rclcpp::Node {

    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscription_1;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_2;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr map_publisher_;
    pcl::PointCloud<pcl::PointXYZ>::Ptr previous_cloud_;
    pcl::PointCloud<pcl::PointXYZ>::Ptr map_;
    Eigen::Matrix4f track_matrix = Eigen::Matrix4f::Identity();

public:
    PointCloudMapper();
    ~PointCloudMapper();

private:
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
    void pointCloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg);
    void saveMap();
    void publishMap();
    void floorFilter(bool statement, pcl::PointCloud<pcl::PointXYZ>::Ptr current_cloud);
    // ... other member variables and methods ...

    // ... other ROS and PCL related member variables ...
};


#endif  //ROS_COMMS_H
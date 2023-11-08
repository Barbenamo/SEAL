#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include <pcl/PCLPointCloud2.h> // Include for pcl::PCLPointCloud2
#include <interactive_icp.h>
#include <pcl/console/time.h>   // TicToc
#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <vector>
#include <pcl/io/pcd_io.h>

pcl::PointCloud<pcl::PointXYZ>::Ptr convertPointCloud2ToPCL(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
    pcl::PCLPointCloud2 pcl_pc2;
    pcl_conversions::toPCL(*msg, pcl_pc2);
    pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(pcl_pc2, *pcl_cloud);
    return pcl_cloud;
}

class PointCloudSubscriberNode : public rclcpp::Node {
public:
  PointCloudSubscriberNode() : Node("point_cloud_subscriber_node") {
        pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_prev(new pcl::PointCloud<pcl::PointXYZ>);
        subscription_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
        "/velodyne_topic", 10,
        [this](const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
          // Callback function to process the received PointCloud2 message
          // You can perform your desired operations on the point cloud data here
          // For example, you can use pcl library or other point cloud processing libraries
          pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cur = convertPointCloud2ToPCL(msg);
            
        });
      }
      
private:
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PointCloudSubscriberNode>());
    rclcpp::shutdown();
    return 0;
}

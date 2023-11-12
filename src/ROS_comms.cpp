#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include <pcl/PCLPointCloud2.h> // Include for pcl::PCLPointCloud2
#include <interactive_icp.h>
#include <pcl/console/time.h> // TicToc
#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <vector>
#include <pcl/io/pcd_io.h>
// #include <pcl/filters/voxel_grid.h>

pcl::PointCloud<pcl::PointXYZ>::Ptr convertPointCloud2ToPCL(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
    pcl::PCLPointCloud2 pcl_pc2;
    pcl_conversions::toPCL(*msg, pcl_pc2);
    pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(pcl_pc2, *pcl_cloud);
    return pcl_cloud;
}

class PointCloudMapper : public rclcpp::Node
{
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscription_;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr map_publisher_;
    pcl::PointCloud<pcl::PointXYZ>::Ptr previous_cloud_;
    pcl::PointCloud<pcl::PointXYZ>::Ptr map_;
    Eigen::Matrix4f track_matrix = Eigen::Matrix4f::Identity();

public:
    PointCloudMapper() : Node("point_cloud_subscriber_node")
    {
        pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_prev(new pcl::PointCloud<pcl::PointXYZ>);
        subscription_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
            "point_cloud_topic", 10, std::bind(&PointCloudMapper::pointCloudCallback, this, std::placeholders::_1));
        map_ = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>());
    }
    ~PointCloudMapper()
    {
        std::cout << "Node killed, map saved" << std::endl;
        saveMap();
    }

private:
    void pointCloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
    {

        pcl::PointCloud<pcl::PointXYZ>::Ptr current_cloud(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::fromROSMsg(*msg, *current_cloud);
        if (previous_cloud_)
        {
            pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
            pcl::transformPointCloud(*current_cloud, *current_cloud, track_matrix);
            icp.setInputSource(current_cloud);
            icp.setInputTarget(previous_cloud_);
            pcl::PointCloud<pcl::PointXYZ>::Ptr aligned_cloud(new pcl::PointCloud<pcl::PointXYZ>());
            icp.align(*aligned_cloud);
            previous_cloud_ = current_cloud;

            // std::cout << "------ here2 ------" << std::endl;
            // Check if ICP converged
            if (icp.hasConverged())
            {
                // Transform the current cloud and add it to the map
                *map_ += *aligned_cloud;
                publishMap();
                track_matrix = track_matrix * icp.getFinalTransformation();
                // std::cout << "------ here3 ------" << std::endl;
                // If you want to downsample the map (recommended to avoid it growing too large), you'd do it here.
                // downsampleMap();

                // Publish the map to a ROS topic
            }
            else
            {
                RCLCPP_ERROR(this->get_logger(), "ICP did not converge.");
            }
        }
        else
        {
            // If there is no previous cloud, initialize map with the current cloud
            *map_ = *current_cloud;
            previous_cloud_ = current_cloud;

            // std::cout << "------ here4 ------" << std::endl;
        }

        // Update the previous_cloud_ for the next frame
    }

    // Optional: Function to downsample the map using a VoxelGrid filter
    // void downsampleMap() {
    //     pcl::VoxelGrid<pcl::PointXYZ> sor;
    //     sor.setInputCloud(map_);
    //     sor.setLeafSize(0.05f, 0.05f, 0.05f); // Set the voxel size
    //     pcl::PointCloud<pcl::PointXYZ>::Ptr tempCloud(new pcl::PointCloud<pcl::PointXYZ>());
    //     sor.filter(*tempCloud);
    //     map_ = tempCloud;
    // }

    // Optional: Function to publish the map
    void publishMap()
    {
        sensor_msgs::msg::PointCloud2 map_msg;
        pcl::toROSMsg(*map_, map_msg);
        map_msg.header.frame_id = "map";
        map_msg.header.stamp = this->get_clock()->now();
        map_publisher_->publish(map_msg);
    }
    void saveMap()
    {
        if (!map_->points.empty())
        {
            std::string filename = "final_map.pcd";
            if (pcl::io::savePCDFile<pcl::PointXYZ>(filename, *map_) == 0)
            {
                RCLCPP_INFO(this->get_logger(), "Saved map to %s", filename.c_str());
            }
            else
            {
                RCLCPP_ERROR(this->get_logger(), "Failed to save map to %s", filename.c_str());
            }
        }
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PointCloudMapper>());
    rclcpp::shutdown();
    return 0;
}

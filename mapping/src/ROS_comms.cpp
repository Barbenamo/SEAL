#include "ROS_comms.hpp"


PointCloudMapper::PointCloudMapper() : Node("point_cloud_subscriber_node")
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_prev(new pcl::PointCloud<pcl::PointXYZ>);
    subscription_1 = this->create_subscription<sensor_msgs::msg::PointCloud2>(
        "point_cloud_topic", 10, std::bind(&PointCloudMapper::pointCloudCallback, this, std::placeholders::_1));   
    subscription_2 = this->create_subscription<nav_msgs::msg::Odometry>(
        "Odom", 10, std::bind(&OdomSubscriber::odom_callback, this, std::placeholders::_1))
    map_ = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>());
    map_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("map_topic", 10);
}
PointCloudMapper::~PointCloudMapper()
{
    std::cout << "Node killed, map saved" << std::endl;
    saveMap();
}

void PointCloudMapper::odom_callback(const nav_msgs::msg::Odometry msg){



}


void PointCloudMapper::pointCloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{

    pcl::PointCloud<pcl::PointXYZ>::Ptr current_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PCLPointCloud2::Ptr current_cloud_2(new pcl::PCLPointCloud2());
    pcl::PCLPointCloud2::Ptr current_cloud_2_filtered(new pcl::PCLPointCloud2());
    pcl::fromROSMsg(*msg, *current_cloud);

    pcl::toPCLPointCloud2(*current_cloud, *current_cloud_2);

    if (previous_cloud_)
    {
        pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
        sor.setInputCloud(current_cloud_2);
        sor.setLeafSize(0.30f, 0.30f, 0.30f); // Set the voxel size
        sor.filter(*current_cloud_2_filtered);
        pcl::fromPCLPointCloud2(*current_cloud_2_filtered, *current_cloud);

        // floor filter option (not working yet...)
        floorFilter(false, current_cloud);

        pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
        pcl::transformPointCloud(*current_cloud, *current_cloud, track_matrix);
        icp.setInputSource(current_cloud);
        icp.setInputTarget(map_);
        icp.setMaxCorrespondenceDistance(0.6);
        icp.setTransformationEpsilon(1e-5);
        icp.setMaximumIterations(100);
        pcl::PointCloud<pcl::PointXYZ>::Ptr aligned_cloud(new pcl::PointCloud<pcl::PointXYZ>());
        icp.align(*aligned_cloud);
        // Update the previous_cloud_ for the next frame
        previous_cloud_ = current_cloud;

        // Check if ICP converged
        if (icp.hasConverged())
        {
            // Transform the current cloud and add it to the map
            *map_ += *aligned_cloud;
            publishMap(); // Publish the map to a ROS topic
            track_matrix = track_matrix * icp.getFinalTransformation();
            std::cout << "\n"
                      << track_matrix << std::endl;
            // downsampleMap();
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
    }
}

void PointCloudMapper::floorFilter(bool statement, pcl::PointCloud<pcl::PointXYZ>::Ptr current_cloud)
    {
        if (statement)
        {
            pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
            pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
            // Create the segmentation object
            pcl::SACSegmentation<pcl::PointXYZ> seg;
            // Optional
            seg.setOptimizeCoefficients(true);
            // Mandatory
            seg.setModelType(pcl::SACMODEL_PLANE);
            seg.setMethodType(pcl::SAC_RANSAC);
            seg.setDistanceThreshold(0.2);
            seg.setInputCloud(current_cloud);
            seg.segment(*inliers, *coefficients);

            pcl::ExtractIndices<pcl::PointXYZ> extract;
            extract.setInputCloud(current_cloud);
            extract.setIndices(inliers);
            extract.setNegative(true);
            extract.filter(*current_cloud);
        }
    }

void PointCloudMapper::publishMap()
    {
        sensor_msgs::msg::PointCloud2 map_msg;
        pcl::toROSMsg(*map_, map_msg);
        map_msg.header.frame_id = "map";
        map_msg.header.stamp = this->get_clock()->now();
        map_publisher_->publish(map_msg);
    }
    // Function to save the map
void PointCloudMapper::saveMap()
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

pcl::PointCloud<pcl::PointXYZ>::Ptr convertPointCloud2ToPCL(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
    {
    pcl::PCLPointCloud2 pcl_pc2;
    pcl_conversions::toPCL(*msg, pcl_pc2);
    pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(pcl_pc2, *pcl_cloud);
    return pcl_cloud;
    }

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PointCloudMapper>());
    rclcpp::shutdown();
    return 0;
}

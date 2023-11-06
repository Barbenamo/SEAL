#ifndef ICP_DEMO_H
#define ICP_DEMO_H

#include <iostream>
#include <string>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/time.h>   // TicToc

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

void print4x4Matrix(const Eigen::Matrix4d& matrix);
void keyboardEventOccurred(const pcl::visualization::KeyboardEvent& event, void*);
int test_algo(int argc, char* argv[]);
void simple_viz_of_2_clouds(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2);
pcl::PointCloud<pcl::PointXYZ>::Ptr Create_Point_Cloud(std::vector<std::vector<std::string>> content);
void ICP_algo(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2,Eigen::Matrix4d transformation_matrix);
Eigen::MatrixXd create_matrix_from_PC(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);
#endif  // ICP_DEMO_H
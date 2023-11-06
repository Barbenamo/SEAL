#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include "csv_functions.h"
#include "interactive_icp.h"
#include <pcl/console/time.h>   // TicToc


int main (int argc, char* argv[]){
    std::string fname1 = "output0.csv";
    std::string fname2 = "output1.csv";
    std::vector<std::vector<std::string>> content1 = read_csv(fname1); // obtaining dataset from csv
    std::vector<std::vector<std::string>> content2 = read_csv(fname2); // obtaining dataset from csv
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>); // Original point cloud
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2(new pcl::PointCloud<pcl::PointXYZ>); // Next frame point cloud
    cloud1 = Create_Point_Cloud(content1);
    cloud2 = Create_Point_Cloud(content2);
    int num_points_1 = cloud1->size();
    int num_points_2 = cloud2->size();    
    Eigen::MatrixXd cloud1_points = create_matrix_from_PC(cloud1);
    // Create the centroid vector of the matrix 
    std::vector<double> centroid1{cloud1_points.col(0).sum()/num_points_1, cloud1_points.col(1).sum()/num_points_1,
    cloud1_points.col(2).sum()/num_points_1};
    
    // Defining a rotation matrix and translation vector
    Eigen::Matrix4d transformation_matrix = Eigen::Matrix4d::Identity ();
    // double theta = M_PI / 8;  // The angle of rotation in radians
    // transformation_matrix (0, 0) = std::cos (theta);
    // transformation_matrix (0, 1) = -sin (theta);
    // transformation_matrix (1, 0) = sin (theta);
    // transformation_matrix (1, 1) = std::cos (theta);

    transformation_matrix (0, 3) = centroid1.at(0);
    transformation_matrix (1, 3) = centroid1.at(1);
    transformation_matrix (2, 3) = centroid1.at(2);
    pcl::transformPointCloud(*cloud1, *cloud1,transformation_matrix);
    print4x4Matrix (transformation_matrix);
    
    //vizualization before algoritm
    simple_viz_of_2_clouds(cloud1, cloud2);
    // ICP_algo(cloud1, cloud2, transformation_matrix);
    //vizualization after algoritm
    // simple_viz_of_2_clouds(cloud1, cloud2);

    

    return 0;
}
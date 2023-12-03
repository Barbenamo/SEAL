#ifndef ODOM_SUBSCRIBER_H
#define ODOM_SUBSCRIBER_H

#include <iostream>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"

class OdomSubscriber : public rclcpp::Node
{
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr publish_;

public:
    OdomSubscriber();

private:
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg) const;
    // ... other ROS and PCL related member variables ...
};

#endif // ODOM_SUBSCRIBER_H

#include "odom_subsriber.hpp"

OdomSubscriber::OdomSubscriber() : Node("odom_subscriber") {
    subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "Odom", 10, std::bind(&OdomSubscriber::odom_callback, this, std::placeholders::_1));
}

void OdomSubscriber::odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg) const {
    std::cout << msg->pose.pose.position.x << " ,    " << msg->pose.pose.position.y <<" ,    " <<
    " ,    " << msg->pose.pose.position.z << std::endl;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OdomSubscriber>());
    rclcpp::shutdown();
    return 0;
}

cmake_minimum_required(VERSION 3.8)
project(first_node)

add_executable(first_nodee First_Node.cpp)
find_package(rclcpp REQUIRED)
target_link_libraries(first_nodee rclcpp::rclcpp)
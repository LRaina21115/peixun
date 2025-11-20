#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class SystemPublisher : public rclcpp::Node
{
    private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_ = 0;
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = "System Normal! Count: " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(),"Publishing: %s", message.data.c_str());

        publisher_->publish(message);
    }

    public:
    SystemPublisher(const std::string &node_name) : Node(node_name)
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("sys_pub",10);

        timer_ = this->create_wall_timer(500ms,std::bind(&SystemPublisher::timer_callback,this));
    }    
};


int main(int argc, char** argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<SystemPublisher>("sys_pub");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
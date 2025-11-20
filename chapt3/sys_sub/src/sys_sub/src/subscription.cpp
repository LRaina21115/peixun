#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// using std::placeholders::_1;

class SystemSubscription : public rclcpp::Node
{
    private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subcription;
    void topic_callback(const std_msgs::msg::String::SharedPtr msgs)
    {
        RCLCPP_INFO(this->get_logger(),"Receiving : %s ", msgs->data.c_str());
    }

    public:
    SystemSubscription(const std::string &node_name) : Node(node_name)
    {
        subcription = this->create_subscription<std_msgs::msg::String>("sys_pub",10,std::bind(&SystemSubscription::topic_callback,this,std::placeholders::_1));
    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<SystemSubscription>("sys_sub");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
#include <iostream>
#include "rclcpp/rclcpp.hpp"

class PersonNode : public rclcpp::Node
{
    private:
    std::string name_;
    int age_;

    public:
    PersonNode(const std::string &node_name, const std::string &name_, const int age_) : Node(node_name)
    {
        this->age_ = age_;
        this->name_ = name_;
    };

    void PersonInfo()
    {
        RCLCPP_INFO(this->get_logger(),"My name is %s, and age is %d",this->name_.c_str(),this->age_);
    };

};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<PersonNode>("Second_Node","LRaina",2000);
    node->PersonInfo();
    // PersonNode node2 = new PersonNode();
    // node2.PersonInfo();
    // node->age_; // error
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp" // 引入我们在“侦察”步骤中查到的消息头文件

using namespace std::chrono_literals;

class TurtleController : public rclcpp::Node
{
public:
  TurtleController()
  : Node("turtle_controller") // 节点名
  {
    // 1. 创建发布者
    // 注意：话题名称必须与 /turtlesim 订阅的完全一致
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);

    // 2. 创建定时器，100ms 发布一次指令 (10Hz)
    timer_ = this->create_wall_timer(
      100ms, std::bind(&TurtleController::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto msg = geometry_msgs::msg::Twist();
    
    // 设置线速度 (m/s) - 前进
    msg.linear.x = 2.0; 
    // 设置角速度 (rad/s) - 逆时针旋转
    msg.angular.z = 1.0;

    // 打印日志
    RCLCPP_INFO(this->get_logger(), "Sending Command: Linear X=%.2f, Angular Z=%.2f", msg.linear.x, msg.angular.z);

    // 发布消息
    publisher_->publish(msg);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TurtleController>());
  rclcpp::shutdown();
  return 0;
}
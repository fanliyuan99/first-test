#include "ros/ros.h"
#include "std_msgs/String.h"
// 回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  // 告诉master需要订阅chatter topic消息
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::spin(); // 自循环
  return 0;
}

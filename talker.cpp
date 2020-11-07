#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
int main(int argc, char **argv)
{
  //初始化ROS，名称重映射（唯一），必须为base name，不含/
  ros::init(argc, argv, "talker"); 
  // 为进程的节点创建一个句柄，第一个创建的NodeHandle初始化节点
  ros::NodeHandle n;
  // 告诉主机要在chatter topic上发布一个std_msgs消息
  // 主机会订阅所有chatter topic节点，参数表示发布队列的大小（先进先出）
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(10);  // 自循环频率
  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();
    // 输出，用来替代prinf/cout
    ROS_INFO("%s", msg.data.c_str()); 
    chatter_pub.publish(msg);

    ros::spinOnce();
    // 休眠，来使发布频率为10Hz
    loop_rate.sleep();
    ++count;
  }
  return 0;
}

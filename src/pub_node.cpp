#include "ros/ros.h"

#include <sstream>
#include "geometry_msgs/Twist.h"
#include <string>
int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "talker");


  ros::NodeHandle n;

  
  geometry_msgs::Twist base_cmd;
  std::string namesp = ros::this_node::getNamespace();
  ROS_INFO_STREAM(namesp);
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>(namesp+"/cmd_vel", 1000);
  ros::Rate loop_rate(5);

  int count = 0;
  while (ros::ok())
  {

    /*switch(count%4){
    	case 0:base_cmd.linear.x=8.0;
	       base_cmd.angular.z=0.0;
	       break;
        case 1:base_cmd.linear.x=2.0;
	       base_cmd.angular.z=1.8;
	       break;
	case 2:base_cmd.linear.x=-8.0;
	       base_cmd.angular.z=0.0;
	       break;
	case 3:base_cmd.linear.x=0.0;
	       base_cmd.angular.z=1.0;
	       break;



    }*/

	base_cmd.linear.x=0.128805;
	base_cmd.angular.z=0.0;
    ROS_INFO_STREAM(base_cmd.linear.x);
    ROS_INFO_STREAM(base_cmd.angular.z);	
    chatter_pub.publish(base_cmd);



    ros::spinOnce();


    loop_rate.sleep();

    ++count;
  }


  return 0;
}

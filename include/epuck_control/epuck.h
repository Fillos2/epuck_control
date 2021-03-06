/*
 * epuck.h
 *
 *  Created on: 15/apr/2015
 *      Author: filippo
 */

#ifndef EPUCK_CONTROL_SRC_EPUCK_H_
#define EPUCK_CONTROL_SRC_EPUCK_H_
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
//#include <serial/serial.h>
#include "epuck_control/serialcomm.h"
class e_puck {
public:
		e_puck();
	virtual ~e_puck();
private:
	std::string nome_;
	double last_vel_update_;
	int left_freq_,right_freq_;
	double raggio_,distanza_,ratio_;
	ros::NodeHandle nh_;
	bool flag;
	ros::Subscriber sub_;
	//serial::Serial ser_;
	SerialComm * ser_;
	int connect(std::string num);
	void cmd_vel_Callback(const geometry_msgs::Twist::ConstPtr& msg);


};

#endif /* EPUCK_CONTROL_SRC_EPUCK_H_ */

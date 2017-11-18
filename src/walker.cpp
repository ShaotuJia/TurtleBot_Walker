/*
 * @file walker.cpp
 * @brief
 * @author Shaotu Jia
 * @copyright Copyright (C) 2007 Free Software Foundation, Inc.
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <memory>
#include "turtlebot_walker/walker.hpp"
/**
 * @brief This constructor combine functions within the class to let turtlebot
 * move forward and turn once find obstacles
 * @param vel The linear velocity in x - direction
 * @param rot The angular velocity once find obstacles
 */
Walk::Walk(double vel, double rot):vel(vel),rot(rot){

}

void Walk::move_forward() {
	//auto n = std::make_shared<ros::NodeHandle>();
	ros::Publisher move_pub = nh->advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1000);


	geometry_msgs::Twist forward;
	geometry_msgs::Twist turn;

	forward.linear.x = 2;
	forward.linear.y = 0;
	forward.linear.z = 0;
	forward.angular.x = 0;
	forward.angular.y = 0;
	forward.angular.z = 0;

	ros::Rate loop_rate(1);		// rate of publishing is 1 Hz
	while (ros::ok()) {
		move_pub.publish(forward);	// publish move forward command
		ros::spinOnce();
		loop_rate.sleep();
	}


}

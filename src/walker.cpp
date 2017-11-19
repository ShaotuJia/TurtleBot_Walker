/*
 * @file walker.cpp
 * @brief This file implements the class members for simple walker algorithm
 * @author Shaotu Jia
 * @copyright Copyright (C) 2007 Free Software Foundation, Inc.
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <kobuki_msgs/BumperEvent.h>
#include <memory>
#include "turtlebot_walker/walker.hpp"

/**
 * @brief This function is the interface to set the velocity that moving turtlebot forward
 * @param x The linear velocity in x-direction
 * @param y The linear velocity in y-direction
 * @param z The linear velocity in z-direction
 */
void Walk::set_forward(const double& x, const double& y, const double& z) {
	forward.linear.x = x;
	forward.linear.y = y;
	forward.linear.z = z;
	forward.angular.x = 0;
	forward.angular.y = 0;
	forward.angular.z = 0;
}

/**
 * @brief This function is the interface to set the angular velocity of turtlebot
 * when it needs to avoid obstacles
 * @param r The angular velocity around z_direction
 */
void Walk::set_turn(const double& r) {
	turn.linear.x = 0;
	turn.linear.y = 0;
	turn.linear.z = 0;
	turn.angular.x = 0;
	turn.angular.y = 0;
	turn.angular.z = r;
}

/**
 * @brief This is a callback function to subscribe the topic /mobile_base/events/bumper
 * @param bumper_state The message from subscribed topic
 */
void Walk::collision(const kobuki_msgs::BumperEvent::ConstPtr& bumper_state) {
	auto state = bumper_state->state;
	if (state == 0) {
		need_turn = false;
	} else {
		need_turn = true;
	}

}

/**
 * @brief The function that moves turtlebot forward and rotate turtlebot once hitting obstacles
 */
void Walk::move() {

	// publisher to publish velocity for turtlebot
	ros::Publisher move_pub = n.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1000);

	// subscriber to listen to topic /mobile_base/events/bumper
	ros::Subscriber bumper = n.subscribe("/mobile_base/events/bumper", 1000, &Walk::collision, this);


	ros::Rate loop_rate(10);		// rate of publishing is 1 Hz
	while (ros::ok()) {
		if (need_turn) {
			move_pub.publish(turn);	// publish move forward command
		} else {
			move_pub.publish(forward);	// publish rotate command
		}
		ros::spinOnce();
		loop_rate.sleep();
	}


}

/*
 * @file walker.hpp
 * @brief
 * @author Shaotu Jia
 * @copyright Copyright (C) 2007 Free Software Foundation, Inc.
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */

#ifndef TURTLEBOT_WALKER_INCLUDE_TURTLEBOT_WALKER_WALKER_HPP_
#define TURTLEBOT_WALKER_INCLUDE_TURTLEBOT_WALKER_WALKER_HPP_

#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<memory>

class Walk {
private:
	double vel = 0;	///< The velocity of turtlebot move forward
	double rot = 0;	///< The angular velocity of rotation once the turtlebot collide.
	//std::shared_ptr<ros::NodeHandle> nh;	///< nodehandle for class walk
	ros::NodeHandle n;


public:
	Walk(double vel, double rot);
	void move_forward();
	void rotate();




};




#endif /* TURTLEBOT_WALKER_INCLUDE_TURTLEBOT_WALKER_WALKER_HPP_ */

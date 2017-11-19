/*
 * @file main.cpp
 * @brief This is the main file to run turtlebot like roomba
 * @author Shaotu Jia
 * @copyright Copyright (C) 2007 Free Software Foundation, Inc.
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */

#include <ros/ros.h>
#include "turtlebot_walker/walker.hpp"

/**
 * @brief This is the main function to run node walker
 */
int main(int argc, char **argv) {
	ros::init(argc, argv, "walk_turtlebot");	///< Initialize node with name "walk_turtlebot"
	Walk walker;	///< declare a object for class Walk
	walker.set_forward(0.01, 0.02, 0);	///< set up linear velocity when moving forward
	walker.set_turn(0.157);	///< set up angular velocity when hitting obstacles
	walker.move();	///< move the turtlebot with a simple walk algorithm like roomba

}



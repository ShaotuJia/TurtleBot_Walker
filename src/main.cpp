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

int main(int argc, char **argv) {
	ros::init(argc, argv, "walk_turtlebot");
	Walk move(1,1);
	move.move_forward();

}



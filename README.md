## Turtlebot_Walker
### Overview
This project is to implement a simple walker algorithm much like a Roomba robot vacuum cleaner. The turtlebot will move forward and rotate once its bumper hits any obstacles. 
### System Requirements
- Linux Ubuntu 16.04
- ROS Kinetic
- catkin
### Package Dependency
- roscpp
- rospy
- std_msgs
- geometry_msgs
- turtlebot_gazebo
- kobuki_msgs
- roslaunch
- gazebo_msgs
### Build/Run
- clone repository to your src directory in catkin workspace. e.g. ~/catkin_ws/src
```
git clone https://github.com/ShaotuJia/TurtleBot_Walker.git
```
- build package
```
catkin_make
```
- source project bash on termininal
```
source turtlebot_walker/devel/setup.bash 
```
- run turtlebot_walker package through launch file with rosbag record; the bag file usually locate on directory ~/.ros/
```
roslaunch turtlebot_walker walker.launch
```
- run turtlebot_walker package through launch file without rosbag record
```
roslaunch turtlebot_walker walker.launch baging:=0
```
- Inspect bag file; there is a 30secs rosbag record file in directory 'results' for topics excluding "/camera/(.*)".
```
rosbag info walker.bag
```
- Play rosbag file without gazebo simulator. Reminder: rosbag only records topics and does not record rosservice call. 
```
rosbag play walker.bag
```

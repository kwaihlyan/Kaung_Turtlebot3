/*
   Kaung Wai Hlyan Lynn _ Qibitech Assignment

   Turtlebot3 automatically moves around while avoiding obstatles in the
   standard world. Initially set the postion and orientation of the turtlebot by
   2D pose estimate button in Rviz. The bot will use Pos1,2,3,4 as its
   destination and attempt to reach it. When successful, it will move onto the
   next. Press Ctrl+C to exit the program.

   ROS Version: ROS 1 - Melodic
 */

#include <actionlib/client/simple_action_client.h>
#include <climits>
#include <cstdio>
#include <iostream>
#include <move_base_msgs/MoveBaseAction.h>
#include <ros/ros.h>

using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>
    MoveBaseClient;

int main(int argc, char **argv) {

  ros::init(argc, argv, "simple_navigation_goals");

  MoveBaseClient ac("move_base", true);

  while (!ac.waitForServer(ros::Duration(5.0))) {
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  int iteration = 0;
  double pos_x[4] = {-1.938, 0.358, 0.802,
                     -0.322}; // x coordinates of 4 positions
  double pos_y[4] = {-0.483, 0.678, -0.665,
                     0.588}; // y coordinates of 4 positions
  double orient_w[4] = {0.999, 0.703, 0.87,
                        0.684}; // orientation of 4 positions

  while (ros::ok() == true) {

    move_base_msgs::MoveBaseGoal goal;

    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    cout << "Position" << iteration + 1 << endl;
    goal.target_pose.pose.position.x = pos_x[iteration];
    goal.target_pose.pose.position.y = pos_y[iteration];
    goal.target_pose.pose.orientation.w = orient_w[iteration];

    ROS_INFO("Attempting to reach destination");
    ac.sendGoal(goal);

    ac.waitForResult();

    // If arrived at the position, move on to the next position.
    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
      ROS_INFO("Destination reached.Moving on...");
      iteration++;
      if (iteration > 3) {
        iteration = 0;
      }
    }

    else {
      ROS_INFO("Didnt arrive");
    }
  }

  return 0;
}
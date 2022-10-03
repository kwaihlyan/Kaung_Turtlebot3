Kaung Wai Hlyan Lynn _ Qibitech Assignment

#ROS version: Melodic
#simulation_ws contains the packages for turtlebot3.
#catkin_ws contains the package for cpp file which automate the movement of turtlebot3.

1) Open up a shell. cd into simulation_ws. Type the folllowing command.

    source devel/setup.bash
    export TURTLEBOT3_MODEL=burger
    roslaunch turtlebot3_gazebo turtlebot3_world.launch

Gazebo will open up and you can see turtlebot in its standard world.

2) Open up a new shell. Type the folllowing command.

    source simulation_ws/devel/setup.bash
    export TURTLEBOT3_MODEL=burger
    roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/map.yaml

Rviz will open up. map used in this simulation is attained by scanning the standard world beforehand.

3) Open up a new shell. cd into catkin_ws. Type the folllowing command.

    source devel/setup.bash
    rosrun auto_move auto_move

The auto_move executable is attained by catkin_make the source file src/auto_move.cpp
The cpp file contain the code for automating the movement of turtlebot.
The x,y and orientation data are put into three arrays, which then get updated each time the bot reaches its destination.

Press Ctrl+C to exit the program.

The gdrive links to screen records of gazebo, rviz, position data are also attached.

- Kaung Wai Hlyan Lynn
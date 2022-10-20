
# Kaung_Turtlebot3

> ROS version: **Melodic**

> **simulation_ws** contains the packages for turtlebot3.

> **catkin_ws** contains the package for cpp file which automate the movement of turtlebot3.

1) Open up a shell. `cd` into simulation_ws.
    ```
    source devel/setup.bash
    export TURTLEBOT3_MODEL=burger
    roslaunch turtlebot3_gazebo turtlebot3_world.launch
    ```
Gazebo will open up and you can see turtlebot in its standard world.

2) Open up a new shell.
    ```
    source simulation_ws/devel/setup.bash
    export TURTLEBOT3_MODEL=burger
    roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/map.yaml
    ```
Rviz will open up. map used in this simulation is attained by scanning the standard world beforehand.

3) Open up a new shell. `cd` into catkin_ws.
    ```
    source devel/setup.bash
    rosrun auto_move auto_move
    ```
The auto_move executable is made by `catkin_make` the source file, **src/auto_move.cpp**.
The cpp file contain the code for automating the movement of turtlebot.
The x,y and orientation data are put into three arrays, which then get updated each time the bot reaches its destination.

Press **Ctrl+C** to exit the program.

Here is the [gdrive link](https://drive.google.com/drive/folders/1W3oiJiCde7q7NhrTX3gDkVxxuj_lzUmO) to screen records of gazebo, rviz and position data.

> **Kaung Wai Hlyan Lynn**

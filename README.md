## Exercise 2
1.	Derive DH parameters for the Fanuc robot.
2.	Translate DH parameters to URDF and visualize the Fanuc robot in RViz with urdf_tutorial display.launch 
3.	Create a fanuc_moveit_config package and visualize the robot in RViz.
4.	Visualize TFs in RViz and write one or more ROS nodes to compute and print the TF of the end-effector in all the reference frames of all joints. From the TF, compute the translational vector, the rotation matrix, the Euler angles and the axis-angle representation.
5.	Verify the results by comparing with manual/MATLAB calculations.


## Start demo

1. Visualize the Fanuc robot in RViz:

   source devel/setup.bash

   roslaunch urdf_tutorial display.launch model:=./src/fanuc_description/robot/fanuc.xacro

2. For create fanuc_moveit_config package:

   roslaunch moveit_setup_assistant setup_assistant.launch

   follow the tutorial: https://ros-planning.github.io/moveit_tutorials/doc/setup_assistant/setup_assistant_tutorial.html
   
3. Copy tf_pkg to your workspace and build them:

   catkin build

   source devel/setup.bash

   roslaunch fanuc_moveit_config demo.launch

   source devel/setup.bash

   rosrun tf_pkg compute_tf

### Referements:
http://wiki.ros.org/tf2/Tutorials/Writing%20a%20tf2%20listener%20%28C%2B%2B%29






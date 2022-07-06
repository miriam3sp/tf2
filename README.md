## Exercise 2
1.	Derive DH parameters for the Comau robot.
2.	Translate DH parameters to URDF and visualize the Comau robot in RViz with urdf_tutorial display.launch 
3.	Create a comau_moveit_config package and visualize the robot in RViz.
4.	Visualize TFs in RViz and write one or more ROS nodes to compute and print the TF of the end-effector in all the reference frames of all joints. From the TF, compute the translational vector, the rotation matrix, the Euler angles and the axis-angle representation.
5.	Verify the results by comparing with manual/MATLAB calculations.


# Start demo
source devel/setup.bash

roslaunch urdf_tutorial display.launch model:=./src/fanuc_description/robot/fanuc.xacro


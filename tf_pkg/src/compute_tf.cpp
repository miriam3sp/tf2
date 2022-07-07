#include <iostream>
#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

int main(int argc, char** argv) {

ros::init(argc, argv, "tf2_listener");
ros::NodeHandle nodeHandle;
tf2_ros::Buffer tfBuffer;
tf2_ros::TransformListener tfListener(tfBuffer);
ros::Rate rate(1.0);

while (nodeHandle.ok()) {
  std::vector<geometry_msgs::TransformStamped> transforms(7);
try {
    transforms[0] = tfBuffer.lookupTransform("base_link", "link6",  ros::Time(0));
    transforms[1] = tfBuffer.lookupTransform("link1", "link6",  ros::Time(0));
    transforms[2] = tfBuffer.lookupTransform("link2", "link6",  ros::Time(0));
    transforms[3] = tfBuffer.lookupTransform("link3", "link6",  ros::Time(0));
    transforms[4] = tfBuffer.lookupTransform("link4", "link6",  ros::Time(0));
    transforms[5] = tfBuffer.lookupTransform("link5", "link6",  ros::Time(0));
    transforms[6] = tfBuffer.lookupTransform("link6", "link6",  ros::Time(0));

} catch (tf2::TransformException &exception) {
  ROS_WARN("%s", exception.what());
  ros::Duration(1.0).sleep();
  continue;
}

for(int i=0; i < transforms.size(); i++){
  std::ostringstream std_output;
  
  std_output << "\nTranslation ################################### \n" << std::endl;
  std_output << transforms[i].transform.translation << std::endl;

  tf2::Quaternion q;
  tf2::fromMsg(transforms[i].transform.rotation, q);

  std_output << "Rotation ################################### \n" << std::endl;
  tf2::Matrix3x3 matrix(q);
  for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        std_output << matrix[i][j] << ' ';
      }
       std_output<< std::endl;
  }

  std_output << "\nEuler angles ################################### \n" << std::endl;
  tf2Scalar roll, pitch, yaw;
  matrix.getRPY(roll, pitch, yaw);
  std_output << "Roll =" << roll << std::endl;
  std_output << "Pitch =" << pitch << std::endl;
  std_output << "Yaw =" << yaw << "\n" <<std::endl;


  std_output << "Axis/angle ################################### \n" << std::endl;
  tf2::Vector3 rotation_axis = q.getAxis();
  std_output << "Axis = [" << rotation_axis.getX() << ", " << rotation_axis.getY() << ", " << rotation_axis.getZ() << "]" << std::endl;
  std_output << "Angle = " << q.getAngle() << std::endl;

  
  ROS_INFO_STREAM(std_output.str());
  
}

rate.sleep();
}

ros::shutdown();
return 0;
};



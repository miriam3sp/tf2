#include <iostream>
#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>


int main(int argc, char** argv) {

ros::init(argc, argv, "tf2_listener");
ros::NodeHandle nodeHandle;
tf2_ros::Buffer tfBuffer;
tf2_ros::TransformListener tfListener(tfBuffer);
ros::Rate rate(1.0);

while (nodeHandle.ok()) {
geometry_msgs::TransformStamped transform;
geometry_msgs::TransformStamped transform1;
geometry_msgs::TransformStamped transform2;
geometry_msgs::TransformStamped transform3;
geometry_msgs::TransformStamped transform4;
geometry_msgs::TransformStamped transform5;
try {
transform= tfBuffer.lookupTransform("base_link","link6", ros::Time(0));
transform1 = tfBuffer.lookupTransform("link1","link6", ros::Time(0));
transform2 = tfBuffer.lookupTransform("link2","link6", ros::Time(0));
transform3 = tfBuffer.lookupTransform("link3","link6", ros::Time(0));
transform4 = tfBuffer.lookupTransform("link4","link6", ros::Time(0));
transform5 = tfBuffer.lookupTransform("link5","link6", ros::Time(0));

} catch (tf2::TransformException &exception) {
ROS_WARN("%s", exception.what());
ros::Duration(1.0).sleep();
continue;
}

  printf("Translations")
  transform.transform.translation
  transform1.transform.translation
  transform2.transform.translation
  transform3.transform.translation
  transform4.transform.translation
  transform5.transform.translation

  // transform.transform.translation  definiscono quanto lontano si è spostato il frame figlio in ciascuna direzione dal genitore
  // transform.transform.rotation definiscono di quanto il frame figlio ha ruotato dal genitore usando un quaternione 

  tf2::Quaternion q;
  transform.transform.rotation
  transform1.transform.rotation
  transform2.transform.rotation
  transform3.transform.rotation
  transform4.transform.rotation
  transform5.transform.rotation

  printf("Rotation Matrix")
  tf2::Matrix3x3 matrix(q);

  double roll, pitch, yaw;
  printf("Euler Angles")
  matrix.getRPY(roll, pitch, yaw);
  

rate.sleep();
}
return 0;
};


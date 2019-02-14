/// Will publish my drone given its configuration

#include <iostream>
#include <sstream>
using namespace std;

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "drone_pub_test");
  ros::NodeHandle nh;

  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher vis_pub = nh.advertise<visualization_msgs::Marker>( "visualization_marker", 0 );

  ros::Rate loop_rate(10);


  int count = 0;
  while (ros::ok())
  {
        visualization_msgs::Marker marker;
        marker.header.frame_id = "world";
        marker.header.stamp = ros::Time();
        marker.ns = "my_namespace";
        marker.id = 0;
        marker.type = visualization_msgs::Marker::SPHERE;
        marker.action = visualization_msgs::Marker::ADD;
        marker.pose.position.x = 1;
        marker.pose.position.y = 1;
        marker.pose.position.z = 1;
        marker.pose.orientation.x = 0.0;
        marker.pose.orientation.y = 0.0;
        marker.pose.orientation.z = 0.0;
        marker.pose.orientation.w = 1.0;
        marker.scale.x = 1;
        marker.scale.y = 1;
        marker.scale.z = 1;
        marker.color.a = 1.0; // Don't forget to set the alpha!
        marker.color.r = 0.0;
        marker.color.g = 1.0;
        marker.color.b = 0.0;

        marker.type = visualization_msgs::Marker::MESH_RESOURCE;
        marker.mesh_resource = "package://teensytiny/meshmodels/quad_plus.obj";
        vis_pub.publish( marker );

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
  }


  return 0;
}

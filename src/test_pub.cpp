/// Will publish my drone given its configuration

#include <iostream>
#include <sstream>
using namespace std;

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <visualization_msgs/Marker.h>

#include "utils/RosMarkerUtils.h"
#include "utils/PoseManipUtils.h"

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
        RosMarkerUtils::init_quad_plus( marker, 1.0 );
        marker.id = 0;
        marker.ns = "quad_0";

        RosMarkerUtils::setcolor_to_marker( 1.0, 1.0, 1.0, marker );
        RosMarkerUtils::setposition_to_marker( 0.0 , 2.0, float(count)/10., marker );

        // marker.type = visualization_msgs::Marker::MESH_RESOURCE;
        // marker.mesh_resource = "package://teensytiny/meshmodels/quad_plus.obj";
        cout << "publish cam\n";
        vis_pub.publish( marker );

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
  }


  return 0;
}

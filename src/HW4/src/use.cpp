#include <ros/ros.h>
#include "HW4/First_srv.h"


int main ( int argc, char** argv ) 
{
	// Initialize the ROS system and become a node .
	ros::init ( argc, argv, "use1" ) ;
	ros::NodeHandle nh ;
	
    ros::ServiceClient client = nh.serviceClient<HW4::First_srv>("pow");

    HW4::First_srv srv;
    srv.request.input_req1 = atoll(argv[1]);
    client.call(srv);
}







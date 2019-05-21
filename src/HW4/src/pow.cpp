#include <ros/ros.h>
#include "HW4/First_srv.h"


int cal_pow(int number)
{
    return number*number;
}

bool service_request(HW4::First_srv::Request &req, HW4::First_srv::Response &res)
{
  ROS_INFO("Request Num = %d",req.input_req1);
  res.output_res1 = cal_pow(req.input_req1);
  ROS_INFO("Response: %d is pow ",(res.output_res1));
  return true;
}


int main ( int argc, char** argv ) 
{
  
	// Initialize the ROS system and become a node .
	ros::init ( argc, argv, "pow1" ) ;
	ros::NodeHandle nh ;
  ROS_INFO("Request Ready!");
  ros::ServiceServer service = nh.advertiseService("pow", service_request);
  ros::spin();
}



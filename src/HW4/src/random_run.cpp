// This program publishes randomly−generated velocity
// messages for turtlesim .
#include <ros/ros.h>
#include <geometry_msgs/Twist.h> // For geometry_msgs::Twist
#include <HW4/turtle_cmd.h>
#include <stdlib.h> // For rand() and RAND_MAX



int main ( int argc, char** argv ) 
{
	// Initialize the ROS system and become a node .
	ros::init ( argc, argv, "random_run_node") ;
	ros::NodeHandle nh ;

    /*system("rosparam load /home/shaq/325/src/test1/config/freq.yaml");

	ros::service::waitForService("clear");*/

    /*int freq;
    // nh.getParam("~freq", freq);   
	nh.setParam("freq", freq);*/




	// Create a publisher obj ect 
	ros::Publisher pub = nh.advertise <geometry_msgs::Twist >("turtle1/cmd_vel", 1000) ;
	
	// Seed the random number generator .
	srand (time(0));

	// Loop at 2Hz until the node is shut down.
	ros::Rate loop_rate(2);
	while ( ros::ok () ) 
	{
		// Create and fill in the message . The other four
		// fields , which are ignored by turtl esim , default to 0.
		geometry_msgs::Twist msg ;
		HW4::turtle_cmd msg1;
		msg1.x= double ( rand()) / double(RAND_MAX);
		msg1.z = 2 * double ( rand() )/double(RAND_MAX)-1 ;


		msg.linear.x = msg1.x;
		msg.angular.z = msg1.z;

		// Publish the message .
		pub.publish ( msg ) ;

		// Send a message to rosout with the details .
		ROS_INFO_STREAM( "Sending random velocity command : "
		<< " linear=" << msg1.x
		<< " angular=" << msg1.z) ;

		// Wait untilit's time for another iteration .
		loop_rate.sleep();
	}
}

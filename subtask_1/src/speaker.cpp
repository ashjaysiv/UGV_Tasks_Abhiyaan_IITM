#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main (int argc, char **argv)
{
	//initialize ros
	ros::init(argc, argv, "speaker");
	
	// node variable
	ros::NodeHandle n;
	
	// publisher node to topic "/chatter"
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1); 
	ros::Rate loop_rate(10);

	int count=0;
	while(ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		ss<<"NO.1 CFI TEAM";
		msg.data = ss.str();
		
		// msg.data = "NO.1 CFI TEAM" + "ABHIYAAN";
		// publish "NO.1 CFI TEAM to topic 
		ROS_INFO("%s", msg.data.c_str());
		chatter_pub.publish(msg);
		ros::spinOnce();

		loop_rate.sleep();
		count++;
	}
	
	return 0;
}

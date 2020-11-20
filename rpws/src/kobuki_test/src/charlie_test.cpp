#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv)
{
    //init the ROS node
    ros::init(argc, argv, "charlie_test");
    ros::NodeHandle nh;

    //! We will be publishing to the "/base_controller/command" topic to issue commands
    ros::Publisher cmd_vel_pub_;

    //set up the publisher for the cmd_vel topic
    cmd_vel_pub_ = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1);

    //we will be sending commands of type "twist"
    geometry_msgs::Twist base_cmd;

    base_cmd.linear.x = base_cmd.linear.y = base_cmd.angular.z = 0;
    base_cmd.linear.x = 1.0;

while(nh.ok()){
    //publish the assembled command
    cmd_vel_pub_.publish(base_cmd);

    ros::spinOnce();
}
    return 0;
}
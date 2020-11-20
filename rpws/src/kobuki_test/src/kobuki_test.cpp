#include <iostream>

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>


void callback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
  float scanImage[10];
    
    float x = msg->ranges.at(1);
    //float x = msgsensor_msgs::LaserScan range_data;
    //scanImage[0] = range_data.ranges.at(1);

    ROS_INFO("This is the scan info at place 0 = %f", x);//scanImage[0]);
}

int main(int argc, char** argv)
{
    //init the ROS node
    ros::init(argc, argv, "charlie_test");
    ros::NodeHandle nh;

    //! We will be publishing to the "/base_controller/command" topic to issue commands
    ros::Publisher cmd_vel_pub;

    ros::Subscriber wall_detection_sub;

    //set up the publisher for the cmd_vel topic
    cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1);

    

    //we will be sending commands of type "twist"
    geometry_msgs::Twist base_cmd;
    

    //base_cmd.linear.x = base_cmd.linear.y = base_cmd.angular.z = 0;
    base_cmd.linear.x = 1.0;

    

while (ros::ok())
{
    //publish the assembled command
    cmd_vel_pub.publish(base_cmd);

    wall_detection_sub = nh.subscribe<sensor_msgs::LaserScan>("/scan",10, callback);
    ros::spin();//ros::spinOnce();
    
}
    return 0;
}


/**
class RobotDriver
{
private:
  //! The node handle we'll be using
  ros::NodeHandle nh_;
  //! We will be publishing to the "/base_controller/command" topic to issue commands
  ros::Publisher cmd_vel_pub_;

public:
  //! ROS node initialization
  RobotDriver(ros::NodeHandle &nh)
  {
    nh_ = nh;
    //set up the publisher for the cmd_vel topic
    cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1);
  }

  //! Loop forever while sending drive commands based on keyboard input
  bool driveKeyboard()
  {
    std::cout << "Type a command and then press enter.  "
      "Use '+' to move forward, 'l' to turn left, "
      "'r' to turn right, '.' to exit.\n";

    //we will be sending commands of type "twist"
    geometry_msgs::Twist base_cmd;

    char cmd[50];
    while(nh_.ok()){

      std::cin.getline(cmd, 50);
      if(cmd[0]!='+' && cmd[0]!='l' && cmd[0]!='r' && cmd[0]!='.')
      {
        std::cout << "unknown command:" << cmd << "\n";
        continue;
      }

      base_cmd.linear.x = base_cmd.linear.y = base_cmd.angular.z = 0;
      //move forward
      if(cmd[0]=='+'){
        base_cmd.linear.x = 0.25;
      }
      //turn left (yaw) and drive forward at the same time
      else if(cmd[0]=='l'){
        base_cmd.angular.z = 0.75;
        base_cmd.linear.x = 0.25;
      }
      //turn right (yaw) and drive forward at the same time
      else if(cmd[0]=='r'){
        base_cmd.angular.z = -0.75;
        base_cmd.linear.x = 0.25;
      }
      //quit
      else if(cmd[0]=='.'){
        break;
      }

      //publish the assembled command
      cmd_vel_pub_.publish(base_cmd);
    }
    return true;
  }

};

int main(int argc, char** argv)
{
  //init the ROS node
  ros::init(argc, argv, "kobuki_test");
  ros::NodeHandle nh;

  RobotDriver driver(nh);
  driver.driveKeyboard();
}
*/
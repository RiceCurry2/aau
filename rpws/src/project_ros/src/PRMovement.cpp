#include "pr_movement/PRMovement.hpp"

namespace pr_movement{

PRMovement::PRMovement(ros::NodeHandle& nodeHandle)
    :nodeHandle_(nodeHandle)
    {
        /*if(!readParameters()){
            ROS_ERROR("Could not read parameters.");
            ros::requestShutdown();
        }*/
        publisher_ = nodeHandle_.advertise<geometry_msgs::Twist>(publisherTopic_, 10);
        ROS_INFO("Sucessfully launched node.");

        PRMovement::GoForward();
    }

bool PRMovement::readParameters(){
    if(!nodeHandle_.getParam("/mobile_base/commands/velocity", publisherTopic_)){
        return false;
    }
    else{
        return true;
    }
}

void PRMovement::GoForward()
{
    geometry_msgs::Twist base_cmd;
    base_cmd.linear.x = -1.0;
    ros::Rate r(1); // 1 Hz (One message per second?)
    
    while(ros::ok()){
    publisher_.publish(base_cmd);
    r.sleep();
    }    
}

void PRMovement::topicCallback(const std_msgs::String& message)
{
    ROS_INFO_STREAM("Yesh " << message.data);
}

void PRMovement::PrintToScreen(){
    std::cout << "Hey hey";
}

}   /*namespace*/


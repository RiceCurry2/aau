#pragma once

#include <ros/ros.h>
#include <iostream>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>

namespace pr_movement {

class PRMovement
{
    public:

    PRMovement(ros::NodeHandle& nodeHandle);

    virtual ~PRMovement()
    { };

    private:

    bool readParameters();
    void topicCallback(const std_msgs::String& message);

    void GoForward();

    void PrintToScreen();

    //! ROS node handle.
    ros::NodeHandle& nodeHandle_;

    //! ROS topic subscriber.
    ros::Subscriber subscriber_;

    //! Ros topic publisher.
    ros::Publisher publisher_;

    //! ROS topic name to publish to.
    std::string publisherTopic_ = "/mobile_base/commands/velocity";

    //! ROS topic name to subscribe to.
    std::string subscriberTopic_ = "Kjartan";
};

}   /*namespace*/
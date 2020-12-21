#pragma once

#include <fstream>
#include <ros/ros.h>
#include <std_msgs/String.h>

namespace pr_map {

class PRMapLocation
{
    public:

    PRMapLocation(ros::NodeHandle& nodeHandle);
    
    virtual ~PRMapLocation()
    { };

    private:

    //! ROS node handle.
    ros::NodeHandle& nodeHandle_;

    //! ROS topic subscriber.
    ros::Subscriber subscriber_;

    //! ROS topic name to publish to.
    std::string subscriberTopic_ = "/prMap";

    void topicCallback(const std_msgs::String::ConstPtr& mapInString);

    //! Ros topic publisher.
    ros::Publisher publisher_;
};

} /*namespace*/

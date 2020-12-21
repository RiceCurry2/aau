#pragma once

#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <geometry_msgs/Twist.h>
#include <iostream>
#include <fstream>
#include <std_msgs/String.h>

namespace pr_map {

class PRMap
{
    public:

    PRMap(ros::NodeHandle& nodeHandle);
    
    virtual ~PRMap()
    { };

    private:

    //! ROS node handle.
    ros::NodeHandle& nodeHandle_;

    //! ROS topic subscriber.
    ros::Subscriber subscriber_;

    //! Ros topic publisher.
    ros::Publisher publisher_;

    //! ROS topic name to publish to.
    std::string subscriberTopic_ = "/prMap";

    //! ROS topic name to publish to.
    std::string publisherTopic_ = "/mobile_base/commands/velocity";

    void topicCallback(const std_msgs::String::ConstPtr& mapInString);

    /*std::vector< std::vector< std::vector<std::string> > > stringToVector3d(std::string mapInString)
    { return vector3dMap;};*/
};

}   /*namespace*/
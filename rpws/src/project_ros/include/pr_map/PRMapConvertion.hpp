#pragma once

#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <std_msgs/String.h>

namespace pr_map {

class PRMapConvertion
{
    public:

    PRMapConvertion(ros::NodeHandle& nodeHandle);

    virtual ~PRMapConvertion()
    { };

    std::vector< std::vector< std::vector<std::string> > > vector3dMapReturn(void)
    {return vector3dMap;};

    private:

    //! ROS node handle.
    ros::NodeHandle& nodeHandle_;

    //! ROS topic subscriber.
    ros::Subscriber subscriber_;

    //! ROS topic name to publish to.
    std::string subscriberTopic_ = "/map";

    //! ROS topic name to publish to.
    std::string publisherTopic_ = "/prMap";

    //! Ros topic publisher.
    ros::Publisher publisher_;

    std::vector< std::vector< std::vector<std::string> > > vector3dMap;

    void topicCallback(const nav_msgs::OccupancyGrid::ConstPtr& map);




};

}   /*namespace*/
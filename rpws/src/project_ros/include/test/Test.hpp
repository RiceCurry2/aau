#pragma once

#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 

namespace test {

class Test
{
    public:

    Test(ros::NodeHandle& nodeHandle);
    
    virtual ~Test()
    { };

    private:

    //! ROS node handle.
    ros::NodeHandle& nodeHandle_;

    //! ROS topic subscriber.
    ros::Subscriber subscriber_;

    //! ROS topic name to publish to.
    std::string subscriberTopic_ = "/map";

    void topicCallback(const nav_msgs::OccupancyGrid::ConstPtr& map);

};

}   /*namespace*/
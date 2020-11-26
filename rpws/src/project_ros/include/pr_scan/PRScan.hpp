#pragma once

#include <std_msgs/String.h>

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

namespace pr_scan {

class PRScan
{
    public:

    PRScan(ros::NodeHandle& nodeHandle);

    virtual ~PRScan()
    { };

    private:

    ros::NodeHandle& nodeHandle_;
    ros::Subscriber subscriber_;
    std::string subscriberTopic_ = "/scan";
    
    void topicCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
};

} /*namespace*/
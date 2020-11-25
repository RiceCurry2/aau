#pragma once

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
};

} /*namespace*/
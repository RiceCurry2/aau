#include "pr_scan/PRScan.hpp"

namespace pr_scan{

    PRScan::PRScan(ros::NodeHandle& nodeHandle)
        :nodeHandle_(nodeHandle)
    {
        subscriber_ = nodeHandle_.subscribe<sensor_msgs::LaserScan>(subscriberTopic_, 10,
                                    &PRScan::topicCallback, this);
        ROS_INFO("Sucessfully launched node.");

        ros::MultiThreadedSpinner spinner(1);

        spinner.spin();
    }

    void PRScan::topicCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
    {
        float scanImage[640];

        float xRight = msg->ranges.at(0);       // Furthes right (45 degrees) scanner is capturing
        float xCenter = msg->ranges.at(319);    // Center
        float xLeft = msg->ranges.at(639);      // Furthest left (-45 degrees) scanner is capturing

        ROS_INFO("Scan info: Left: %f, Center: %f Right: %f", xLeft, xCenter, xRight);//scanImage[0]);
    }


} /*namespace*/
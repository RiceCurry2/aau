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

        float xRight = msg->ranges.at(0);       // Furthes right scanner is capturing
        float xCenter = msg->ranges.at(319);    // Center
        float xLeft = msg->ranges.at(639);      // Furthest left scanner is capturing

        //float x = msgsensor_msgs::LaserScan range_data;
        //scanImage[0] = range_data.ranges.at(1);

        ROS_INFO("Scan info: Left: %f, Center: %f Right: %f", xLeft, xCenter, xRight);//scanImage[0]);
    }


} /*namespace*/
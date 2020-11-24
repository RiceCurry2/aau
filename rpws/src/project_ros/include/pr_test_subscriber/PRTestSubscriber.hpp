#pragma once

#include <ros/ros.h>
#include <std_msgs/String.h>

namespace pr_test_subscriber {

class PRTestSubscriber
{
    public:

    PRTestSubscriber(ros::NodeHandle& nodeHandle);

    virtual ~PRTestSubscriber()
    { };

    private:

    bool readParameters();

    void topicCallback(const std_msgs::String& message);

    //! ROS node handle.
    ros::NodeHandle& nodeHandle_;

    //! ROS topic subscriber.
    ros::Subscriber subscriber_;

    //! ROS topic name to subscribe to.
    std::string subscriberTopic_ = "/Kjartan";
};

} /*namespace*/
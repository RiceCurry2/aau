#pragma once

#include <ros/ros.h>
#include <std_msgs/String.h>

namespace project_ros_test_subscriber {

class ProjectRosTestSubscriber
{
    public:

    ProjectRosTestSubscriber(ros::NodeHandle& nodeHandle);

    virtual ~ProjectRosTestSubscriber()
    { };

    private:

    bool readParameters();

    void topicCallback(const std_msgs::String& message);

    //! ROS node handle.
    ros::NodeHandle& nodeHandle_;

    //! ROS topic subscriber.
    ros::Subscriber subscriber_;

    //! ROS topic name to subscribe to.
    std::string subscriberTopic_;
};

} /*namespace*/
#include "project_ros_test_subscriber/ProjectRosTestSubscriber.hpp"

// STD
#include <string>

namespace project_ros_test_subscriber{

ProjectRosTestSubscriber::ProjectRosTestSubscriber(ros::NodeHandle& nodeHandle)
    :nodeHandle_(nodeHandle)
    {
        /*if(!readParameters()){
            ROS_ERROR("Could not read parameters.");
            ros::requestShutdown();
        }*/
        subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1,
                                    &ProjectRosTestSubscriber::topicCallback, this);
        ROS_INFO("Sucessfully launched node.");
    }

bool ProjectRosTestSubscriber::readParameters(){
    if(!nodeHandle_.getParam("subscriber_topic", subscriberTopic_)) return false;
    return true;
}

void ProjectRosTestSubscriber::topicCallback(const std_msgs::String& message)
{
    ROS_INFO_STREAM("Yesh " << message.data);
}

} /*namespace*/
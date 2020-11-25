#include "pr_test_subscriber/PRTestSubscriber.hpp"

// STD
#include <string>

namespace pr_test_subscriber{

PRTestSubscriber::PRTestSubscriber(ros::NodeHandle& nodeHandle)
    :nodeHandle_(nodeHandle)
    {
        /*if(!readParameters()){
            ROS_ERROR("Could not read parameters.");
            ros::requestShutdown();
        }*/
        subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 10,
                                    &PRTestSubscriber::topicCallback, this);
        ROS_INFO("Sucessfully launched node.");

        ros::MultiThreadedSpinner spinner(1);

        spinner.spin();
    }

bool PRTestSubscriber::readParameters(){
    if(!nodeHandle_.getParam("subscriber_topic", subscriberTopic_)) return false;
    return true;
}

void PRTestSubscriber::topicCallback(const std_msgs::String& message)
{
    ROS_INFO_STREAM("Yesh " << message.data);
}

} /*namespace*/
#include <ros/ros.h>
#include "pr_test_subscriber/PRTestSubscriber.hpp"
#include "pr_movement/PRMovement.hpp"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "main");
    ros::NodeHandle nodeHandle("~");

    //pr_movement::PRMovement pRMovement();

    pr_test_subscriber::PRTestSubscriber pRTestSubscriber(nodeHandle);
    
    ros::spin();
    return 0;
}
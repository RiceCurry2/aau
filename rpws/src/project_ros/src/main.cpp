#include <ros/ros.h>
#include "project_ros_test_subscriber/ProjectRosTestSubscriber.hpp"
#include "project_ros_movement/ProjectRosMovement.hpp"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "main");
    ros::NodeHandle nodeHandle("~");

    project_ros_movement::ProjectRosMovement projectRosMovement;
       
    project_ros_test_subscriber::ProjectRosTestSubscriber projectRosTestSubscriber(nodeHandle);
    
    ros::spin();
    return 0;
}
#pragma once

#include <ros/ros.h>
#include <iostream>

namespace pr_movement {

class PRMovement
{
    public:

<<<<<<< Updated upstream
    PRMovement();
=======
    PRMovement(ros::NodeHandle& nodeHandle);
    
>>>>>>> Stashed changes

    virtual ~PRMovement()
    { };

    private:

    void PrintToScreen();

<<<<<<< Updated upstream
    PRMovement& movement_;
=======
    //int& argc_;
    //char**& argv_;

    //! ROS node handle.
    ros::NodeHandle& nodeHandle_;

    //! ROS topic subscriber.
    ros::Subscriber subscriber_;

    //! Ros topic publisher.
    ros::Publisher publisher_;

    //! ROS topic name to publish to.
    std::string publisherTopic_ = "/mobile_base/commands/velocity";
>>>>>>> Stashed changes

};

}   /*namespace*/
#pragma once

#include <ros/ros.h>
#include <iostream>

namespace project_ros_movement {

class ProjectRosMovement
{
    public:

    ProjectRosMovement();

    virtual ~ProjectRosMovement()
    { };

    private:

    void PrintToScreen();

};

}   /*namespace*/
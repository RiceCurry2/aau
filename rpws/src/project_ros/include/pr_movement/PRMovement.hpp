#pragma once

#include <ros/ros.h>
#include <iostream>

namespace pr_movement {

class PRMovement
{
    public:

    PRMovement();

    virtual ~PRMovement()
    { };

    private:

    void PrintToScreen();

    PRMovement& movement_;

};

}   /*namespace*/
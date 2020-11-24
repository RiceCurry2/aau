#include <ros/ros.h>
#include <thread>

#include "pr_test_subscriber/PRTestSubscriber.hpp"
#include "pr_movement/PRMovement.hpp"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "xCrushinator");
    ros::NodeHandle nodeHandle("~");
    
    std::thread t1([&]{
        pr_movement::PRMovement pRMovement(nodeHandle);
    });

<<<<<<< Updated upstream
    //pr_movement::PRMovement pRMovement();

    pr_test_subscriber::PRTestSubscriber pRTestSubscriber(nodeHandle);
=======
    std::thread t2([&]{
        pr_test_subscriber::PRTestSubscriber pRTestSubscriber(nodeHandle);
    });
    
    t1.join();
    t2.join();
    
    //ros::spin();
>>>>>>> Stashed changes
    
    return 0;
}
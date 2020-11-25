#include <ros/ros.h>
#include <thread>
#include <chrono>

#include "pr_test_subscriber/PRTestSubscriber.hpp"
#include "pr_movement/PRMovement.hpp"
#include "pr_scan/PRScan.hpp"

int main(int argc, char** argv)
{
    std::thread t1([&]{
        system("roscore && cd ../ && source devel/setup.bash");
    });

    std::this_thread::sleep_for(std::chrono::seconds(3));

    ros::init(argc, argv, "xCrushinator");
    ros::NodeHandle nodeHandle("~");
    
    std::thread t2([&]{
        pr_movement::PRMovement pRMovement(nodeHandle);
    });

    std::thread t3([&]{
        pr_test_subscriber::PRTestSubscriber pRTestSubscriber(nodeHandle);
    });

    std::thread t4([&]{
        pr_scan::PRScan pRScan(nodeHandle);
    });
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    //ros::spin();
    
    return 0;
}
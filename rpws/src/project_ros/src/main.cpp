#include <ros/ros.h>
#include <thread>
#include <chrono>
#include <iostream>

#include "pr_test_subscriber/PRTestSubscriber.hpp"
#include "pr_movement/PRMovement.hpp"
#include "pr_scan/PRScan.hpp"
#include "pr_map/PRMap.hpp"
#include "pr_map/PRMapConvertion.hpp"
#include "pr_map/PRMapLocation.hpp"
#include "test/Test.hpp"

int main(int argc, char** argv)
{
    /*std::thread t1([]{
        system("/usr/bin/terminator --new-tab -x bash -c roscore");
        //system("/usr/bin/terminator --new-tab -x source devel/setup.bash");// --new-tab -x ");//;&& ");//  --window
    });*/
    
    // std::this_thread::sleep_for(std::chrono::seconds(3));
    
    ros::init(argc, argv, "xCrushinator");
    ros::NodeHandle nodeHandle("~");

    // std::thread t2([&]{
    //     pr_movement::PRMovement pRMovement(nodeHandle);
    // });

    // std::thread t3([&]{
    //     pr_test_subscriber::PRTestSubscriber pRTestSubscriber(nodeHandle);
    // });

    // std::thread t4([&]{
    //     pr_scan::PRScan pRScan(nodeHandle);
    // });

    // std::thread t5([&]{
    //     system("/usr/bin/terminator --new-tab -x roslaunch turtlebot_stage turtlebot_in_stage.launch");
    // });
        
    // std::this_thread::sleep_for(std::chrono::seconds(3));
    
    // std::thread t6([&]{
    //     system("/usr/bin/terminator --new-tab -x roslaunch turtlebot_teleop keyboard_teleop.launch");
    // });

    std::thread t7([&]{
         pr_map::PRMapConvertion pRMapConvertion(nodeHandle);
    });

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::thread t8([&]{
         pr_map::PRMap pRMap(nodeHandle);
    });

    // std::thread t9([&]{
    //        test::Test test(nodeHandle);
    // });

    std::thread t10([&]{
        pr_map::PRMapLocation pRMapLocation(nodeHandle);        
    });



    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();
    // t5.join();
    // t6.join();
    t7.join();
    t8.join();
    // t9.join();
    t10.join();





    //ros::spin();
    
    return 0;
}
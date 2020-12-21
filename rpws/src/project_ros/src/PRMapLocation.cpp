#include "pr_map/PRMapLocation.hpp"

namespace pr_map{

PRMapLocation::PRMapLocation(ros::NodeHandle& nodeHandle)
    :nodeHandle_(nodeHandle)
    {
        subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1, &PRMapLocation::topicCallback, this);
        ROS_INFO("Sucessfully launched node.");

        ros::MultiThreadedSpinner spinner(1);
        spinner.spin();
    }

void PRMapLocation::topicCallback(const std_msgs::String::ConstPtr& mapInString)
    {
        std_msgs::String mapInString_;
        mapInString_.data = mapInString->data;
        
        int x = 1, y = 0, z = 0;
        std::vector< std::vector< std::vector<std::string> > > vector3dMap(x, std::vector< std::vector<std::string> >(y, std::vector<std::string>(z)));
        
        std::ofstream out("mapInfoLocation.txt"); //object of fstream class

        for (int b = 0, n = 0, h = 0; b < mapInString_.data.size(); b++)
        {
            if(mapInString_.data.at(b) == 'e')
            {
                // out << mapInString_.data.at(b) << "\n";
                vector3dMap.push_back(std::vector< std::vector<std::string> >());

                h = 0;
                n++;
            }
            else{
                if(mapInString_.data.at(b) == '.'){

                    vector3dMap[n].push_back(std::vector<std::string>());
                    vector3dMap[n][h].push_back("");
                    vector3dMap[n][h][z] = ".";

                    h++;
                }else if (mapInString_.data.at(b) == 'w'){

                    vector3dMap[n].push_back(std::vector<std::string>());
                    vector3dMap[n][h].push_back("");
                    vector3dMap[n][h][z] = "w";

                    h++;
                }else if (mapInString_.data.at(b) == '0'){

                    vector3dMap[n].push_back(std::vector<std::string>());
                    vector3dMap[n][h].push_back("");
                    vector3dMap[n][h][z] = "0";

                    h++;
                }else{}

                // out << mapInString_.data.at(b);
            }
        }

        int flag = 0;
        int startPositionX = 0, startPositionY = 0, nextPositionX = 0, nextPositionY = 0;
        int tempPositionX = 0, tempPositionY = 0;
        int largestY = 0;
        int place = 0;

        for (int l = 0; l < vector3dMap.size(); l++){

            if(vector3dMap[l].size() > largestY)
            {
                largestY = vector3dMap[l].size();
                place = l;
            }else{}                             
        }
        // std::cout << largestY << " " << place << " " << std::endl;


        for (int q = 0; q != vector3dMap.size(); q++){

            /*if(q < 10){
                out << "X: " << q;
            }else{out << "X:" << q;}*/

            for (int w = 0; w < vector3dMap[q].size(); w++){

                // out << vector3dMap[q][w][0];

                if (flag == 0 && vector3dMap[q][w][0] == "0" && vector3dMap[q-1][w-1][0] == "0" && vector3dMap[q-1][w][0] == "0"
                 && vector3dMap[q-1][w+1][0] == "0" && vector3dMap[q][w+1][0] == "0" && vector3dMap[q+1][w+1][0] == "0"
                  && vector3dMap[q+1][w][0] == "0" && vector3dMap[q+1][w-1][0] == "0" && vector3dMap[q][w-1][0] == "0"){

                      startPositionX = q;
                      startPositionY = w;

                      flag = 1;
                }else{}                
            }

            // out << "\n";
        }

        // out << "\nY: ";

        /*for (int m = 0; m < largestY; m++){

            out << m << " ";        
        }*/

        out << "\n\nStart position is - X: " << startPositionX << " Y: " << startPositionY << std::endl;

        ros::Rate r(0.5); // 1 Hz (One message per second?)

        while(publisher_.getNumSubscribers() < 1 && ros::ok())
        {
            /* wait for connection */
        }
        //publisher_.publish(mapInString);  // barks once
    }
} /*namespace*/
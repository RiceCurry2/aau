#include "pr_map/PRMapConvertion.hpp"

namespace pr_map{

PRMapConvertion::PRMapConvertion(ros::NodeHandle& nodeHandle)
    :nodeHandle_(nodeHandle)
    {
        subscriber_ = nodeHandle_.subscribe<nav_msgs::OccupancyGrid>(subscriberTopic_, 10,
                                    &PRMapConvertion::topicCallback, this);
        ROS_INFO("Sucessfully launched node.");

        ros::MultiThreadedSpinner spinner(1);
        spinner.spin();
    }

void PRMapConvertion::topicCallback(const nav_msgs::OccupancyGrid::ConstPtr& map){

        int x = 0, y = 0, z = 0;
        std::vector< std::vector< std::vector<std::string> > > map3d(x, std::vector< std::vector<std::string> >(y, std::vector<std::string>(z)));

        nav_msgs::OccupancyGrid map_;
        map_.data = map->data;
        map_.info = map->info;

        std::ofstream out("mapInfoConvertion.txt"); //object of fstream class

        std_msgs::String mapInString;
        mapInString.data = "";

        int widthsGoneThrough = 0, widthsGoneThroughFlag = 0;        
        int widthBefore = 0;
        int mapWidth = 0, mapWidthToDelete = 0;
        int flag = 0;


        for (int i = 0; i < map_.data.size(); i++){

            if ((i-(widthsGoneThrough * map_.info.width) == 0)){
                
                widthsGoneThrough += 1;
                widthsGoneThroughFlag = 1;
                y = 0;              
            }else{}

            if (map_.data.at(i) == 'd' || map_.data.at(i) == 0){
                
                if(widthsGoneThroughFlag == 1){

                    map3d.push_back(std::vector< std::vector<std::string> >());

                    widthBefore = ((widthsGoneThrough * map_.info.width)-(i));

                    for (int p = 0; p < (map_.info.width - widthBefore); p++){

                        map3d[x].push_back(std::vector<std::string>());
                        
                        map3d[x][y].push_back("");

                        map3d[x][y][z] = ".";
                        
                        // std::cout << ".";
                        // out << map3d[x][y][z];

                        y++;
                    }

                    widthsGoneThroughFlag = 0;
                }else{}

                while(((i+1)-(widthsGoneThrough * map_.info.width) != 0)){

                    if (map_.data.at(i) == 'd'){

                        map3d[x].push_back(std::vector<std::string>());
                            
                        map3d[x][y].push_back("");

                        map3d[x][y][z] = "w";
                        
                        // std::cout << "w";
                        // out << map3d[x][y][z];

                        y++;
                    }else{}

                    if (map_.data.at(i) == 0){

                        map3d[x].push_back(std::vector<std::string>());
                            
                        map3d[x][y].push_back("");

                        map3d[x][y][z] = "0";
                        
                        // std::cout << "0";
                        // out << map3d[x][y][z];

                        y++;
                    }else{}

                    if(map_.data.at(i) == -1){

                        map3d[x].push_back(std::vector<std::string>());
                            
                        map3d[x][y].push_back("");

                        map3d[x][y][z] = ".";
                        
                        // std::cout << ".";
                        // out << map3d[x][y][z];

                        y++;  
                    }else{}

                    i++;
                } /*while loops ends*/
                                
                // out << "\n";
                x++;
            }else{}
        };


        vector3dMap = map3d;

        publisher_ = nodeHandle_.advertise<std_msgs::String>(publisherTopic_, 10);
        ROS_INFO("Sucessfully launched node.");

        for (int l = 0; l < map3d.size(); l++){

            mapWidth = map3d[l].size();

            for (int k = mapWidth; k > 0; k--){

                if (flag == 0 && map3d[l][k-1][0] == "w" || flag == 0 && map3d[l][k-1][0] == "0"){

                    mapWidthToDelete = k+1;

                    std::cout << l << ". " << mapWidthToDelete << std::endl;

                    while(mapWidth > mapWidthToDelete+1)
                    {
                        map3d[l][mapWidth-1][0].pop_back();
                        map3d[l][mapWidth-1].pop_back();
                        map3d[l].pop_back();

                        mapWidth--;
                        // std::cout << sizeOfY;
                    }

                    map3d[l][k+1][0] = "e";
                    flag = 1;
                }else{}
            }
            flag = 0;
        }

        for (int q = 0; q != map3d.size(); q++){

            for (int w = 0; w < map3d[q].size(); w++){

                out << map3d[q][w][0];                
            }

            out << "\n";
        }

        for (int q = 0; q != map3d.size(); q++){

            for (int w = 0; w < map3d[q].size(); w++){

                mapInString.data += map3d[q][w][0];                               
            }
        }

        /*for (int b = 0; b < mapInString.data.size(); b++)
        {
            if(mapInString.data.at(b) == 'e')
            {

                out << mapInString.data.at(b) << "\n";
            }
            else{out << mapInString.data.at(b);}
        }*/


        out.close();
        std::cout << "\n\n" << "Successful termination of PRMapConvertaion class." << std::endl;

        while(publisher_.getNumSubscribers() < 1 && ros::ok())
        {
            /* wait */
        }
        publisher_.publish(mapInString);  
    };

} /*namespace*/
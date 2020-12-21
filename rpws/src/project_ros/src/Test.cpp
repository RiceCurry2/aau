#include "test/Test.hpp"

namespace test{

Test::Test(ros::NodeHandle& nodeHandle)
    :nodeHandle_(nodeHandle)
    {
        subscriber_ = nodeHandle_.subscribe<nav_msgs::OccupancyGrid>(subscriberTopic_, 10,
                                    &Test::topicCallback, this);
        ROS_INFO("Sucessfully launched node.");

        ros::MultiThreadedSpinner spinner(1);

        spinner.spin();
    }

void Test::topicCallback(const nav_msgs::OccupancyGrid::ConstPtr& map)
    {
        int x = 0, y = 0, z = 0;
        std::vector< std::vector< std::vector<std::string> > > map3d(x, std::vector< std::vector<std::string> >(y, std::vector<std::string>(z)));

        nav_msgs::OccupancyGrid map_;

        map_.data = map->data;
        map_.info = map->info;
        

        int widthsGoneThrough = 0, widthsGoneThroughFlag = 0;
        
        int mapWidth = map_.info.width;
        int mapSize = map_.data.size();
        
        int widthRemaining = 0;
        int widthBefore = 0, unknownSpaceBetweenWalls = 0;
        int map3dArrayLocationX = 0, map3dArrayLocationY = 0, map3dArrayLocationZ = 0;
        int yFlag = 0;
        std::string name = "I am here";
        std::ofstream out("mapInfo.txt"); //object of fstream class
        

        for (int i = 0; i < mapSize; i++){

            if ((i-(widthsGoneThrough * mapWidth) == 0)){
                
                widthsGoneThrough += 1;
                widthsGoneThroughFlag = 1;

                y = 0;
                
            }else{}

            if (map_.data.at(i) == 'd' || map_.data.at(i) == 0){
                
                if(widthsGoneThroughFlag == 1){

                    map3d.push_back(std::vector< std::vector<std::string> >());

                    widthBefore = ((widthsGoneThrough * mapWidth)-(i));

                    for (int p = 0; p < (mapWidth - widthBefore); p++){

                        map3d[x].push_back(std::vector<std::string>());
                        
                        map3d[x][y].push_back("");

                        map3d[x][y][z] = ".";
                        
                        std::cout << ".";
                        out << map3d[x][y][z];

                        y++;
                    }

                    widthsGoneThroughFlag = 0;
                }else{}

                while(/*map_.data.at(i-1) != -1 && */((i+1)-(widthsGoneThrough * mapWidth) != 0)){

                    unknownSpaceBetweenWalls += 1;

                    if (map_.data.at(i) == 'd'){
                        map3d[x].push_back(std::vector<std::string>());
                            
                        map3d[x][y].push_back("");

                        map3d[x][y][z] = "w";
                        
                        std::cout << "w";
                        out << map3d[x][y][z];

                        y++;
                        // i++;                    
                    }else{}

                    if (map_.data.at(i) == 0){
                        map3d[x].push_back(std::vector<std::string>());
                            
                        map3d[x][y].push_back("");

                        map3d[x][y][z] = "0";
                        
                        std::cout << "0";
                        out << map3d[x][y][z];

                        y++;
                        // i++;                    
                    }else{}

                    if(map_.data.at(i) == -1){
                        map3d[x].push_back(std::vector<std::string>());
                            
                        map3d[x][y].push_back("");

                        map3d[x][y][z] = ".";
                        
                        std::cout << ".";
                        out << map3d[x][y][z];

                        y++;
                        // i++;    
                    }else{}

                    i++;
                } /*while loops ends*/

                unknownSpaceBetweenWalls = 0;

                                
                out << "\n";
                x++;
            }else{}

            // if (i > 1 && map_.data.at(i-1) == -1 && map_.data.at(i) == 'd')
            // {
            //     widthBefore = ((widthsGoneThrough * mapWidth)-(i-1));

            //     map3d.push_back(std::vector< std::vector<std::string> >());
                
            //     for (int p = 0; p <= (mapWidth - widthBefore); p++)
            //     {
            //         map3d[x].push_back(std::vector<std::string>());

            //         map3d[x][y].push_back("z");

            //         if (map_.data.at(i) == -1)
            //         {
            //             map3d[x][y][0] = "u";
            //         }

            //         std::cout << " ";
            //         out << " ";

            //         y++;
            //     }
                                
            //     while (map_.data.at(i) == 'd')
            //     {
            //         map3d[x].push_back(std::vector<std::string>());

            //         map3d[x][y].push_back("z");

            //         if (map_.data.at(i) == 'd')
            //         {
            //             map3d[x][y][0] = "w";
            //         }else{}
                    

            //         std::cout << "w";
            //         out << "w";

            //         i++;
            //         y++;
            //         yFlag = 1;

            //         if (map_.data.at(i-1) == 'd' && map_.data.at(i) == 0)
            //         {
            //             while (map_.data.at(i) == 0)
            //             {
            //                 map3d[x].push_back(std::vector<std::string>());
                    
            //                 map3d[x][y].push_back("z");

            //                 if (map_.data.at(i) == 0){
            //                     map3d[x][y][0] = "0";
            //                 }else{}

            //                 std::cout << "0";
            //                 out << "0";
                            
            //                 i++;
            //                 y++;                            
            //             }
            //             yFlag = 1;    
            //         }else{}
                    
            //         if (yFlag == 1){yFlag = 0;}
            //         else {y++;}

            //         //y++;
            //     }
                
            //     // std::cout << "\n";

            //     std::cout << " " << i /*<< " " << widthsGoneThrough*/ << " map3d.size: " << map3d.size() << " X: " << x << " map3d[" << x << "]: " << map3d[x].size() << " Y: " << y /*<< " " << widthBefore*/ << " \n";
            //     out << " " << i /*<< " " << widthsGoneThrough*/ << " map3d.size" << map3d.size() << " X: " << x  << " map3d[" << x << "]: " << map3d[x].size() << " Y: " << y /*<< " " << widthBefore*/ << " \n\n";

            //     widthRemaining = 0;
            //     widthBefore = 0;
            //     widthsGoneThroughFlag = 0;
            //     y = 0;
            //     x++;
            // }else{}
        };

        std::cout << "\n\n" << name << std::endl;

        for (int q = 0; q != map3d.size(); q++)
        {
            for (int w = 0; w < map3d[q].size(); w++)
            {
                //std::cout << "'" << map3d[q][w][0] << "' ";
                out << map3d[q][w][0];                
            }
            //std::cout << "'" << map3d[q][0][0] << "' ";

            //std::cout << "\n";
            out << "\n";
        }

        out.close();      
    };
    
/*Test::Test()
    {
        
        int n,m, l;
	    n = 0;
	    m = 0;
        l = 0;

        std::vector< std::vector<int> > map2D(n,std::vector<int>(m , 0));

        std::vector< std::vector< std::vector<int> > > map3D(n, std::vector< std::vector<int> >(m, std::vector<int>(l)));

        //map3D.push_back(vector<vector<int>>());
        //map3D[0].push_back(vector<int>());
        //map3D[0][0].push_back("value");

        map2D.push_back(std::vector<int>());
        map2D.push_back(std::vector<int>());
        map2D.push_back(std::vector<int>());
        map2D[1].push_back(2+21);
        map2D[1].push_back(3+1);
        map2D[2].push_back(23+1);
        map2D[1].push_back(3+1);
        map2D[0].push_back(3+31);
        map2D[1].push_back(3+1);
        map2D[1].push_back(23+1);
        map2D[0].push_back(3+1);
        map2D[1].push_back(13+1);
        map2D[2].push_back(3+11);

        for (int i = 0; i < map2D.size(); i++)
        {
            std::cout << i << ". ";
            for (int p = 0; p < map2D[i].size(); p++)
            {
                std::cout << map2D[i][p] << " - ";
            }
            std::cout << "\n";
        }

        std::cout << "\n";

        map3D.push_back(std::vector< std::vector<int> >());
        map3D.push_back(std::vector< std::vector<int> >());
        map3D.push_back(std::vector< std::vector<int> >());
        //map3D.push_back(std::vector< std::vector<int> >());
        //map3D.push_back(std::vector< std::vector<int> >());
        map3D[0].push_back(std::vector<int>());
        map3D[0].push_back(std::vector<int>());
        map3D[1].push_back(std::vector<int>());
        map3D[1].push_back(std::vector<int>());
        map3D[2].push_back(std::vector<int>());
        //map3D[0].push_back(std::vector<int>());
        map3D[0][0].push_back(0);
        map3D[0][0].push_back(0);
        map3D[0][0].push_back(0);
        map3D[1][1].push_back(0);
        map3D[1][1].push_back(0);
        //map3D[1][0].push_back(3+1);
        //map3D[0][1].push_back(3+31);
        //map3D[1][2].push_back(3+1);
        //map3D[1][0].push_back(23+1);
        //map3D[0][2].push_back(3+1);
        //map3D[1][0].push_back(13+1);
        //map3D[2][1].push_back(3+11);

        std::cout << map3D.size() << std::endl;
        std::cout << map3D[0].size() << " -|- " << map3D[1].size() << " -|- " << map3D[2].size() << std::endl;
        std::cout << map3D[0][0].size() << " -|- " << map3D[0][1].size() << " -|- " << map3D[1][0].size()
                                                                 << " -|- " << map3D[1][1].size() << std::endl;

        std::cout << "\n";

        map3D[0][0][0] = 0;
        map3D[0][0][1] = 3;
        map3D[0][0][2] = 6;
        map3D[1][1][1] = 9;
        //map3D[0][0][2] = 3;
        //map3D[1][1][0] = 8;
        
        //map3D[0][1].assign(2,0);// 2;
        //map3D[0][1].assign(2,1);// 2;
        //map3D[0][0][0] = 1;

        /*std::cout << "'" << map3D[0][0][0] << "' ";
        std::cout << "'" << map3D[0][0][1] << "' ";
        std::cout << "'" << map3D[1][1][1] << "' ";*/

        /*
        std::cout << "\n";

        for (int i = 0; i < map3D.size(); i++)
        {
            std::cout << i << ". ";
            //std::cout << "'" << map3D[0].at(0).at(0) << "' ";
            for (int p = 0; p < map3D[i].size(); p++)
            {
                std::cout << p << ". ";
                //std::cout << "'" << map3D[i][p].at(0) << "' ";
                for (int f = 0; f < map3D[i][p].size(); f++)
                {
                    std::cout << f << ". ";
                    std::cout << "'" << map3D[i][p][f] << "' ";
                }
                std::cout << "\n";                
            }
            std::cout << "\n";
        }


    }*/
}
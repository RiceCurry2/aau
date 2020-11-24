cmake_minimum_required(VERSION 2.8.3)# 3.0.2)
project(project_ros)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
roscpp
)

###
## catkin specific configuration
###

catkin_package(
    INCLUDE_DIRS
        include
    #LIBRARIES
    CATKIN_DEPENDS
        roscpp
    #DEPENDS
)

include_directories(include ${catkin_INCLUDE_DIRS})

#add_library(${PROJECT_NAME}
#  src/ProjectRosMovement.cpp
#)

add_executable(${PROJECT_NAME}
src/main.cpp
src/PRTestSubscriber.cpp
src/PRMovement.cpp)


target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})
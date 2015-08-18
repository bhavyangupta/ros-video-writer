cmake_minimum_required(VERSION 2.8.3)
project(video_writer)

find_package(catkin REQUIRED COMPONENTS roscpp
                                        cv_bridge
                                        image_transport
                                        sensor_msgs)
find_package(OpenCV REQUIRED)

include_directories(${catkin_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(inc/)

add_executable(topic_to_video src/main.cpp src/video_writer_t.cpp)
target_link_libraries(topic_to_video ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

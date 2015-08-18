/** \mainpage 
* \section intro_sec Introduction
* ROS node to read an image topic and create a .avi video from it 
* \section use Usage
  rosrun video_writer topic_to_video _topic:=/camera/image _file:=output/out.mkv
  _fps:=30 _width:=640 _height:=368 _display:=1
* \note  Parameters are explained in README.md
* \author Bhavya Narain Gupta
* \date August 17,2015
*/

#include "video_writer_t.hpp"
/**
* \fn main(int argc, char **argv)
* \brief main function.

Fetches parameters from CLI. Instantiates the video_writer_t object and waits 
for callbacks to process.
*/
int main(int argc, char **argv){
  if(argc!=7){
    cout<<"INPUT ERROR!! Correct usage:" <<endl;
    cout<<"rosrun video_writer topic_to_video _topic:=/camera/image "  
        <<"_file:=name-of-file _fps:=FPS _width:=640 _height:= 368 _display:=1"
        <<endl;
    return -1;
  }

  ros::init(argc, argv,"video_writer_node");
  ros::NodeHandle nh("~");

  string topic_name; 
  string output_filename;
  int fps;
  int display;
  int frame_width;
  int frame_height;
  nh.getParam("topic",topic_name);
  nh.getParam("file",output_filename);
  nh.getParam("fps",fps);
  nh.getParam("display",display);
  nh.getParam("width",frame_width);
  nh.getParam("height",frame_height);
  
  cv::Size frame_dim(frame_width, frame_height);
  
  video_writer_t video_writer(nh, topic_name, output_filename, fps, frame_dim,
                              display);
  ros::spin();
  
  return 0;
}


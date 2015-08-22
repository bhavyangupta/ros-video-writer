#ifndef VIDEO_WRITER_VIDEO_WRITER_T_HPP
#define VIDEO_WRITER_VIDEO_WRITER_T_HPP

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>           
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/**
* \class video_writer_t "inc/video_writer_t.hpp"
* \brief Class to wrap topic read and file write
*/

class video_writer_t {
  public:
    video_writer_t(ros::NodeHandle &nh,string &topic, string &filename,
                   int fps,cv::Size frame_size,bool disp_enable);
    ~video_writer_t(void);
    void callback_image_frame(const sensor_msgs::ImageConstPtr &frame);
    void init_subscriber(void);
    void init_video_writer(void);
    void display_frame(cv::Mat &frame);
    void write_frame(cv::Mat &frame);
  private:
    ros::NodeHandle writer_nh;
    ros::Subscriber sub_frame;
    string window_name;
    string &topic_name;
    string &file_name;
    int fps;
    bool display;
    cv::VideoWriter vid_out;
    cv::Size frame_size;
};

/**
* \class sync_video_writer_t "inv/video_writer.hpp"
* \brief Class exposes more of the frame file writing api of the base class. 
         Does not start a ros::subscriber to any topic - instead it only manages
         video display/write functions when a frame is passed to the class.
*/


// class sync_video_writer_t : public video_writer {

// };

#endif //VIDEO_WRITER_VIDEO_WRITER_T_HPP

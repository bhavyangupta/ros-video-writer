#include "video_writer_t.hpp"

video_writer_t::video_writer_t(ros::NodeHandle &nh, string &topic, 
                             string &filename, int fps, cv::Size size, 
                             bool disp_enable)
:writer_nh(nh),
 topic_name(topic),
 file_name(filename),
 frame_size(size)
{ 
  this->fps = fps;
  this->display = disp_enable;
  ROS_INFO_STREAM("Topic: "<<this->topic_name << " File: "<< this->file_name << 
                  "FPS: "<<this->fps << "Display: "<< this->display<< "Size: "
                  << frame_size.width <<"x"<< frame_size.height);
  sub_frame = writer_nh.subscribe(this->topic_name,1,
                                        &video_writer_t::callback_image_frame,
                                        this);

  vid_out.open(this->file_name,CV_FOURCC('M','J','P','G'),this->fps,frame_size,
               true);
  if(!vid_out.isOpened()) {
    ROS_ERROR("Output file cannot be opened");
    exit(-1);
  }
  if (this->display) {// spawn window;
    this->window_name = "output";
    cv::namedWindow(this->window_name);
  }
  else {
    this->window_name = "";
  }
  return;
}

video_writer_t::~video_writer_t(){
  cv::destroyWindow(this->window_name);
  return;
}

void video_writer_t::callback_image_frame(const sensor_msgs::ImageConstPtr &frame){
  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(frame, sensor_msgs::image_encodings::BGR8);
  if(this->display) {
    cv::imshow(this->window_name,cv_ptr->image);
    cv::waitKey(1000/this->fps);
  }
  vid_out.write(cv_ptr->image);
  return;
}





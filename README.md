# To install:
1. clone the repository and rename the folder to video_writer/
2. execute cmake CMakeLists.txt
3. execute make 
4. execute source devel/setup.bash
5. rosrun video_writer topic_to_video _topic:=/camera/image _file:=out.mkv 
  _fps:=30 _width:=640 _height:=368 _display:=1

# Options:
* ~/topic : Name of the topic that is read
* ~/file : Output file name
* ~/fps : Frames per second(integer)
* ~/width : Frame width
* ~/height : Frame height
* ~/display : Switch to enable video display during video writing

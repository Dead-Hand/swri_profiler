// *****************************************************************************
//
// Copyright (c) 2015, Southwest Research Institute® (SwRI®)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Southwest Research Institute® (SwRI®) nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL Southwest Research Institute® BE LIABLE 
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// *****************************************************************************

#ifndef SWRI_PROFILER_TOOLS_ROS_SOURCE_BACKEND_H_
#define SWRI_PROFILER_TOOLS_ROS_SOURCE_BACKEND_H_

#include <QObject>
#include <ros/subscriber.h>
#include <swri_profiler_msgs/ProfileIndexArray.h>
#include <swri_profiler_msgs/ProfileDataArray.h>

namespace swri_profiler_tools
{
class RosSourceBackend : public QObject
{
  Q_OBJECT;

  ros::Subscriber index_sub_;
  ros::Subscriber data_sub_;  

  bool is_connected_;  
  
 Q_SIGNALS:
  void connected(bool connected, QString uri);
  void indexReceived(swri_profiler_msgs::ProfileIndexArray);
  void dataReceived(swri_profiler_msgs::ProfileDataArray);

 public:
  RosSourceBackend();
  ~RosSourceBackend();

 private:
  void startRos();
  void stopRos();
  
  void timerEvent(QTimerEvent *event);

  void handleIndex(const swri_profiler_msgs::ProfileIndexArray &msg);
  void handleData(const swri_profiler_msgs::ProfileDataArray &msg);
};  // class RosSourceBackend
}  // namespace swri_profiler_tools
#endif  // SWRI_PROFILER_TOOLS_ROS_SOURCE_BACKEND_H_

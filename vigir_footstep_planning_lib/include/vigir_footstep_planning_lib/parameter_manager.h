//=================================================================================================
// Copyright (c) 2015, Alexander Stumpf, TU Darmstadt
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the Simulation, Systems Optimization and Robotics
//       group, TU Darmstadt nor the names of its contributors may be used to
//       endorse or promote products derived from this software without
//       specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//=================================================================================================

#ifndef VIGIR_FOOTSTEP_PLANNING_PARAMETER_MANAGER_H__
#define VIGIR_FOOTSTEP_PLANNING_PARAMETER_MANAGER_H__

#include <ros/ros.h>

#include <boost/noncopyable.hpp>
#include <boost/filesystem.hpp>

#include <vigir_footstep_planning_lib/helper.h>

#include <vigir_footstep_planning_msgs/footstep_planning_msgs.h>
#include <vigir_footstep_planning_msgs/parameter_set.h>



namespace vigir_footstep_planning
{
class ParameterManager
  : boost::noncopyable
{
public:
  static void initTopics(ros::NodeHandle& nh);

  static void clear();

  static bool empty();
  static size_t size();

  static bool loadFromFile(const boost::filesystem::path& path, ParameterSet& params);
  static void loadParameterSets(const std::string& path);

  static void updateParameterSet(const ParameterSet& params);
  static void updateParameterSet(const msgs::ParameterSet& param_sets);

  static bool getParameterSet(const std::string& name, ParameterSet& params);
  static bool getParameterSet(const std::string& name, msgs::ParameterSet& param_sets);

  static void getAllParameterSets(std::vector<ParameterSet>& param_sets);
  static void getAllParameterSets(std::vector<msgs::ParameterSet>& param_sets);

  static void removeParameterSet(const std::string& name);

  static bool hasParameterSet(const std::string& name);

  static void getParameterSetNames(std::vector<std::string>& names);
  static void getParameterSetNames(std::vector<std_msgs::String>& names);

  static bool setActive(const std::string& name);
  static const ParameterSet& getActive();

  // typedefs
  typedef boost::shared_ptr<ParameterManager> Ptr;
  typedef boost::shared_ptr<const ParameterManager> ConstPtr;

protected:
  ParameterManager();

  static ParameterManager::Ptr& Instance();

  static ParameterManager::Ptr singelton;

  // subscriber
  void updateParameterSet(const msgs::ParameterSetConstPtr& params);

  // service calls
  bool setParameterSetService(msgs::SetParameterSetService::Request& req, msgs::SetParameterSetService::Response& resp);
  bool getParameterSetService(msgs::GetParameterSetService::Request& req, msgs::GetParameterSetService::Response& resp);
  bool getAllParameterSetsService(msgs::GetAllParameterSetsService::Request& req, msgs::GetAllParameterSetsService::Response& resp);
  bool getParameterSetNamesService(msgs::GetParameterSetNamesService::Request& req, msgs::GetParameterSetNamesService::Response& resp);

  // action server calls
  void setParameterSetAction(SimpleActionServer<msgs::SetParameterSetAction>::Ptr& as);
  void getParameterSetAction(SimpleActionServer<msgs::GetParameterSetAction>::Ptr& as);
  void getAllParameterSetsAction(SimpleActionServer<msgs::GetAllParameterSetsAction>::Ptr& as);
  void getParameterSetNamesAction(SimpleActionServer<msgs::GetParameterSetNamesAction>::Ptr& as);

  // subscriber
  ros::Subscriber update_parameter_set_sub;

  // service servers
  ros::ServiceServer set_parameter_set_srv;
  ros::ServiceServer get_parameter_set_srv;
  ros::ServiceServer get_all_parameter_sets_srv;
  ros::ServiceServer get_parameter_set_names_srv;

  // action servers
  SimpleActionServer<msgs::SetParameterSetAction>::Ptr set_parameter_set_as;
  SimpleActionServer<msgs::GetParameterSetAction>::Ptr get_parameter_set_as;
  SimpleActionServer<msgs::GetAllParameterSetsAction>::Ptr get_all_parameter_sets_as;
  SimpleActionServer<msgs::GetParameterSetNamesAction>::Ptr get_parameter_set_names_as;

  // parameter sets
  std::map<std::string, ParameterSet> param_sets;

  // current selected parameter set
  ParameterSet::Ptr active_parameter_set;
};
}

#endif

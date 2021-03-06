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

#ifndef VIGIR_FOOTSTEP_PLANNING_LIB_ROBOT_MODEL_PLUGIN_H__
#define VIGIR_FOOTSTEP_PLANNING_LIB_ROBOT_MODEL_PLUGIN_H__

#include <ros/ros.h>

#include <vigir_footstep_planning_lib/helper.h>

#include <vigir_footstep_planning_lib/plugins/plugin.h>



namespace vigir_footstep_planning
{
class RobotModelPlugin
  : public Plugin
{
public:
  RobotModelPlugin(const ParameterSet& params, ros::NodeHandle &nh);
  RobotModelPlugin(ros::NodeHandle &nh);

  bool isUnique() const final;

  const geometry_msgs::Vector3& getFootSize() const;
  const geometry_msgs::Vector3& getUpperBodySize() const;
  const geometry_msgs::Vector3& getUpperBodyOriginShift() const;

  // typedefs
  typedef boost::shared_ptr<RobotModelPlugin> Ptr;
  typedef boost::shared_ptr<const RobotModelPlugin> ConstPtr;

protected:
  // foot paramaters
  geometry_msgs::Vector3 foot_size;

  // upper body parameters
  geometry_msgs::Vector3 upper_body_size;
  geometry_msgs::Vector3 upper_body_origin_shift;
};
}

#endif

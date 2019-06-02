/*
 * file: run_rosbag_experiment.cpp
 * purpose: Initialize a ROS node to generate data.
 */

#include <chrono>
#include <csignal>
#include <thread>
#include <ros/ros.h>
#include "rosbag_experiment/numeric_data_generator.hpp"

using namespace std::chrono_literals;

bool interrupted{false};

int main(int argc, char ** argv)
{
  ros::init(argc, argv, "data_generator",
            ros::init_options::NoSigintHandler | ros::init_options::NoRosout);
  signal(SIGINT, [](int /* sig */){ interrupted = true; ros::shutdown(); });

  // Initialize the generator object
  ros::NodeHandle handle;
  NumericDataGenerator generator(handle, 100);

  while (ros::ok() && !interrupted)
  {
    ros::spin();
    std::this_thread::sleep_for(100ms);
  }

  generator.stop();

  return 0;
}
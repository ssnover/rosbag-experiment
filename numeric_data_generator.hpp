/*
 * file: numeric_data_generator.hpp
 * purpose: Define a class which generates numeric data and publishes it to a topic.
 */

#pragma once

#include <memory>
#include <thread>
#include <ros/ros.h>

class NumericDataGenerator
{
public:

  NumericDataGenerator(ros::NodeHandle & nodeHandle, double frequency);

  void stop();

private:

  void getNextDatum(ros::TimerEvent const & /* event */) const;

  ros::Publisher mutable mDataPublisher;
  ros::Timer mPublishTimer;

};

/*
 * file: numeric_data_generator.cpp
 * purpose: Generate a sinusoidal data stream and publish it on a topic.
 */

#include <cmath>
#include <std_msgs/Float64.h>
#include "numeric_data_generator.hpp"
#include "std_msgs_utility.hpp"

NumericDataGenerator::NumericDataGenerator(ros::NodeHandle &nodeHandle, double frequency)
  : mDataPublisher(nodeHandle.advertise<std_msgs::Float64>("data", 10)),
    mPublishTimer(nodeHandle.createTimer(ros::Duration(1 / frequency),
                                         &NumericDataGenerator::getNextDatum,
                                         this))
{
}

void NumericDataGenerator::stop()
{
  mPublishTimer.stop();
}

void NumericDataGenerator::getNextDatum(ros::TimerEvent const & /* event */) const
{
  static auto startTime = std::chrono::steady_clock::now();
  auto currentTime = std::chrono::steady_clock::now();
  auto timeSinceStart = currentTime - startTime;
  double timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(timeSinceStart).count() / 1000.;

  mDataPublisher.publish(toFloat64(sin(timeDiff)));
}

cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)
project(rosbag_experiment)

find_package(catkin REQUIRED COMPONENTS
    roscpp
)

catkin_package(
    )

###################
# LIBRARIES
###################
add_library(numeric_data_generator STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/numeric_data_generator.cpp)
target_include_directories(numeric_data_generator
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${catkin_INCLUDE_DIRS}
    SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include ${catkin_INCLUDE_DIRS})
target_link_libraries(numeric_data_generator
    PRIVATE ${catkin_LIBRARIES})
target_compile_options(numeric_data_generator PRIVATE -Wall -Wextra --std=c++14)

###################
# EXECUTABLES
###################
add_executable(run_rosbag_experiment ${CMAKE_CURRENT_SOURCE_DIR}/src/run_rosbag_experiment.cpp)
target_link_libraries(run_rosbag_experiment
    PRIVATE numeric_data_generator ${catkin_LIBRARIES})
target_include_directories(run_rosbag_experiment
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${catkin_INCLUDE_DIRS}
    SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include ${catkin_INCLUDE_DIRS})
target_compile_options(run_rosbag_experiment PRIVATE -Wall -Wextra --std=c++14)

cmake_minimum_required(VERSION 3.1)
project(simulation_robot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

find_package (Threads)



include_directories(
  include/
)

add_executable(simulation_robot
  src/main.cpp
  src/world.cpp
  src/robot.cpp
  src/simulation.cpp
)
target_link_libraries (simulation_robot ${CMAKE_THREAD_LIBS_INIT})

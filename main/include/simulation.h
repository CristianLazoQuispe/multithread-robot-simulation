#ifndef SIMULATION_H
#define SIMULATION_H

#include "world.h"
#include "robot.h"
#include <thread>


class Simulation {

 public:
    Simulation(){};
    Simulation(World w);
    
    // save robots in my world
    bool addRobot(Robot robot1);
    // display simulation
    void run();
    // ** simulate movements **

    void run_threads(); // run all threads
    void close_threads(); // close all threads
    void run_thread_random_movement(Robot robot_aux); // make a single thread

 private:
    World w_;
    // list of robots in my world
    std::vector<Robot> my_robots; // dynamic vector of robots
    std::vector<std::thread> threads; // dynamic vector of threads of robots
};

#endif

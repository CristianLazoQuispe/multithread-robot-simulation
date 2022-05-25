#include "simulation.h"



Simulation::Simulation(World w){
    w_ = w;
}

bool Simulation::addRobot(Robot robot1) {
  // get features of robot
  int row = robot1.robot_x;
  int col = robot1.robot_y;
  const char* robot_color = robot1.robot_color;
  char name = robot1.robot_name;
  
  // check if position is available in map
  if(w_.map_[row][col]=='0'){
      // update map
      w_.map_[row][col] = name;
      std::cout<<"success creating robot"<<std::endl;

      // save color in dictionary because is more optimal to use in display
      w_.my_map_colors.insert({ name, robot_color });
      
      // add robot in our World
      my_robots.push_back(robot1);      
      return true;
  }
  else{
    std::cout<<"error creating robot"<<std::endl;
    return false;
  }

}

void Simulation::run_thread_random_movement(Robot robot_aux){
    while(true){
      // make a random movement 
      std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_ROBOT));
      bool success = robot_aux.random_movement(w_.map_);
    };

}


void Simulation::run_threads(){

  // This is a simulation of movements in real world

  for(int i=0;i<my_robots.size();i++){
      // simulate a random movements in a thread
      std::thread th1(&Simulation::run_thread_random_movement,this,my_robots[i]);
      threads.push_back(std::move(th1));
  }

}
void Simulation::close_threads(){

  for (std::thread & th : threads)
  {   
      // close threads
      if (th.joinable())
          th.join();
  }


}

void Simulation::run(){

  run_threads(); 

  while (true) {
    w_.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_DISPLAY));
  }
  close_threads();
}

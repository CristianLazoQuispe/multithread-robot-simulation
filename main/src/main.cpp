#include "simulation.h"
#include "iostream"


int main(int argc, char** argv) {
  // You should customize this data structure and the World constructor to
  // match your chosen data structure.

  bool success_robot=false;

  Variables my_variable;
  
  /// Create a world
  World w(my_variable.MAP);

  /// create robots with original position, color,and name
  Robot robot_1(1, 1,BOLDRED,'A');
  Robot robot_2(10, 10,BOLDGREEN,'B');
  Robot robot_3(2, 2,BOLDYELLOW,'C');
  Robot robot_4(6, 7,BOLDMAGENTA,'D');
  Robot robot_5(0, 0,BOLDCYAN,'E'); // is not available in the map

  Robot robot_6(17, 18,RED,'F');
  Robot robot_7(17, 10,YELLOW,'G');
  Robot robot_8(10, 15,GREEN,'H');
  Robot robot_9(5, 19,MAGENTA,'I');
  Robot robot_10(6, 19,CYAN,'J');
  
  
  
  //Simulation
  Simulation my_simulation(w);
  
  
  /// try to add a robot in my world
  success_robot = my_simulation.addRobot(robot_1);
  success_robot = my_simulation.addRobot(robot_2);
  success_robot = my_simulation.addRobot(robot_3);
  success_robot = my_simulation.addRobot(robot_4);
  success_robot = my_simulation.addRobot(robot_5); // is not available in the map

  success_robot = my_simulation.addRobot(robot_6);
  success_robot = my_simulation.addRobot(robot_7);
  success_robot = my_simulation.addRobot(robot_8);
  success_robot = my_simulation.addRobot(robot_9);
  success_robot = my_simulation.addRobot(robot_10); 

  // run multithread simulation
  my_simulation.run();
  
}

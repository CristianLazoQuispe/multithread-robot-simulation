#ifndef ROBOT_H
#define ROBOT_H

#include "variables.h"

// Define and implement the following class
class Robot {
 public:
  Robot(){};
  Robot(int x, int y, const char* color,char name);

  // features of robot
  int robot_x;
  int robot_y;
  const char*  robot_color;
  char robot_name;

  // movement of robot
  bool move(int x, int ,char map[W_WORLD][R_WORLD], int time);
  bool random_movement(char map[W_WORLD][R_WORLD]);

  // move robot in map
  bool is_available(int x, int y, char map[W_WORLD][R_WORLD] );

  // get random value in list
  int  get_random_value();
  
 private:
  
  // Holonomic movements x y 
  std::vector<std::vector<int>> movements{{-1,-1}, 
                                {-1, 0}, 
                                {-1, 1}, 
                                { 0, -1}, 
                                { 0, 0}, 
                                { 0, 1}, 
                                { 1, -1}, 
                                { 1, 0}, 
                                { 1, 1}
                                };
  };

#endif

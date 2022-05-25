#ifndef WORLD_H
#define WORLD_H
//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.

#include "variables.h"
#include <map>


// Define and implement the following class. Feel free to change the given
// interfaces and data structures to better match your design

class World {
 public:
    World(){}
    World(char map[W_WORLD][R_WORLD]);
    void display();
    
    //map
    char map_[W_WORLD][R_WORLD];
    // color dictionary initialization
    std::map<char, const char* > my_map_colors = {
        { '1', BLUE },
        { '0', WHITE }};
    
 private:


};

#endif

#include "world.h"


World::World(char map[][R_WORLD]) {
  // variable initialization
  for (int i = 0; i < W_WORLD; i++) {
    for (int j = 0; j < R_WORLD; j++) {
      map_[i][j] = map[i][j];
    }
  }
}


void World::display() {
  // "Clear" screen
  for (int i = 0; i < 20; i++)
    std::cout << std::endl;

  
  // title
  std::cout << RED << "Robo agents" << RESET << std::endl;

  for (int i = 0; i < W_WORLD; i++) {
    for (int j = 0; j < R_WORLD; j++) {
      // optimal display using a dictionary of colors 
      std::cout << my_map_colors[map_[i][j]] <<map_[i][j] << RESET;
    }
    std::cout << std::endl;
  }
}

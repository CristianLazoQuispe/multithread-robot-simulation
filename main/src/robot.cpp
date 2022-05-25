#include "robot.h"



Robot::Robot(int x, int y, const char* color,char name) {
    //variable initialization

    robot_x = x; //original position x
    robot_y = y; //original position y

    robot_color = color; // color of name
    robot_name = name;   // char name
}

int Robot::get_random_value(){

    // get random number in list
    std::vector<int> list{0,1,2,3,4,5,6,7,8}; // list of ids 
    int index = std::rand() % list.size(); // pick a random index
    int value = list[index]; //get random value in list
    return value;

}


bool Robot::random_movement(char map[W_WORLD][R_WORLD]){
    

    // choose random movement in list
    int id_movement = get_random_value();
    int x_move = movements[id_movement][0];
    int y_move = movements[id_movement][1];

    // change position of robot
    int x_new = robot_x+x_move;
    int y_new = robot_y+y_move;
    //std::cout<<"x "<<x_new<<"  y "<<y_new<<std::endl;

    // check is the new position is available    
    bool sucess = is_available(x_new,y_new, map);
    if(sucess){
        // update new postition to be restricted
        map[x_new][y_new] = robot_name;
        // update last position to be available
        map[robot_x][robot_y] = '0';
        // update original position
        robot_x = x_new;
        robot_y = y_new;
        
    }
    return sucess;

}

bool Robot::move(int x_move, int y_move, char map[W_WORLD][R_WORLD], int time){
    // make a movement
    int x_new = robot_x+x_move;
    int y_new = robot_y+y_move;
    //std::cout<<"x "<<x_new<<"  y "<<y_new<<std::endl;
    
    // check is the new position is available    
    bool sucess = is_available(x_new,y_new, map);
    if(sucess){
        // update new postition to be restricted
        map[x_new][y_new] = robot_name;
        // update last position to be available
        map[robot_x][robot_y] = '0';
        // update original position
        robot_x = x_new;
        robot_y = y_new;
    }
    return sucess;

}



bool Robot::is_available(int x, int y, char map[W_WORLD][R_WORLD]){

    //check is position is available in map
    if (map[x][y] =='0'){
        //std::cout<<"available"<<std::endl;
        return true;
    }
    else{
        //std::cout<<"is not available"<<std::endl;
        return false;
    }


}


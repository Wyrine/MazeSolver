//Author: Kirolos Shahat
//maze.cpp main
#include "proto.h"

using namespace std;

//the driver. Calls createMaze
int main(int argv, char *argc[]){
  createMaze();
}

//createMaze Creates a stacks instance and then calls enterMaze
void createMaze(){
  Stacks m;
  m.enterMaze();
  travMaze(m);
}

void travMaze(Stacks m){
  while(!m.solved()) m.goMoveDecision();
  cout << "Maze solved! Goodbye!\n";
}

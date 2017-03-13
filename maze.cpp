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
  //enterMaze(m.maze, m.rows, m.cols);
  m.enterMaze();
  travMaze(m);
}

void travMaze(Stacks m){
  while(!m.solved()){
    //this is to break infinite loop
    return;
  }
}

void makeMove(vector<string> maze, vector<Location> decisions, vector<Location> moves,
  Location m, bool pushDecisions){
  if(DOWN == ' ') {
    m.curRow++;
//    writeCurrentLocation(m, maze);
    moves.push_back(m);
    if(pushDecisions) decisions.push_back(m);
  }
  else if(LEFT == ' ') {
    m.curCol--;
//    writeCurrentLocation(m, maze);
    moves.push_back(m);
    if(pushDecisions) decisions.push_back(m);
  }
  else if(RIGHT == ' ') {
    m.curCol++;
//    writeCurrentLocation(m, maze);
    moves.push_back(m);
    if(pushDecisions) decisions.push_back(m);
  }
  else{
    m.curRow--;
//    writeCurrentLocation(m, maze);
    moves.push_back(m);
    if(pushDecisions) decisions.push_back(m);
  }
}

void traverseMaze(vector<string> maze, vector<Location> moves, vector<Location> decisions){
  bool fullSurroundings;
  Location m;
  while(true){
    fullSurroundings = false;
    m = moves.back();
    if(checkSurroundings(maze, m, fullSurroundings)){
      makeMove(maze, decisions, moves, m, true);
    }
    else if(fullSurroundings){
      rollBackDecisions(decisions, moves, maze);
    }
    else{
      makeMove(maze, decisions, moves, m);
    }
  }
}

//If there are no moves that can be made in the current Location
//then this pops back the deicison stack until the move and decisions
//are the same, aka there was a fork in the road, to try a new path.
//If there was no fork in the road then there is no solution and
//the program exits.
void rollBackDecisions(vector<Location> decisions,
  vector<Location> moves, vector<string> maze){
  if(decisions.size() <= 1){
    cout << "There is not a solution to this maze. Goodbye.\n";
    exit(0);
  }
  decisions.pop_back();
  Location m;
  //while the last decision doesn't match the last move made then
  //then pop back and rewrite the path with an x because it's not
  //a path that leads to a solution
  while((decisions.back() != moves.back()) && !moves.empty()){
    m = moves.back();
//    writeCurrentLocation(m, maze, 'x');
    moves.pop_back();
  }
}

//checks to see if there are any openings
bool checkSurroundings(vector<string> maze, Location m, bool& fullSurroundings){
  if(LEFT != ' ' && RIGHT != ' ' && DOWN != ' ' && UP != ' '){
    fullSurroundings = true;
    return false;
  }
  if((LEFT == ' ' || RIGHT == ' ' || DOWN == ' ') && UP == ' ') return true;
  else if((UP == ' ' || RIGHT == ' ' || DOWN == ' ') && LEFT == ' ') return true;
  else if((LEFT == ' ' || RIGHT == ' ' || UP == ' ') && DOWN == ' ') return true;
  else if((LEFT == ' ' || UP == ' ' || DOWN == ' ') && RIGHT == ' ') return true;
  return false;
}

//Author: Kirolos Shahat
//maze.cpp main
#include "proto.h"

using namespace std;

int main(int argv, char *argc[]){
  createMaze();
}

void createMaze(){
  Stacks m;
  //enterMaze(m.maze, m.rows, m.cols);
}

void enterMaze(vector<string> maze, const int rows, const int cols){
  Location m = {0, 1};
  vector<Location> moves, decisions;
  moves.push_back(m);
  writeCurrentLocation(moves.back(), maze);
  traverseMaze(maze, moves, decisions);
}

void writeCurrentLocation(Location m, vector<string>& maze, char z){
  maze[m.curRow][m.curCol] = z;
  printMaze(maze);
}

void printMaze(vector<string>& maze){
  for (vector<string>::iterator it = maze.begin(); it != maze.end(); it++){
    cout << *it << endl;
  }
}

void makeMove(vector<string> maze, vector<Location> decisions, vector<Location> moves,
  Location m, bool pushDecisions){
  if(DOWN == ' ') {
    m.curRow++;
    writeCurrentLocation(m, maze);
    moves.push_back(m);
    if(pushDecisions) decisions.push_back(m);
  }
  else if(LEFT == ' ') {
    m.curCol--;
    writeCurrentLocation(m, maze);
    moves.push_back(m);
    if(pushDecisions) decisions.push_back(m);
  }
  else if(RIGHT == ' ') {
    m.curCol++;
    writeCurrentLocation(m, maze);
    moves.push_back(m);
    if(pushDecisions) decisions.push_back(m);
  }
  else{
    m.curRow--;
    writeCurrentLocation(m, maze);
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

void rollBackDecisions(vector<Location> decisions, vector<Location> moves, vector<string> maze){
  if(decisions.empty()){
    cout << "There is not a solution to this maze. Goodbye.\n";
    exit(0);
  }
  decisions.pop_back();
  if(decisions.empty()){
    cout << "There is not a solution to this maze. Goodbye.\n";
    exit(0);
  }
  Location m;
  while(decisions.back() != moves.back()){
    m = moves.back();
    writeCurrentLocation(m, maze, 'x');
  }
}

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

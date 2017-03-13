#pragma once
#include "file.h"

struct Location{
  int curRow, curCol;
  bool operator !=(const Location& arg){
    return ((arg.curRow != curRow) || (arg.curCol != curCol)) ? true : false;
  }
};

class Stacks{
  Location exitLoc;
  void findExit();
public:
  vector<string> maze;
  vector<Location> decisions, moves;
  int rows, cols;
  Stacks();
  //initializing the starting location to 0,1
  void enterMaze();
  //If the last move made is not equal to the location of the exit
  //return false, otherwise return true
  bool solved(){ return (moves.back() != exitLoc) ? false: true; }
  void writeCurrentLocation(Location m, char path = '*');
  void printMaze();
  bool canGo(string direction);
  void quitMaze();
  int checkDirections(string ignoredDirec = "");
  bool goMove(string direction);
  //I think this function is useless
  bool goMoveDecision(string direction);
  void popToDecision();
};

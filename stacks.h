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
public:
  vector<string> maze;
  vector<Location> decisions, moves;
  int rows, cols;
  Stacks();
  void enterMaze();
  void findExit();
  bool solved();
  void writeCurrentLocation(Location m, char z = '*');
  void printMaze();
  bool canGo(string direction);
  bool goMove(string direction);
  bool goMoveDecision(string direction);
  void popToDecision();
};

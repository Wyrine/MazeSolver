#pragma once
#include "file.h"

//l = left
//d = down
//u = up
//r = right
//none = no path
enum Paths{l, d, u, r, none};

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
  void enterMaze();
  //If the last move made is not equal to the location of the exit
  //return false, otherwise return true
  bool solved(){ return (moves.back() != exitLoc) ? false: true; }
  void writeCurrentLocation(Location m, char mark = '*');
  void printMaze();
  bool canGo(Paths direction);
  void quitMaze();
  int checkDirections(Paths &validPath);
  void goMove(Paths direction, int numPaths);
  void goMoveDecision();
  void popToDecision();
};

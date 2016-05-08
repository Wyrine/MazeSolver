#include "stacks.h"

Stacks::Stacks(){
  OpenFile f;
  f.getRowCol(rows, cols);
  f.readMaze(maze, rows);
  findExit();
}

bool Stacks::solved(){
  return (moves.back() != exitLoc) ? false: true;
}

void Stacks::findExit(){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(i == 0 && j > 1)
        if(maze[i][j] == ' '){
          exitLoc.curRow = i;
          exitLoc.curCol = j;
          return;
        }
      if(i == rows-1)
        if(maze[i][j] == ' '){
          exitLoc.curRow = i;
          exitLoc.curCol = j;
          return;
        }
      if(j == 0 || j == cols -1)
        if(maze[i][j] == ' '){
          exitLoc.curRow = i;
          exitLoc.curCol = j;
          return;
        }
    }
  }
}

void Stacks::enterMaze(){
  Location m = {0, 1};
}

void Stacks::writeCurrentLocation(Location m, char z){
  maze[m.curRow][m.curCol] = z;
  printMaze();
}

void Stacks::printMaze(){
  for (vector<string>::iterator it = maze.begin(); it != maze.end(); it++){
    cout << *it << endl;
  }
}

bool Stacks::canGo(string direction){
  if(direction == "left")
    return (maze[moves.back().curRow][moves.back().curCol-1] == ' ') ? true : false;
  if(direction == "down")
    return (maze[moves.back().curRow+1][moves.back().curCol] == ' ') ? true : false;
  if(direction == "up")
    return (maze[moves.back().curRow-1][moves.back().curCol] == ' ') ? true : false;
  else
    return (maze[moves.back().curRow][moves.back().curCol+1] == ' ') ? true : false;
}

bool Stacks::goMove(string direction){
  if (direction == "left"){
    Location m = {moves.back().curRow, moves.back().curCol-1};
    writeCurrentLocation(m);
    moves.push_back(m);
    return solved();
  } else if (direction == "right"){
    Location m = {moves.back().curRow, moves.back().curCol+1};
    writeCurrentLocation(m);
    moves.push_back(m);
    return solved();
  } else if (direction == "down"){
    Location m = {moves.back().curRow+1, moves.back().curCol};
    writeCurrentLocation(m);
    moves.push_back(m);
    return solved();
  } else if (direction == "up"){
    Location m = {moves.back().curRow-1, moves.back().curCol};
    writeCurrentLocation(m);
    moves.push_back(m);
    return solved();
  } return false;
}

bool Stacks::goMoveDecision(string direction){
  bool returnBool = goMove(direction);
}
void Stacks::popToDecision(){

}

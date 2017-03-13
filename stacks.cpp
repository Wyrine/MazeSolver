#include "stacks.h"

//The base constructor which calls the OpenFile class to read the
//dimensions of the maze and the mazeitself
Stacks::Stacks(){
  //Instantiating the OpenFile class
  OpenFile f;
  //getting the dimensions of the maze
  f.getRowCol(rows, cols);
  //reading in the maze into the maze vector
  f.readMaze(maze, rows);
  //finding the opening on the edges of the maze
  findExit();
}

//initializing the start location and marking our current location
//in the maze
void Stacks::enterMaze(){
  Location m = {0, 1};
  moves.push_back(m);
  writeCurrentLocation(m);
}

void Stacks::quitMaze(){
  cout << "No solution found. Exiting.\n";
  exit(0);
}

//loops through the rows and columns and checks all of the borders for
//an open space. This assumes that all of the borders are characters
//and that there is only one exit because as soon as this finds an exit it
//stores it and exits
void Stacks::findExit(){
  //loop through the number of rows
  for(int i = 0; i < rows; i++){
    //loop through the number of columns
    for(int j = 0; j < cols; j++){
      if(maze[i][j] == ' '){
        exitLoc.curRow = i;
        exitLoc.curCol = j;
        //this if statement checks the first row past the entrance
        if((i == 0 && j > 1) || (i == rows-1) || (i > 0 && j == 0) || (j == cols -1)){
          cout << "Exit row: " << i << ". Exit column: " << j << ".\n";
          return;
        }
      }
    }
  }
  //if there are no exits on the boundaries then the program exits because
  //there is no solution
  quitMaze();
}

//this checks how many valid paths there are from the current Location
//and returns that count. If an string is passed as a parameter then it
//does not include that direction in the count
int Stacks::checkDirections(Paths ignoredDirec){
  Paths validDirecs[] = {LEFT, DOWN, UP, RIGHT};
  int validPaths = 0;
  for(int i=0; i < 4; i++)
    if(validDirecs[i] != ignoredDirec && canGo(validDirecs[i]))
      validPaths++;
  return validPaths;
}

//updates the current path of the maze and marks where
void Stacks::writeCurrentLocation(Location m, char path){
  maze[m.curRow][m.curCol] = path;
  printMaze();
}

//iterates through the vector and prints the current look of the maze
void Stacks::printMaze(){
  for (vector<string>::iterator it = maze.begin(); it != maze.end(); it++)
    cout << *it << endl;
}

//canGo takes a string parameter being either "left", "right", "down",
//or "up" and this checks to see if that direction is a Location
//that can be moved to, if so then it returns true, otherwise false
bool Stacks::canGo(Paths direction){
  int thisRow = moves.back().curRow;
  int thisCol = moves.back().curCol;
  switch (direction){
    case LEFT:
      return (maze[thisRow][thisCol-1] == ' ') ? true : false;
    case DOWN:
      return (maze[thisRow+1][thisCol] == ' ') ? true : false;
    case UP:
      return (maze[thisRow-1][thisCol] == ' ') ? true : false;
    case RIGHT:
      return (maze[thisRow][thisCol+1] == ' ') ? true : false;
    default:
      return false;
  }
}

//goMove moves the path of the direction string passed and returns the solved
//state of the maze, true if solved, false otherwise
bool Stacks::goMove(Paths direction){
  Location m = {moves.back().curRow, moves.back().curCol};
  switch (direction){
    case LEFT:
      m.curCol -= 1;
      writeCurrentLocation(m);
      moves.push_back(m);
      return solved();
    case DOWN:
      m.curCol += 1;
      writeCurrentLocation(m);
      moves.push_back(m);
      return solved();
    case UP:
      m.curRow += 1;
      writeCurrentLocation(m);
      moves.push_back(m);
      return solved();
    case RIGHT:
      m.curRow -= 1;
      writeCurrentLocation(m);
      moves.push_back(m);
      return solved();
    default:
      return false;
  }
}

bool Stacks::goMoveDecision(Paths direction){
  int numPaths = checkDirections(direction);
  if(numPaths > 0){
    return goMove(direction);
  }
  return false;
}

void Stacks::popToDecision(){
  do{
    if(moves.empty() || decisions.empty()) quitMaze();
    writeCurrentLocation(moves.back(), 'x');
    moves.pop_back();
  }while(decisions.back() != moves.back());
}

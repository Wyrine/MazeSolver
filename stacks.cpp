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

//If the last move made is not equal to the location of the exit
//return false, otherwise return true
bool Stacks::solved(){
  return (moves.back() != exitLoc) ? false: true;
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
  cout << "No exit found, Exiting.\n";
  exit(0);
}

void Stacks::writeCurrentLocation(Location m, char path){
  maze[m.curRow][m.curCol] = path;
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
  else if(direction == "down")
    return (maze[moves.back().curRow+1][moves.back().curCol] == ' ') ? true : false;
  else if(direction == "up")
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
  //bool returnBool = goMove(direction);
  return goMove(direction);
}
void Stacks::popToDecision(){

}

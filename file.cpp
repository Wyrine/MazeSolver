#include "file.h"

//Default constructor which asks the user for a file name and attempts
//to open that file, if the open fails then program exits
OpenFile::OpenFile(){
  string fileName;
  cout << "Please enter the name of the maze file: ";
  cin >> fileName;
  input.open(fileName.c_str());
  if(input.fail()) {
    cout << "File open failed, exiting." << endl;
    exit(0);
  }
}

//Reads in the dimensions of the maze and return them back by reference
void OpenFile::getRowCol(int& rows, int& cols){
  input >> rows >> cols;
  input.ignore(100, '\n');
}

//readMaze loads the maze into the maze vector that is passed by reference
//and prints the maze
void OpenFile::readMaze(vector<string> &maze, int rows){
  string curRow;
  //looping through the number of rows
  for (int i = 0; i < rows; i++){
    //if the number of rows doesn't match the actual dimensions of the maze
    //the loop breaks
    if(!getline(input, curRow)) break;
    //append the current row of the maze into the vector
    maze.push_back(curRow);
    //print the current dimensions of the maze
    cout << curRow << endl;
  }
}

#include "file.h"

OpenFile::OpenFile(){
  string fileName;
  cout << "Please enter the name of the maze file: ";
  cin >> fileName;
  input.open(fileName.c_str());
  if(!properOpen()) {
    cout << "File open failed, exiting." << endl;
    exit(0);
  }
}

void OpenFile::getRowCol(int& rows, int& cols){
  input >> rows >> cols;
  input.ignore(100, '\n');
}

void OpenFile::readMaze(vector<string> &maze, int rows){
  string temp;
  for (int i = 0; i < rows; i++){
    if(!getline(input, temp)) break;
    maze.push_back(temp);
    cout << temp << endl;
  }
}

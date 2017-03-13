#pragma once
//OpenFile class definition.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class OpenFile{
  ifstream input;
public:
  OpenFile();
  //Destructor closes the file
  ~OpenFile() { input.close(); };
  void getRowCol(int& rows, int& cols);
  void readMaze(vector<string> &maze, int rows);
};

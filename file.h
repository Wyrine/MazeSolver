#pragma once
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
  ~OpenFile() { input.close(); };
  bool properOpen() { return input.fail() ? false : true; };
  void getRowCol(int& rows, int& cols);
  void readMaze(vector<string> &maze, int rows);
};

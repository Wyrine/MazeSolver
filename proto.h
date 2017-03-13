#pragma once
#include "stacks.h"

#define LEFT maze[m.curRow][m.curCol-1]
#define RIGHT maze[m.curRow][m.curCol+1]
#define UP maze[m.curRow-1][m.curCol]
#define DOWN maze[m.curRow+1][m.curCol]

void createMaze();
void travMaze(Stacks m);
void traverseMaze(vector<string> maze, vector<Location> moves,
  vector<Location> decision);
bool checkSurroundings(vector<string> maze, Location m, bool& fullSurroundings);
void makeMove(vector<string> maze, vector<Location> decisions, vector<Location> moves,
  Location m, bool pushDecisions = false);
void rollBackDecisions(vector<Location> decisions, vector<Location >moves, vector<string> maze);

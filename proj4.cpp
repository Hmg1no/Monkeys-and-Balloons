/***********************************************************
 ** File:    Game.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hazael Magino
 ** Date     4/16/2023
 ** Section: 12
 ** This file contains the header file of the Game class
 **********************************************************/


#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
  srand (time(NULL));
  Game g;
  g.StartGame();
  return 0;
}

/***********************************************************
 ** File:    Bomb.h
 ** Project: CMSC 202 - Project 4
 ** Author:  Hazael Magino
 ** Date     3/31/2023
 ** Section: N/A
 ** This file contains the header file of the Bomb class
 **********************************************************/

// Do NOT edit this file


#ifndef BOMB_H_
#define BOMB_H_

#include "Monkey.h"
#include "Bloon.h"
#include <vector>
using namespace std;

//Launches a powerful bomb at the Bloons.
//It uses heavy bombs which deal area damage and naturally pop Lead Bloons.

class Bomb: public Monkey {
 public:
  // Name: Bomb() - Default Constructor
  // Description: Creates a new Bomb Monkey
  // Preconditions: None
  // Postconditions: Can create a Bomb Monkey
  Bomb();
  // Name: Bomb(string type, int damage, int location)
  // Description: Creates a new Bomb Monkey
  // Preconditions: None
  // Postconditions: Can create a Bomb Monkey
  Bomb(string, int, int);
  // Name: ~Bomb - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Bomb();
  // Name: Attack
  // Description: Iterates through all bloons. Hits all bloons in same location as bomb.
  //              Returns total bloon health or damage (whichever is less) for earnings (money)
  //              EXTRA CREDIT: Only monkey that can pop Lead Bloons.
  // Preconditions: Bloons must be in same location as bomb monkey
  // Postconditions: Damages each bloon and returns earnings (total pops)
  int Attack(vector<Bloon*>);
};
#endif

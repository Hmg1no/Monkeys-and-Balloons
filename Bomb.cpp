/***********************************************************
 ** File:    Bomb.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hazael Magino
 ** Date     4/14/2023
 ** Section: 12
 ** This file contains the neccesary implementation of the Bomb class
 **********************************************************/

#include "Bomb.h"

#include <iostream>

#include <fstream>

#include <iomanip>

#include <vector>

#include <cstdlib>

#include <time.h>

#include <cmath>

#include <string>

#include <iomanip>


// Name: Bomb() - Default Constructor
// Description: Creates a new Bomb Monkey
// Preconditions: None
// Postconditions: Can create a Bomb Monkey
Bomb::Bomb() {

  //Default constructor..never used

}
// Name: Bomb(string type, int damage, int location)
// Description: Creates a new Bomb Monkey
// Preconditions: None
// Postconditions: Can create a Bomb Monkey

// Constructor for Bomb class which sets the type, damage and location of the monkey using the constructor of Monkey class.
Bomb::Bomb(string type, int damage, int location): Monkey(type, damage, location) {}

// Name: ~Bomb - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated

//Child destructor...never used. No dynamical memory used in this class
Bomb::~Bomb() {}

// Name: Attack
// Description: Iterates through all bloons. Hits all bloons in same location as bomb.
//              Returns total bloon health or damage (whichever is less) for earnings (money)
//              EXTRA CREDIT: Only monkey that can pop Lead Bloons.
// Preconditions: Bloons must be in same location as bomb monkey
// Postconditions: Damages each bloon and returns earnings (total pops)

int Bomb::Attack(vector < Bloon * > balloons) {

  //initalize and declare a variable to store pops
  int pops = 0;

  for (unsigned int i = 0; i < balloons.size(); i++) {

    // Check if the bloon is at the same location as the bomb monkey
    if (balloons.at(i) -> GetLocation() == GetLocation() - 1) {

      // Check if the bloon is still alive
      if (balloons.at(i) -> GetHealth() > 0) {

        // print a message that the Bomb monkey throws a Bomb
        cout << "The bomb monkey launches a bomb" << endl;

        // Pop the bloon and increment the number of pops
        pops = pops + balloons.at(i) -> Pop(GetDamage());

      }

    }

  }

  //return pops for money
  return pops;

}
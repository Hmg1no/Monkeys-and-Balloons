/***********************************************************
 ** File:    Boomerang.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hazael Magino
 ** Date     4/14/2023
 ** Section: 12
 ** This file contains the neccesary implementation of the Boomerang class
 **********************************************************/

#include "Boomerang.h"

#include <iostream>

#include <fstream>

#include <iomanip>

#include <vector>

#include <cstdlib>

#include <time.h>

#include <cmath>

#include <string>

#include <iomanip>


// Name: Boomerang() - Default Constructor
// Description: Creates a new Boomerang Monkey
// Preconditions: None
// Postconditions: Can create a Boomerang Monkey

Boomerang::Boomerang() {

  //Default constructor..never used

}

// Name: Boomerang(string type, int damage, int location)
// Description: Creates a new Boomerang Monkey
// Preconditions: None
// Postconditions: Can create a Boomerang Monkey

Boomerang::Boomerang(string type, int damage, int location): Monkey(type, damage, location) {

  // Constructor for Bomb class which sets the type, damage and location of the monkey using the constructor of Monkey class.

}

// Name: ~Boomerang - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated

Boomerang::~Boomerang() {

  //Child destructor...never used. No dynamical memory used in this class

}

// Name: Attack
// Description: Iterates through all bloons. For each bloon in the same location as boomerang,
//              hits each bloon twice (once out and once back)
//              Returns total bloon health or damage (whichever is less) for earnings (money)
// Preconditions: Bloons must be in same location as Boomerang Monkey
// Postconditions: Damages each bloon and returns earnings (total pops)

int Boomerang::Attack(vector < Bloon * > balloons) {

  int pops = 0;

  // loop through all the balloons
  for (unsigned int i = 0; i < balloons.size(); i++) {

    // check if the current balloon is at the same location as the Boomerang monkey
    if (balloons.at(i) -> GetLocation() == GetLocation() - 1) {

      // check if the current balloon still has health left
      if (balloons.at(i) -> GetHealth() > 0) {

        // print a message that the Boomerang monkey throws a boomerang
        cout << "The boomerang monkey throws a boomerang! " << endl;

        // calculate the damage and pop the balloon(boomerang hits twice)
        pops += balloons.at(i) -> Pop(GetDamage());

      }

    }
  }

  for (unsigned int i = 0; i < balloons.size(); i++) {

    // check if the current balloon is at the same location as the Boomerang monkey
    if (balloons.at(i) -> GetLocation() == GetLocation() - 1) {

      // check if the current balloon still has health left
      if (balloons.at(i) -> GetHealth() > 0) {

        // calculate the damage and pop the balloon(boomerang hits twice)
        pops += balloons.at(i) -> Pop(GetDamage());

      }

    }
  }

  // return the total number of balloons popped
  return pops;
}
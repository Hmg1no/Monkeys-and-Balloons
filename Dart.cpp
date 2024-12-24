/***********************************************************
 ** File:    Dart.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hazael Magino
 ** Date     4/14/2023
 ** Section: 12
 ** This file contains the neccesary implementation of the Dart class
 **********************************************************/

#include "Dart.h"

#include <iostream>

#include <fstream>

#include <iomanip>

#include <vector>

#include <cstdlib>

#include <time.h>

#include <cmath>

#include <string>

#include <iomanip>


// Name: Dart() - Default Constructor
// Description: Creates a new Dart Monkey
// Preconditions: None
// Postconditions: Can create a Dart Monkey

Dart::Dart() {

  //Default constructor..never used

}

// Name: Dart(string type, int damage, int location)
// Description: Creates a new Dart Monkey
// Preconditions: None
// Postconditions: Can create a Dart Monkey

Dart::Dart(string type, int damage, int location): Monkey(type, damage, location) {

  // Constructor for Dart class which sets the type, damage and location of the monkey using the constructor of Monkey class.

}

// Name: ~Dart - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated

Dart::~Dart() {

  //Child destructor...never used. No dynamical memory used in this class

}

// Name: Attack
// Description: Iterates through all bloons. Hits first bloon in the same location as dart.
//              Returns total bloon health or damage (whichever is less) for earnings (money)
// Preconditions: Bloon must be in same location as Dart monkey
// Postconditions: Damages one bloon and returns earnings (total pops)

int Dart::Attack(vector < Bloon * > balloons) {

  // Initialize a variable to keep track of the number of pops.
  int pops = 0;

  // Iterate over the balloons vector.
  for (unsigned int i = 0; i < balloons.size(); i++) {

    // Check if the health of the balloon is greater than or equal to 0.
    if (balloons.at(i) -> GetHealth() > 0) {

      //Make sure that the location of the bloon mathches the monkey
      if (balloons.at(i) -> GetLocation() == GetLocation() - 1) {

        // Print a message to indicate that the dart monkey has thrown a dart.
        cout << " The dart monkey throws a dart! " << endl;

        // Call the Pop() function of the balloon to reduce its health by the dart's damage.
        pops = balloons.at(i) -> Pop(GetDamage());

        // Return the number of pops.
        return pops;

      }
    }
  }

  return 0;
}
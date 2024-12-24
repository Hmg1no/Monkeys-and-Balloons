/***********************************************************
 ** File:    Basic.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hazael Magino
 ** Date     4/18/2023
 ** Section: 12
 ** This file contains the neccesary implementation of the Basic class
 **********************************************************/

#include <iostream>

#include <fstream>

#include <iomanip>

#include <vector>

#include <cstdlib>

#include <time.h>

#include <cmath>

#include <string>

#include <iomanip>

#include "Basic.h"

using namespace std;

// Name: Basic() - Default Constructor
// Description: Creates a new Basic Bloon
// Preconditions: None
// Postconditions: Can create a Basic Bloon

Basic::Basic() {

  //Default constructor...dont use this

}

// Name: Basic(int health, int location)
// Description: Creates a new basic bloon with health at a specific location
// if health = 1, red, 2=blue, 3=green, 4=yellow, 5=pink, >=6=black
// Preconditions: None
// Postconditions: Can create a basic bloon

Basic::Basic(int health, int location): Bloon(health, location) {

  // Check if the health of the Basic object minus one matches for colors of bloons (red, blue, green, yellow, pink).
  if (GetHealth() - 1 == red) {

    // If the health matches red, set the m_color  to "Red".
    m_color = "Red";

  } else if (GetHealth() - 1 == blue) {

    // If the health matches blue, set the m_color  to "Blue".
    m_color = "Blue";

  } else if (GetHealth() - 1 == green) {

    // If the health matches green, set the m_color  to "Green".
    m_color = "Green";

  } else if (GetHealth() - 1 == yellow) {

    // If the health matches yellow, set the m_color  to "Yellow".
    m_color = "Yellow";

  } else if (GetHealth() - 1 == pink) {

    // If the health matches pink, set the m_color  to "Pink".
    m_color = "Pink";

  } else if (GetHealth() - 1 >= black) {

    // If the health does not match any values, set the m_color  to "Black".
    m_color = "Black";
  }
}

// Name: ~Basic - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated

Basic::~Basic() {

  // Empty destructor, since it is a virtual destructor.
  
}

// Name: Pop
// Description: Changes the color of the bloon based on how many health it has left
// red = 1, blue = 2, green = 3, yellow = 4, pink = 5, black >=6
// Preconditions: None
// Postconditions: Returns number of pops that occurred.
// Number of pops is the lesser of (health left of bloon) or (damage caused by monkey).

int Basic::Pop(int damage) {

  cout << "The " << m_color << " bloon pops" << endl;

  //The inital amount of health the bloon had
  int origin = GetHealth();

  // Calculate the health offset based on the damage inflicted
  int OffSetH = origin - damage;

  //Unique cases to check for: Is it dead(health 0) otherwise get the offset health 
  if (OffSetH <= 0) {

    SetHealth(0);

  } else {

    SetHealth(OffSetH);
  }

  // Check if the bloon is still alive and update its properties
  if (GetHealth() >= 6) {

    // Set the color to black
    m_color = "black";

  } else if (GetHealth() == 1) {

    //Set color to red
    m_color = "red";

  } else if (GetHealth() == 2) {

    //Set color to blue
    m_color = "blue";

  } else if (GetHealth() == 3) {

    //Set color to green
    m_color = "green";

  } else if (GetHealth() == 4) {

    //Set color to yellow
    m_color = "yellow";

  } else if (GetHealth() == 5) {

    //Otherwise bloon must have a health of 5 and be pink

    m_color = "pink";
  }

  if (origin <= damage) {

    cout << "The bloon is now gone " << endl;

    return origin;

  } else {

    cout << "The bloon is now " << m_color << endl;

    return damage;
  }

  return 0;

}

// Name: GetColor()
// Description: Returns the current color of a bloon
// Preconditions: None
// Postconditions: None

string Basic::GetColor() {

  // Returns color for specified bloon

  return m_color;

}
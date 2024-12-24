/***********************************************************
 ** File:    Bloon.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hazael Magino
 ** Date     4/14/2023
 ** Section: 12
 ** This file contains the neccesary implementation of the Bloon class
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

#include "Bloon.h"

using namespace std;

// Name: Bloon() - Default Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes (may not be specifically used)

Bloon::Bloon() {

  //default cconstruct

  m_health = 0;

  m_location = 0;

}

// Name: Bloon(int health, int location) - Overloaded Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes

Bloon::Bloon(int health, int location) {

  //overloaded constructor

  m_health = health;

  m_location = location;

}

// Name: virtual ~Bloon - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated

Bloon::~Bloon() {

  //virutal destructor...no dynamically allocated memory here

}

// Name: GetHealth()
// Description: Returns health of bloon
// Preconditions: Bloon has health
// Postconditions: None

int Bloon::GetHealth() {

  //return necessary health for the bloon

  return m_health;

}

// Name: SetHealth()
// Description: Sets health of bloon
// Preconditions: None
// Postconditions: Health is set

void Bloon::SetHealth(int health) {

  //set necessary health for the bloon

  m_health = health;

}

// Name: GetLocation()
// Description: Returns location of bloon
// Preconditions: Bloon has location
// Postconditions: None

int Bloon::GetLocation() {

  //get neccesary location for bloon

  return m_location;

}

// Name: SetLocation()
// Description: Sets location of bloon
// Preconditions: None
// Postconditions: Location is set

void Bloon::SetLocation(int location) {

  //set neccesary location for the bloon

  m_location = location;

}

// Name: Overloaded <<
// Description: Prints the details of an bloon
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of bloon

ostream & operator << (ostream & output, Bloon & bloon) {

  //Whenever m_monkeys.at(i) is called this overloaded operator is called to return color and health

  output << "Bloon: " << bloon.GetColor() << " Health: " << bloon.GetHealth() << endl;

  return output;
}
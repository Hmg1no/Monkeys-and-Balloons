/***********************************************************
 ** File:    Monkey.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  HazaeL Magino
 ** Date     4/14/2023
 ** Section: N/A
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

#include "Monkey.h"


using namespace std;

// Name: Monkey() - Default Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes (may not be specifically used)

Monkey::Monkey() {}

// Name: Monkey(string type, int damage, int location) - Overloaded Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes

Monkey::Monkey(string type, int damage, int location) {

  //set passed in values to member variables
  m_type = type;

  m_damage = damage;

  m_location = location;
}

// Name: virtual ~Monkey - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated

Monkey::~Monkey() {

  //Never called. No dynamic memory in this class

}

// Name: GetDamage()
// Description: Returns damage of monkey
// Preconditions: Monkey has damage defined
// Postconditions: None

int Monkey::GetDamage() {

  //Return private member variable value 

  return m_damage;
}

// Name: GetType()
// Description: Returns types of monkey
// Preconditions: Monkey has a type defined
// Postconditions: None

string Monkey::GetType() {

  //Return private member variable value 
  return m_type;
}

// Name: GetLocation()
// Description: Returns location of monkey on track
// Preconditions: Monkey is on the track
// Postconditions: None

int Monkey::GetLocation() {

  //Return private member variable value 
  return m_location;
}

// Name: SetDamage()
// Description: Sets damage of monkey
// Preconditions: None
// Postconditions: Damage is set

void Monkey::SetDamage(int damage) {

  //Set private member variable a value
  m_damage = damage;
}

// Name: SetType()
// Description: Sets type of monkey (dart, bomb, or boomerang)
// Preconditions: None
// Postconditions: Type is set

void Monkey::SetType(string type) {

  //Set private member variable a value
  m_type = type;
}

// Name: SetLocation()
// Description: Sets location of monkey on track
// Preconditions: None
// Postconditions: Type is set

void Monkey::SetLocation(int location) {

  //Set private member variable a value
  m_location = location;
}

// Name: Overloaded <<
// Description: Prints the details of a monkey
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of monkey

ostream & operator << (ostream & output, Monkey & monkey) {

  //output the monkey type, location, and damage return that output 
  output << monkey.GetType() << " Monkey: " << "Location: " << monkey.GetLocation() << " Damage: " << monkey.GetDamage() << endl;

  return output;

}
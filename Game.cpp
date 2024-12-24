/***********************************************************
 ** File:    Game.cpp
 ** Project: CMSC 202 - Project 4
 ** Author:  Hazael Magino
 ** Date     4/16/2023
 ** Section: 12
 ** This file contains the header file of the Game class
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

#include "Game.h"

using namespace std;

// Name: Game() - Default Constructor
// Description: Creates a new Game and populates money, round, and health
// Preconditions: None
// Postconditions: Initializes all game variables to defaults (constants)
// including rounds played

Game::Game() {

  //set private variables to pre-established constants
  m_curMoney = START_MONEY;

  m_curLife = START_LIFE;

  //Beginning round
  m_curRound = START_ROUND;

}

// Name: ~Game
// Description: Destructor
// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated in Game

Game::~Game() {

  // Free the memory allocated for bloons
  for (unsigned int i = 0; i < m_bloons.size(); i++) {

    delete m_bloons.at(i);

  }

  // Free the memory allocated for monkeys
  for (unsigned int m = 0; m < m_monkeys.size(); m++) {

    delete m_monkeys.at(m);

  }

}

// Name: StartGame()
// Description: Welcomes the player to the game. Continually calls MainMenu until user quits
// Preconditions: None
// Postconditions: Thanks user when quitting

void Game::StartGame() {

  // Constants for exiting the game and initial state
  int
  const EXIT = 6;

  int state = 0;

  // Display welcome message
  cout << "Welcome to UMBC Bloons!" << endl;

  // Continue running the game until the player chooses to exit or runs out of life
  do {

    state = MainMenu();

  } while ((state != EXIT) && (m_curLife > 0));

  // Check the final state to determine whether the player won or lost
  if (state == EXIT) {

    cout << "Thanks for playing!" << endl;

  } else {

    cout << "Sorry you lost the game..." << endl;
    cout << "Thanks for playing!" << endl;
  }

}

// Name: MainMenu()
// Description: Checks to see if player still has life. If m_curLife <= 0, game ends with loss.
//              Display menu (View Map, Buy New Monkey, Improve Existing Monkey
//              Progress Round, Check Stats, or Quit).
//              Calls function related to user choice.
// Preconditions: None
// Postconditions: Game continues until quit or player runs out of life

int Game::MainMenu() {

  //variables for return output
  int choice = 0;
  int EXIT = 6;

  // Displaying menu options

  cout << "What would you like to do? " << endl;

  cout << "1. View Map\n" << endl;

  cout << "2. Buy New Monkey\n" << endl;

  cout << "3. Improve Existing Monkey\n" << endl;

  cout << "4. Progress Round\n" << endl;

  cout << "5. Check Stats\n" << endl;

  cout << "6. Quit\n" << endl;

  //Reading user choice from input

  cin >> choice;

  //Switch statement to determine which functions calls to make

  switch (choice) {

  case 1:

    //Allows the player to view current map
    PrintMap();
    break;

  case 2:

    //Allows the player to buy a monkey
    BuyMonkey();
    break;

  case 3:

    //Allows the player to improve existing monkey
    ImproveMonkey();
    break;

  case 4:

    //Allows the player to play a round of BTD
    PlayRound();
    break;

  case 5:

    //States current state of the game for the player
    Stats();
    break;

  case 6:

    //Allows the user to exit
    break;

  default:
    cout << "Invalid input. Please select something on the main menu" << endl;

  }

  // Return cases for do while in start game
  if (choice == EXIT) {

    return EXIT;

  } else if (m_curLife <= 0) {

    return 0;

  } else {

    return 0;
  }

}

  // Name: PrintMap()
  // Description: For each location on the path, outputs the bloons and the monkeys (or none)
  // Precondition: None
  // Postcondition: None

void Game::PrintMap() {

  // iterate over each path location
  for (int x = 0; x < PATH_LENGTH; x++) {

    // print the monkeys at the location
    cout << "\n**Location: " << x + 1 << "**" << endl;

    cout << "--Monkeys--" << endl;

    //flag for if there are monkeys
    bool has_monkeys = false;

    int monk_Count = 0;

    //iterate over each monkey 
    for (unsigned int m = 0; m < m_monkeys.size(); m++) {

      // if monkey is at current location
      if (x == m_monkeys.at(m) -> GetLocation() - 1) {

        monk_Count++;

        //print the monkey (overloaded operator)
        cout << monk_Count << ". " << * m_monkeys.at(m) << endl;

        has_monkeys = true;
      }
    }

    //if there are no monkeys at the location
    if (!has_monkeys) {

      //Change the state to prevent none from printing out
      cout << "None" << endl;
    }

    //print the bloons at the location
    cout << "<<Bloons>>" << endl;

    //If there are no bloons in the current location
    bool has_bloons = false;

    //iterate over each bloon
    for (unsigned int b = 0; b < m_bloons.size(); b++) {

      //if bloon is at current location
      if (x == m_bloons.at(b) -> GetLocation()) {

        //print the bloon
        cout << * m_bloons.at(b) << endl;

        //Change the state to prevent none from printing out
        has_bloons = true;
      }

    }

    //If there are no bloons at the location
    if (!has_bloons) {

      cout << "None" << endl;

    }
  }
}

// Name: BuyMonkey
// Description: Asks the user which monkey they would like to buy
//            Reduces m_curMoney and then calls PlaceMonkey (which creates and places new monkey)
// Precondition: Must have enough money to pay (COST_DART, COST_BOOMERANG, or COST_BOMB)
// Postcondition: Specified monkey is added a chosen location on the path

void Game::BuyMonkey() {

  //intaialize and declare user choice variable
  int choice = 0;

  //do while to keep iterating over the menu for choosing a monkey
  do {

    cout << "What type of monkey would you like to buy? " << endl;

    cout << "1. Dart Monkey" << endl;

    cout << "2. Boomerang Monkey" << endl;

    cout << "3. Bomb Monkey" << endl;

    cout << "4. Cancel" << endl;

    cin >> choice;

  } while ((choice <= 0) || (choice >= 5));

  //Switch case based off user input to create a certain monkeys
  switch (choice) {

  case 1: // Dart Monkey

    //validation if you can buy money
    if (m_curMoney >= COST_DART) {

      PlaceMonkey(choice);

      //Decrease the amount of money after
      m_curMoney = m_curMoney - COST_DART;

    } else {

      cout << "You don't have enough money to buy this monkey!" << endl;
      return;
    }

    break;

  case 2: // Boomerang Monkey

    if (m_curMoney >= COST_BOOMERANG) {

      PlaceMonkey(choice);

      m_curMoney = m_curMoney - COST_BOOMERANG;

    } else {

      cout << "You don't have enough money to buy this monkey!" << endl;

      return;
    }
    break;

  case 3: // Bomb Monkey 

    if (m_curMoney >= COST_BOMB) {

      PlaceMonkey(choice);
      m_curMoney = m_curMoney - COST_BOMB;

    } else {

      cout << "You don't have enough money to buy this monkey!" << endl;
      return;
    }
    break;

    //Cancel case
  default:

    break;

  }

}

// Name: ImproveMonkey
// Description: Asks the user which monkey they would like to improve
//              Increases chosen monkey's damage by IMPROVE_VALUE above
// Precondition: Must have monkeys in m_monkeys and have enough money to pay (COST_IMPROVE)
// Postcondition: Monkey's damage is permanently improved

void Game::ImproveMonkey() {

  //intialize and declare user varaible
  int mkChoice = 0;

  //First validate if there is enough money to spend
  if (m_curMoney > COST_IMPROVE) {

    //Validate if there are any monkeys to improve
    if (m_monkeys.size() > 0) {

      //Do-while to keep running while the user doesn't input within 1 and monkey vector size
      do {

        cout << "Which monkey would you like to improve? (1-" << m_monkeys.size() << ")" << endl;

        //for loop to iterate over the whole monkey vector
        for (unsigned int m = 0; m < m_monkeys.size(); m++) {

          //Print avaliable monkeys
          cout << m + 1 << ". " << * m_monkeys.at(m) << endl;

        }

        //Read in user input
        cin >> mkChoice;

      } while ((mkChoice < 1) || (mkChoice > int(m_monkeys.size())));

      //Change damage of user input damage
      m_monkeys.at(mkChoice - 1) -> SetDamage(m_monkeys.at(mkChoice - 1) -> GetDamage() + IMPROVE_VALUE);

      //Decrement the money available
      m_curMoney = m_curMoney - COST_IMPROVE;

      //Print out which monkey was improved 
      cout << m_monkeys.at(mkChoice - 1) -> GetType() << " Monkey in position " << mkChoice << " improved! " << endl;

      //If there are no monkeys in the vector to spend
    } else {

      cout << "You have no monkeys to improve" << endl;

      return;

    }

    //If there is not enough money to spend
  } else {

    cout << "You do not have enough money to improve a monkey" << endl;

    return;

  }

}

// Name: PlayRound()
// Description: Announces beginning and end of round
//              Calls PopulateBloons once then ResolveBattle once.
//              Calls RemovePopped (5 times due to erase function)
//              Calls MoveBloons once then calls CheckPath (5 times due to erase call)
//              Increments curRound
// Preconditions: None
// Postconditions: Round progresses

void Game::PlayRound() {
  // Constant to iterate 5 times for RemovePopped and CheckPath
  const int CALL = 5;

  // State the beginning of the round
  cout << "Beginning of round " << m_curRound << endl;

  // Create new balloons
  PopulateBloons();

  // Monkeys attack bloon vector
  ResolveBattle();

  // Remove popped bloons
  for (int y = 0; y < CALL; y++) {
    RemovePopped();
  }

  // Move bloons
  MoveBloons();

  // Check path to see if bloons are past bloon length
  for (int x = 0; x < CALL; x++) {
    CheckPath();
  }

  // Print completed round
  cout << "Round " << m_curRound << " Completed" << endl;

  // Increment current round for the next
  m_curRound++;
}

// Name: Stats()
// Description: Displays the information about the game
//              (current round, number of monkeys, money, and lives left)
// Preconditions: None
// Postconditions: None

void Game::Stats() {

  //Display stats
  cout << "**Current Stats** " << endl;

  //Display current round 
  cout << "Current Round: " << m_curRound << endl;

  //Display the amount of monkeys in the vector
  cout << "Monkeys Working: " << m_monkeys.size() << endl;

  //Display the current amount of money that the player has
  cout << "Current Money: " << m_curMoney << endl;

  //Display the the playable lives the player has
  cout << "Current Life: " << m_curLife << endl;

}

// Name: PopulateBloons
// Description: Each round, dynamically allocated bloons added to path in position START_BLOON
//              Bloons have a minimum of 1 health.
//              For each round, the number of new bloons increases matching the round number
//              For example: Round 1 = 1 red bloon (health 1)
//              Round 2 = 1 red bloon (health 1) and 1 blue bloon (health 2)
//              Round 3 = 1 red (health 1) and 1 blue (health 2) and 1 green (health 3)
//              Round 4 = 1 red, 1 blue, 1 green, and 1 yellow (health 4) and so forth
//              Notifies user that a new bloon (with color) has appeared.
// Preconditions: Round is at least 1
// Postconditions: All new bloons populated

void Game::PopulateBloons() {

  //Create a new bloon object
  Bloon * newBloon;

  //iterate the amount of rounds to decide the health of the balloon
  for (int i = 0; i < m_curRound; i++) {

    newBloon = new Basic(i + 1, START_BLOON);

    //put the bloon in the bloon vector
    m_bloons.push_back(newBloon);

    //Print the statement of which bloon colored has been created
    cout << "A new " << newBloon -> GetColor() << " bloon appears! " << endl;

  }

}

// Name: ResolveBattle()
// Description: Each monkey attacks the whole bloon vector.
//              For each pop, curMoney is increased.
// Preconditions: Monkeys and bloons exist
// Postconditions: Damage is dealt to bloons

void Game::ResolveBattle() {

  // Initialize and declare a new int money variable
  int monkeyMoney = 0;

  // Iterate through the monkey vector
  for (unsigned int m = 0; m < m_monkeys.size(); m++) {

    // Call the Attack function on the current monkey and add the money earned to monkeyMoney
    monkeyMoney += m_monkeys.at(m) -> Attack(m_bloons);

  }

  // Add the total amount of money earned by the monkey in this battle to the game's current money
  m_curMoney += monkeyMoney;

}

// Name: RemovePopped()
// Description: Iterates through m_bloons and if health is <= 0, bloon is deallocated and
//              removed from m_bloons
//         HINT: m_bloons.erase(m_bloons.begin() + counter) will erase at location
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons are removed

void Game::RemovePopped() {

  // Iterate through the m_bloons vector
  for (unsigned int i = 0; i < m_bloons.size(); i++) {

    // Check if the bloon's health is less than or equal to zero
    if (m_bloons.at(i) -> GetHealth() <= 0) {

      // Delete the bloon object from memory
      delete m_bloons.at(i);

      // Erase the bloon object from the vector
      m_bloons.erase(m_bloons.begin() + i);
    }

  }

}

// Name: MoveBloons
// Description: For each bloon that still lives, it moves one location down the path
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons increment their location

void Game::MoveBloons() {

  // Iterate through the m_bloons vector
  for (unsigned int b = 0; b < m_bloons.size(); b++) {

    // Move the bloon along the track by increasing its location by 1
    m_bloons.at(b) -> SetLocation(m_bloons.at(b) -> GetLocation() + 1);

  }

  cout << "The bloon moves along the path" << endl;

}

// Name: CheckPath
// Description: Iterates over m_bloons to see if location is equal to (or greater than)
//              PATH_LENGTH. If location is equal to PATH_LENGTH, causes damage to player.
//              Damage to player is one per health of bloon.
//              If 10 green bloons (health 3) hit player, player takes 30 damage
//              Bloons that hurt player are deallocated and erased from m_bloons
//              HINT: m_bloons.erase(m_bloons.begin() + counter) will erase at location
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons are removed

void Game::CheckPath() {

  // Initialize variables to keep track of damage and the bloon counter
  int damage = 0;

  // Loop through the m_bloons vector
  for (unsigned int i = 0; i < m_bloons.size(); i++) {

    // Check if the bloon's location is at or past the end of the path
    if (m_bloons.at(i) -> GetLocation() >= PATH_LENGTH) {

      // If so, add its health to the damage counter
      damage += m_bloons.at(i) -> GetHealth();

      //deallocate memory for the object
      delete m_bloons.at(i);

      // Remove the bloon from the m_bloons vector
      m_bloons.erase(m_bloons.begin() + i);

    }

  }

  // Update the player's current life by subtracting the damage dealt by bloons
  m_curLife -= damage;

  // If any damage was dealt, print a message indicating that bloons have moved along the path
  if (damage > 0) {

    cout << "A bloon made it to the end of the path and you took " << damage << " damage." << endl;
  }

}

// Name: PlaceMonkey(int choice)
// Description: Based on monkey purchased in BuyMonkey, asks user where to place new monkey
//              Dynamically allocates new monkey and populates location and adds to m_monkey
// Preconditions: Successfully purchased new monkey
// Postconditions: New monkey is added to m_monkey at chosen location

void Game::PlaceMonkey(int choice) {

  int placement = 0;

  // Loop until a valid placement location is selected
  do {
    cout << "Where would you like to place the new monkey? (1-" << PATH_LENGTH << ")" << endl;

    cin >> placement;

  } while (placement <= 0 || placement > PATH_LENGTH);

  Monkey * newMonkey;

  // Create a new monkey based on the player's choice
  switch (choice) {

  case 1: // Dart Monkey

    newMonkey = new Dart("Dart", DAMAGE_DART, placement);

    cout << "New Dart monkey placed in location " << placement << endl;

    break;

  case 2: // Boomerang Monkey

    newMonkey = new Boomerang("Boomerang", DAMAGE_BOOM, placement);

    cout << "New Boomerang monkey placed in location " << placement << endl;

    break;

  case 3: // Bomb Monkey

    newMonkey = new Bomb("Bomb", DAMAGE_BOMB, placement);

    cout << "New Bomb monkey placed in location " << placement << endl;

    break;

  default: //case never called but created

    cout << "Error creating a new Monkey" << endl;

    break;
  }

  // Add the new monkey to the vector of monkeys
  m_monkeys.push_back(newMonkey);
}
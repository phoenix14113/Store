/*************************************************************************
 *
 * Project 2: Store
 *
 * File Name:   Store.cpp
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 *
 * Difficult to understand
 *
 * Contains all the function declaratoins for the class Store. Contains
 * functions for reading files, interpreting data, printing the menu and
 * returning data that the user may ask for.
 *
 */
#include "Store.h"
#include "Brand.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;
void Store::readFile() {
  fstream fin;
  fin.open("Inventory.txt");

  // checks if file opened propperly
  if (!fin) {

    std::cerr << "Unable to open file poem.txt";
    exit(1);
  }

  // runs commands if the file isn't at the end
  cout << "Reading file." << endl;

  while (!fin.eof()) {

    // store entire line of the file
    string temp;
    getline(fin, temp);

    // variables for separating the line
    string IDInput;
    string BrandInput;
    string DescriptionInput;

    int breakCounter = 0;
    // checks each line for a tab
    for (int i = 0; i < temp.size(); i++) {
      // separates the first section at the first tab
      if (temp.at(i) != '\t' && breakCounter == 0) {
        IDInput.push_back(temp.at(i));
      }
      // separates the second section at the second tab
      if (temp.at(i) != '\t' && breakCounter == 1) {
        BrandInput.push_back(temp.at(i));
      }
      // separates the third section at the third tab
      if ((temp.at(i) != '\t' || temp.at(i) != '\n') && breakCounter == 2) {
        DescriptionInput.push_back(temp.at(i));
      } else if (temp.at(i) == '\t') {
        breakCounter++;
      }
    }

    // adds the line into the Store vector
    addNewItem(IDInput, BrandInput, DescriptionInput);
  }
  fin.close();
  cout << "Finished Reading File" << endl;
}

void Store::addNewItem(string ID, string Brand_Name, string Description) {
  bool isEverEqual = false;
  // runs throught the vector to make sure that there isn't a duplicate brand.
  for (int i = 0; i < Inventory.size(); i++) {
    if (Inventory.at(i)->getBrandName() == Brand_Name) {
      // if there's a duplicate the products information is added to that brand.
      Inventory.at(i)->newProduct(ID, Description);
      isEverEqual = true;
    }
  }
  if (!isEverEqual) {
    // if it is a unique brand it creates a new spot in the Inventory
    Inventory.push_back(new Brand(Brand_Name, ID, Description));
  }
}

int Store::storeMenu(int input) const {
  while (true) {
    int userOption;
    // HUD
    cout << endl << endl << endl << endl << endl << endl;
    cout << "List of possible options:" << endl << endl;

    cout << "1: Search for brands by first letter or print all possible brands."
         << endl;
    cout << "2: Find all specific products produced by a brand." << endl;
    cout << "3: Find what product and brand are associated with a " << endl
         << "   particular UPC code." << endl;
    cout << "4: Find all UPC codes associated with a product." << endl;
    cout << "5: Find all the brands that make a specific product." << endl;
    cout << "6: Exit out of program." << endl;

    cout << endl << "Enter the number of the option you would like: ";

    // for testing
    if (input != 0) {
      userOption = input;
    } else {
      // main program
      cin >> userOption;
    }
    cout << endl;
    // check valid input
    if (cin.fail() || userOption > 6 || userOption < 1) {
      cin.clear();
      cin.ignore(100, '\n');
      cerr << "You did not input a valid option number. Try again." << endl;
      continue;
    };
    return userOption;
  }
}

void Store::printEndl() {
  // prints endlines
  for (int i = 0; i < 20; i++) {
    cout << endl;
  }
}

void Store::displayBrands(char input) const {
  // collect user input
  string userInput;
  cout << "Search for companies all companies with a given first letter"
       << endl;
  cout << "or type \"All\" to output all brand names." << endl;
  bool correctInput;
  // error checking
  do {
    correctInput = true;
    cout << "Please enter a letter: ";
    // for testing purposes
    if (input != '|') {
      userInput = input;
    } else {
      // main program
      cin >> userInput;
    }
    userInput.at(0) = toupper(userInput.at(0));

    if (userInput.size() > 1 && !(userInput == "All")) {
      cin.clear();
      cin.ignore(100, '\n');
      cerr << "That is not \"All\" or a valid letter. Try again." << endl
           << endl;
      correctInput = false;
    }

  } while (!correctInput);

  cout << endl << "These are the brands that this store holds:" << endl << endl;
  // find all brand names in Inventory with a starting letter
  int numEntries = 0;
  if (userInput.size() == 1) {
    for (int i = 1; i < Inventory.size() - 1; i++) {
      if (Inventory.at(i)->getBrandName().at(0) == userInput.at(0)) {
        cout << '\t' << Inventory.at(i)->getBrandName() << endl;
        numEntries++;
      }
    }
    // if none are found
    if (numEntries == 0) {
      cout << '\t' << "There are none." << endl;
    }
  }
  // output all
  if (userInput == "All") {
    for (int i = 1; i < Inventory.size(); i++) {
      cout << '\t' << Inventory.at(i)->getBrandName() << endl;
    }
  }

  cout << endl;
  string HUDReturn;
  // wait until the user actually wants to return to the menu
  cout << "Enter anything to return to the HUD: ";
  cin >> HUDReturn;
}

void Store::displayBrandProducts(string input) const {
  // collect user info
  string userLookUp;
  cout << "What brand would you like to look up: ";
  cin.clear();
  cin.ignore(100, '\n');
  // for testing purposes
  if (input != "blank") {
    userLookUp = input;
  } else {
    // main program
    getline(cin, userLookUp);
  }

  // search vector for user's input
  bool foundUserLookUp = false;
  for (int i = 1; i < Inventory.size(); i++) {
    if (Inventory.at(i)->getBrandName() == userLookUp) {
      foundUserLookUp = true;

      cout << endl << userLookUp << " has these products:" << endl << endl;
      for (int j = 0; j < Inventory.at(i)->Products.size(); j++) {
        // collects all UPC codes and product names from Inventory
        cout << '\t' << Inventory.at(i)->Products.at(j).getID() << '\t'
             << Inventory.at(i)->Products.at(j).getDescription() << endl;
      }
      break;
    }
  }
  // message if the user input is not found in the vector
  if (!foundUserLookUp) {
    cout << endl << "The company you entered has no products." << endl;
  }
  cout << endl;
  string HUDReturn;
  // wait until the user actually wants to return to the menu
  cout << "Enter anything to return to the HUD: ";
  cin >> HUDReturn;
}

void Store::displayUPCInformation(string input) const {
  // collect user info
  string userLookUp;
  cout << "What UPC would you like to look up: ";
  cin.clear();
  cin.ignore(100, '\n');
  // for testing purposess
  if (input != "0") {
    userLookUp = input;
  } else {
    // main program
    getline(cin, userLookUp);
  }

  cout << endl << endl;

  // search vector for user's input
  bool foundUserLookUp = false;
  for (int i = 1; i < Inventory.size(); i++) {
    for (int j = 0; j < Inventory.at(i)->Products.size(); j++) {
      // collects all UPC codes and product names from Inventory
      if (Inventory.at(i)->Products.at(j).getID() == userLookUp) {
        foundUserLookUp = true;
        cout << "\tThe brand is: " << Inventory.at(i)->getBrandName() << endl;
        cout << "\tThe product is: "
             << Inventory.at(i)->Products.at(j).getDescription() << endl;
      }
    }
  }
  // message if user input is not found in the vector
  if (!foundUserLookUp) {
    cout << endl << "The UPC you entered doesn't exist." << endl;
  }
  cout << endl;
  string HUDReturn;
  // wait until the user actually wants to return to the menu
  cout << "Enter anything to return to the HUD: ";
  cin >> HUDReturn;
}

void Store::displayProductUPCS(string input) const {
  string userLookUp;
  cout << "What Product would you like to look up: ";
  cin.clear();
  cin.ignore(100, '\n');
  // for testing purposess
  if (input != "blank") {
    userLookUp = input;
  } else {
    // main program
    getline(cin, userLookUp);
  }
  cout << endl << endl;

  // search vector for user's input
  bool foundUserLookUp = false;

  for (int i = 1; i < Inventory.size(); i++) {
    for (int j = 0; j < Inventory.at(i)->Products.size(); j++) {
      // collects all UPC codes and product names from Inventory
      if (Inventory.at(i)->Products.at(j).getDescription() == userLookUp) {
        foundUserLookUp = true;
        cout << "\tUPC code: " << Inventory.at(i)->Products.at(j).getID()
             << endl;
      }
    }
  }
  // message if user input is not found in the vector
  if (!foundUserLookUp) {
    cout << endl << "The Product you entered doesn't exist." << endl;
  }
  cout << endl;
  string HUDReturn;
  // wait until the user actually wants to return to the menu
  cout << "Enter anything to return to the HUD: ";
  cin >> HUDReturn;
}

void Store::displayProductBrands(string input) const {
  string userLookUp;
  cout << "What Product would you like to look up: ";
  cin.clear();
  cin.ignore(100, '\n');
  // for testing purposes
  if (input != "blank") {
    userLookUp = input;
  } else {
    // main program
    getline(cin, userLookUp);
  }
  cout << endl << endl;
  // search vector for user's input
  bool foundUserLookUp = false;

  for (int i = 1; i < Inventory.size(); i++) {
    for (int j = 0; j < Inventory.at(i)->Products.size(); j++) {
      // collects all UPC codes and product names from Inventory
      if (Inventory.at(i)->Products.at(j).getDescription() == userLookUp) {
        foundUserLookUp = true;
        cout << "\tBrand name: " << Inventory.at(i)->getBrandName() << endl;
      }
    }
  }
  // message if user input is not found in the vector
  if (!foundUserLookUp) {
    cout << endl << "The Product you entered doesn't exist." << endl;
  }
  cout << endl << endl;
  string HUDReturn;
  // wait until the user actually wants to return to the menu
  cout << "Enter anything to return to the HUD: ";
  cin >> HUDReturn;
}
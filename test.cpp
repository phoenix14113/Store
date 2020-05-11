/*************************************************************************
 *
 * Project 2: Store
 *
 * File Name:   main.cpp
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 *
 * easy to understand
 *
 * this file contains test that prove that the class Store works as intended and
 * returns the values that the user actually want. It also outputs what values
 * are being tested.
 *
 */

#include "Store.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  Store newStore;
  newStore.readFile();

  int executeCommands = 0;
  // automated tests
  while (true) {
    // for testing
    executeCommands++;

    // display options to the consol and ask user to choose the an option
    // test each function in order from first to quitting
    int choice = newStore.storeMenu(executeCommands);

    // process user choice
    switch (choice) {
    case 1:
      newStore.printEndl();
      cout << "using '1' as input" << endl;
      cout << "Scroll up to see menu printed" << endl << endl;
      // find all brand names starting with a particular character
      newStore.displayBrands('1');
      newStore.printEndl();
      break;

    case 2:
      newStore.printEndl();
      cout << "using \"Wrench\" as input" << endl;
      cout << "Scroll up to see menu printed" << endl << endl;
      // find all products from a particular company
      newStore.displayBrandProducts("Wrench");
      newStore.printEndl();
      break;

    case 3:
      newStore.printEndl();
      cout << "using \"093709300403\" as input" << endl;
      cout << "Scroll up to see menu printed" << endl << endl;
      // display all information assosiated with a given UPC code
      newStore.displayUPCInformation("093709300403");
      newStore.printEndl();
      break;

    case 4:
      newStore.printEndl();
      cout << "using \"Pork Chops Bone-in Center Cut\" as input" << endl;
      cout << "Scroll up to see menu printed" << endl << endl;
      // display all UPC's with a given product name
      newStore.displayProductUPCS("Pork Chops Bone-in Center Cut");
      newStore.printEndl();
      break;

    case 5:
      newStore.printEndl();
      cout << "using \"Pork Chops Bone-in Center Cut\" as input" << endl;
      cout << "Scroll up to see menu printed" << endl << endl;
      // display all companyies that make each product that has this given
      // product name
      newStore.displayProductBrands("Pork Chops Bone-in Center Cut");
      newStore.printEndl();
      break;

    case 6:
      newStore.printEndl();
      cout << "\tScroll up to see menu printed" << endl;
      cout << "\tThank you for using my store program. Come again." << endl
           << endl;
      break;
    }
    // exit full loop
    if (choice == 6) {
      break;
    }
  }

  // determine if the user wants to run their own tests
  char continueProgram;
  bool validEntry = true;
  do {

    cout << "\tWould you like to run your own tests" << endl;
    cout << "\tor would you like to end the program?" << endl;
    cout << "\ttype 'y' to continue the program or" << endl;
    cout << "\tanything other character to break: ";
    cin >> continueProgram;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(100, '\n');
      cerr << "That is not a valid entry";
      validEntry = false;
    }
  } while (!validEntry);
}
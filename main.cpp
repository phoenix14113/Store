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

  while (true) {

    // display options to the consol and ask user to choose the an option
    // test each function in order from first to quitting
    int choice = newStore.storeMenu();

    // process user choice
    switch (choice) {
    case 1:
      newStore.printEndl();
      // find all brand names starting with a particular character
      newStore.displayBrands();
      newStore.printEndl();
      break;

    case 2:
      newStore.printEndl();
      // find all products from a particular company
      newStore.displayBrandProducts();
      newStore.printEndl();
      break;

    case 3:
      newStore.printEndl();
      // display all information assosiated with a given UPC code
      newStore.displayUPCInformation();
      newStore.printEndl();
      break;

    case 4:
      newStore.printEndl();
      // display all UPC's with a given product name
      newStore.displayProductUPCS();
      newStore.printEndl();
      break;

    case 5:
      newStore.printEndl();
      // display all companyies that make each product that has this given
      // product name
      newStore.displayProductBrands();
      newStore.printEndl();
      break;

    case 6:
      newStore.printEndl();
      cout << "\tThank you for using my store program. Come again." << endl
           << endl;
      break;
    }
    // exit full loop
    if (choice == 6) {
      break;
    }
  }
}
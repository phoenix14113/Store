/*************************************************************************
 *
 * Project 2: Store
 *
 * File Name:   Store.h
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 *
 * Fairly easy to understand
 *
 * This file contains all of the function definitions and the class declaration
 * for Store. It also initializes the vector that stores all data in the file
 * Inventory.txt
 *
 */

#include "Brand.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>

#ifndef STORE_H
#define STORE_H

using namespace std;

// all default arguments in functions are for testing

class Store {

private:
  // Stores pointers to what each brand makes
  vector<Brand *> Inventory;

public:
  // reads file into the vectory Inventory
  void readFile();
  // adds a new item to the vector Inventory
  void addNewItem(string, string, string);

  // print the menu
  int storeMenu(int input = 0) const;

  // adds a lot of end lines so that the main is no longer vissible
  // for convenience
  void printEndl();

  // Displays all brands stored in the vector Inventory
  void displayBrands(char input = '|') const;

  // Display all products made by a certain brand
  void displayBrandProducts(string input = "blank") const;

  // Display associated brand and product name given a UPC code
  void displayUPCInformation(string input = "0") const;

  // Display all associated UPC codes to a given product
  void displayProductUPCS(string input = "blank") const;

  // Display each Brands that make a product with a particular name
  void displayProductBrands(string input = "blank") const;
};
#endif
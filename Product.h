/*************************************************************************
 *
 * Project 2: Store
 *
 * File Name:   Product.h
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 *
 * easy to understand
 *
 * This file contains all of the class definitions for the class Product. It
 * creates variables that store some of the data from Inventory.txt. It allows
 * for retrieval of items from the containers
 *
 */
#include <iostream>
#include <string>
#include <utility>

#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product {
private:
  pair<string, string> Item;

public:
  Product(string ID, string Description);
  string getID() const { return Item.first; }
  string getDescription() const { return Item.second; }
};

#endif
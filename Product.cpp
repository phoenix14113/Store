/*************************************************************************
 *
 * Project 2: Store
 *
 * File Name:   Product.cpp
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 *
 * easy to understand
 *
 * This file contains all of the class declarations for the class Product. It
 * stores some of the data from Inventory.txt.
 *
 */
#include "Product.h"
#include "utility"
using namespace std;

Product::Product(string ID, string Description) {
  Item.first = ID;
  Item.second = Description;
}
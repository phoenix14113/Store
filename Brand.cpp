/*************************************************************************
 *
 * Project 2: Store
 *
 * File Name:   Brand.cpp
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 *
 * Fairly easy to understand
 *
 * contains all class declarations for the class Brand. Adds and retrieves data
 * from the vector Inventory. Also creates another container for storing more
 * information from file Inventory.txt.
 *
 */
#include "Brand.h"
#include "Product.h"
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

Brand::Brand(string Brand_Name, string ID, string Description) {
  this->Brand_Name = Brand_Name;
  Product newProduct(ID, Description);
  Products.push_back(newProduct);
}
void Brand::newProduct(string ID, string Description) {
  Product newProduct(ID, Description);
  Products.push_back(newProduct);
}
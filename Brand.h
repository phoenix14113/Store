/*************************************************************************
 *
 * Project 2: Store
 *
 * File Name:   Brand.h
 * Username:  	taylad, Adam Taylor
 * Course:      CPTR 142
 *
 *
 * Fairly easy to understand
 *
 * This file contains the class definition for Brand. It creates variables for
 * the storage of the information in Inventory.txt. It al
 *
 */

#include "Product.h"
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#ifndef BRAND_H
#define BRAND_H

using namespace std;

class Brand {
public:
  // stores the products that each brand has
  vector<Product> Products;

  // initiallizes a brand with its product
  Brand(string, string, string);

  // retrieves brand name
  string getBrandName() const { return Brand_Name; }

  // adds a new product to the company
  void newProduct(string, string);

private:
  string Brand_Name;
};

#endif
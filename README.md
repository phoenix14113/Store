# CPTR 142: Project #2

## Problem Overview

UPC codes are commonly used to uniquely identify a specific product.
I've provided Inventory.txt, based on [this](https://www.grocery.com/open-grocery-database-project/) list of brands and products.

In this assignment you will create a Store with Brands and Products.
In the end you will want to be able to answer these questions:

* Brand: 
  * What is your name?
  * What are your products?
* Product:
  * What is your name?
  * What is your Brand?
  * What is your UPC?
* Store: 
  * What are your Brands?
  * Given a brand name, what is the Brand?
  * What are your Products?
  * Given a UPC, what is the Product?
  * Given a product name, what are the Products?

## Solution Specifications

* Implement the public member functions for these three classes: Store, Brand, and Product.
* You should have at least seven files, two each for the classes named above (the provided .h files and your own .cpp files), plus main.cpp with tests.
* Using dynamically allocated Brand and Product objects, you should have only one instance of each Brand (with a pointer shared by all references) and only one instance of each Product (with a pointer shared by all references).
* Implement a function to answer each of the questions in the problem overview.
* Write test driver main that demonstrates each of the questions in the problem overview.
  * You do not need to create a UI for this project; tests that demonstrate the above queries are sufficient.

## Hints

Use the hints provided here to complete this project:

* Start simple and build up to the full project.
  * Write main() with a "Hello world!" output
  * Add the header files for each class
  * Use class [forward declarations](https://www.geeksforgeeks.org/what-are-forward-declarations-in-c/) to get the class headers to recognize each other. 
* Get a working main quickly.
  * Make the edits needed to get it to compile.
  * Add a failing test, such as `assert(false);` to main() and ensure that the program compiles and the error is properly reported.
* Start by testing each class individually
  * Create a Brand with code like `Brand brand("Riceland");` and get it to compile and run.
  * Add a test like `assert(brand.getName() == "Riceland");` and get it to compile and run.
  * Convert the code to use pointers (and use pointers in all that follows).
  * Create a Product and test its public accessor functions.
* Continue to build out your store and list of products.
  * Add a Store and in the default constructor read the products file (search zyBooks for "file input").
    When reading the file consider a three-argument version of `getline()` to read up to the '\t' or '\n' delimiters.
  * Write tests for one of the Store functions, and then write the code to satisfy the test.
  * Complete the tests and code for the Store functions.
* Finally, think about the Brand functions.
  * To handle Store::getBrandByName() are you creating a new Brand or do you have a container with Brands?
  * If you keep a container of Brands you could, while reading the Products, add each Product to its Brand.
  * Then, when you ask the Store for a Brand and then ask the Brand for its Products, it would have them.
  * What type of container would be good for a name lookup (key-value)?
  * You should have about 9000 Brands and about 110,000 Products.
* Working with pointers.
  * Instead of collections of objects, you will have collections of pointers to objects.
  * Operations previously performed on objects will need to use the dereferenced pointer.
  * Take care to avoid creating duplicate objects that are not referenced (memory leaks).

## Code Review

Before you can turn in your project, you must participate in a [code review](https://en.wikipedia.org/wiki/Code_review) with your TA or with the SDC tutor.
This [walk-through](https://en.wikipedia.org/wiki/) style review is a guided-tour of your source code in which you describe how you implemented the various features, explain why you made the choices you did, and solicit constructive input which might help improve your final product.

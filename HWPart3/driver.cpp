/*
 * driver.cpp
 *
 *  Created on: Sep 19, 2017
 *      User: jclay
 *		Author: Jacob Claytor
 */


#include <iostream>
#include "collection.h"

using namespace std;

int main()
{
	// This code takes a few seconds to run because of my while loop in the removeRandom() method.
	// It was the only way I could think to make it work without changing the size of the array.
	Collection<int> myArray(1);
	myArray.isEmpty();
	myArray.insert(23);
	myArray.insert(12);
	myArray.insert(34);
	myArray.isEmpty();
	myArray.insert(55);
	myArray.insert(56);
	myArray.remove(34);
	myArray.remove(13);
	myArray.removeRandom();
	myArray.notContained(23);
	myArray.notContained(12);
	myArray.notContained(109);
	myArray.makeEmpty();
	myArray.isEmpty();
	myArray.insert(22);
	myArray.insert(45);
	myArray.insert(26);
	myArray.insert(78);
	myArray.insert(99);
	myArray.removeRandom();
	myArray.removeRandom();
	myArray.removeRandom();
	myArray.removeRandom();
	myArray.removeRandom();
	myArray.removeRandom();
	myArray.isEmpty();


	return 0;
}





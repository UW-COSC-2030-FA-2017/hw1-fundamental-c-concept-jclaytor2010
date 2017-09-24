/*
 * collection.h
 *
 *  Created on: Sep 17, 2017
 *      User: jclay
 *		Author: Jacob Claytor
 */

#ifndef COLLECTION_H_
#define COLLECTION_H_

#include <time.h>
#include <iostream>
using namespace std;

template <class T>
class Collection
{
private:
	int size;
	T * array;
	int objectCounter = 0;

public:
	// Initialize array with size x.
	Collection(int x)
	{
		size = x;
		cout << "Array with size " << size << " successfully created." << endl;
		array = new T[size];
	};

	//Destructor
	~Collection()
	{
		delete[] array;
		cout << "Array deleted." << endl;
	};

	// Checks to see if objectCounter is 0. If so, then array is empty and returns true.
	// Else it returns false as array is not empty.
	bool isEmpty()
	{
		if(objectCounter == 0)
		{
			cout << "This array is empty." << endl;
			return true;
		}
		else
		{
			cout << "This array is not empty." << endl;
		}
		return false;
	};

	// Sets all values to 0 indicating empty values.
	// Prints empty array to show empty values, and sets objectCounter to 0.
	void makeEmpty()
	{
		for(int i = 0; i < size; i++)
		{
			array[i] = 0;
		}
		objectCounter = 0;
		cout << "This array was made empty." << endl;
		printArray();
	};

	// Inserts value.
	// If array is already full, then array is copied over to a new array with larger size.
	void insert(T object)
	{
		if(objectCounter == size)
		{
			size = size + 1;
			T * localArray = new T[size];
			for(int i = 0; i < size - 1; i++)
			{
				localArray[i] = array[i];
			}
			localArray[objectCounter] = object;
			delete[] array;
			array = localArray;
			cout << "\nObject " << object << " inserted successfully." << endl;
			cout << "Array was full so size is now: " << size << endl;
			printArray();
		}
		else
		{
			array[objectCounter] = object;
			cout << "\nObject " << object << " inserted successfully." << endl;
			cout << "\nPrinting updated array:" << endl;
			for(int j = 0; j < size; j++)
			{
				cout << "| " << array[j] << " |";
			}
			cout << endl;
		}
		objectCounter++;
	};

	// Removes designated object.
	// Moves elements down so that new object is always inserted at back of array.
	void remove(T object)
	{
		bool found = false;
		int indexFound;
		for(int j = 0; j < size; j++)
		{
			if(array[j] == object)
			{
				indexFound = j;
				found = true;
			}
		}
		if(found == true)
		{
			for(int i = indexFound; i < size - 1; i++)
			{
				array[i] = array[i+1];
			}
			array[size - 1] = 0;
			objectCounter--;
			cout << "\nObject " << object << " deleted successfully." << endl;
			printArray();
		}
		else
		{
			cout << "Object " << object << " not found in this array." << endl;
		}
	};

	// Removes a random element based on random index value.
	// I had to include the "time.h" file because
	// I kept getting the same random number when I ran without.
	// Also checked for random element being equal to 0. If it was I got a new random number
	// so it will still work if elements have already been deleted.

	void removeRandom()
	{
		if(objectCounter == 0)
		{
			cout << "Cannot remove random item. Array is empty." << endl;
		}
		else
		{
			int num;
			srand(time(NULL));
			num = rand() % size;

			while(array[num] == 0)
			{
				srand(time(NULL));
				num = rand() % size;
			}
			cout << "\nRandom object " << array[num] << " successfully deleted." << endl;
			if(num == size - 1)
			{
				array[size - 1] = 0;
			}
			else
			{
				for(int i = num; i < size - 1; i++)
				{
					array[i] = array[i+1];
				}
				array[size -1] = 0;
			}
			objectCounter--;
			printArray();
		}
	};

	// Returns true if value is not contained.
	// Returns false if value is contained.
	bool notContained(T object)
	{
		for(int i = 0; i < size; i++)
		{
			if(object == array[i])
			{
				cout << object << " is contained in this array." << endl;
				return false;
			}
		}
		cout << object << " is not contained in this array." << endl;
		return true;
	};

	// Extra function just to check that my array worked properly when being manipulated.
	void printArray()
	{
		cout << "\nPrinting updated array:" << endl;
		for(int j = 0; j < size; j++)
		{
			cout << "| " << array[j] << " |";
		}
		cout << endl << endl;
	};


};



#endif

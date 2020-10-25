//Valeria Benetti
//October 12, 2020
//Chapter 9: Array Expander

#include <iostream>
#include <fstream>

using namespace std;

// creating const variable to be called in both functions
const int SIZE = 10;
int* expandedArray(int* arr);

int main()
{
	int arr[SIZE];
	cout << "Original array" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = i;
		cout << arr[i] << " ";
	}
	cout << " \nExpanded Array: " << endl;
	int* newArr = expandedArray(arr);
	for (int i = 0; i < 2 * SIZE; i++)
	{

		cout << newArr[i] << " ";
	}
	delete[] newArr;

	return 0;
}

// Creating a function outside of the main function
int * expandedArray(int *arr)
{
	// Defining the new array that is double the length of the original
	int* doubledArr = new int[2 * SIZE];

	// Creating a loop for the 2xSize
	for (int i = 0; i < 2 * SIZE; i++)
	{
		// Creating a validation to make sure that it need to be larger than the copy
		if (i < SIZE)
		{
			doubledArr[i] = arr[i];
		}
		// Check is SIZE is  smaller than i, then we copy 0 into the array
		else
		{
			doubledArr[i] = 0;
		}
	}
	// Return Pointer
	return doubledArr;
}








/*
write a function that accepts an int array and the array's size as arguments. 
The function should create a new array that is twice the size of the argument array. 
the function should copy the contents of the argument array to the new array and initialize the unused elements of the second array with 0. 
The function should return a pointer to the new array.
*/

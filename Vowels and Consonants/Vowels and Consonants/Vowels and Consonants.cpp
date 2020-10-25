/*
General Notes that I will now always add to my projects so I don't go back and forth:

REQUIREMENTS TO TURN:
For each programming assignment you will include comments at the start of your code:


//Valeria Benetti

//October 13, 2020 © (the current date and alt+0169 on the number pad to get © Windows; Option G Mac)

//Chapter 10 Assignment

If using a version of Visual Studio prior to 2019, make sure you follow the Visual Studio Startup word document directions. You must include a system("pause"); in your code if you are using a PC (not a Mac). Visual Studio 2019 does not require this statement.
You should NOT have # include stdfax; in your code. If you do, you have NOT created an empty project.
You must include a collaboration statement in the message box of the drop box. Collaboration means whoever or wherever you received help with your code, even if it was only the text book.
This is worth 5 of your overall 40 points for programming assignments. 
If you have used the Internet, you need to specify the URL where you received help. 
Failure to do so will result in an Academic Integrity violation.
Any output that is representing money must be formatted to look like US currency. 
You will lose 5 points if it is not. Chapter 2 has a section on formatting output. Include your last name in filenames.
You will be submitting only the *.cpp file to the drop box.
*/


#include <iostream>
#include <cstring>


using namespace std;

// Writing some function prototypes
int vowelCount(char* str);
int consCount(char* str);
bool isNotSpecialChar(char str);

int main()
{
	// Declaring the variables 
	int numVowels, numConsonants;
	// Making max char size to 100
	char inputStr[100];
	char userChoice, type[2];


	// Ask user to read the options and choose a string
	cout << "Enter a string: \n";
	cin.getline(inputStr, 100);
	do
	{
		// Menu Prompt
		cout << "Menu Options: \n";
		cout << "A. Count the number of number of Vowels in the string" << endl;
		cout << "B. Count the number of Consonants in the string" << endl;
		cout << "C. Count both the Vowels and Consonants in the string" << endl;
		cout << "D. Enter another string" << endl;
		cout << "E. Exit the program" << endl;

		// Prompt the user to choose from the list above
		cout << "Enter your choice (A/B/C/D/E). You can you either caps or lowercase: ";
		cin.getline(type, 2);
		userChoice = type[0];

		//Making a switch statement
		switch (userChoice)
		{
		// For Option A/a
		case 'A':
		case 'a':
			// Call the vowelCount function
			numVowels = vowelCount(inputStr);

			// Display the vowel count
			cout << "The number of vowels in this string is: " << numVowels << endl;
			break;
		
		// For Option B/b
		case 'B':
		case 'b':
			// Call the consCount function
			numConsonants = consCount(inputStr);

			// Display the consonant count
			cout << "The number of consonants in this string is: " << numConsonants << endl;
			break;

		// For Option C/c
		case 'C':
		case 'c':
			// Call the vowelCount function
			numVowels = vowelCount(inputStr);

			// Call the consCount function
			numConsonants = consCount(inputStr);

			// Display both counts
			cout << "The number of vowels in this string is: " << numVowels << endl;
			cout << "The number of consonants in this string is: " << numConsonants << endl;
			break;

		case 'D':
		case 'd':
			// Prompt the user to put another string in
			cout << "Enter another string: ";
			cin.getline(inputStr, 100);
			break;

		// For option E/e
		case 'E':
		case 'e':
			//Close the program
			cout << "Good Bye!" << endl;
			exit(0);
			break;

		// Adding an note in case the use a letter that is not listed
		default:
			cout << "Choice not valid. Please Choose from options below:" << endl;
		}
	} while (userChoice != 'E' || 'e');
	 
	return 0;
}

// vowlCount Function/Method
int vowelCount(char *x) 
{
	// Creating a placement so we start at 0
	int countVowels = 0;

	// Making a while loop
	while (*x != '\0')
	{
		if (*x == 'a' || *x == 'A' || *x == 'E' ||
			*x == 'e' || *x == 'i' || *x == 'I' ||
			*x == 'o' || *x == 'O' || *x == 'u'
			|| *x == 'U')
			countVowels++;
		x++;
	}

	// Return count
	return countVowels;
}

// consCount Function/Method
int consCount(char* y)
{
	// Creating aplace me so we start a 0
	int countConsonants = 0;

	// Making another while loop for the consosnats. So anything that ISNT the above letters
	while (*y != '\0')
	{
		//Checks for consonants
		if (*y != 'a' && *y != 'A' && *y != 'E' &&
			*y != 'e' && *y != 'i' && *y != 'I' &&
			*y != 'o' && *y != 'O' && *y != 'u'
			&& *y != 'U' && isNotSpecialChar(*y))
			countConsonants++;
		y++;
	}
	return countConsonants;
}

// notSpecialChar Function/Method
// Just checking to for non letters
bool isNotSpecialChar(char z)
{
	// Make if statement
	if ((z >= 32 && z <= 64) || (z >= 91 && z <= 96) || (z >= 123 && z <= 126))
	{
		return false;
	}
	return true;
}
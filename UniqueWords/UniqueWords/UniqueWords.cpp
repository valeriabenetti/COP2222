/*
* For each programming assignment you will include comments at the start of your code:


Valeria Benetti 2183227

//Novermber 20, 2020 © (the current date and alt+0169 on the number pad to get © Windows; Option G Mac)

//Chapter 17 Assignment (the current assignment)

If using a version of Visual Studio prior to 2019, make sure you follow the Visual Studio Startup word document directions. You must include a system("pause"); in your code if you are using a PC (not a Mac). Visual Studio 2019 does not require this statement.

You should NOT have # include stdfax; in your code. If you do, you have NOT created an empty project.

You must include a collaboration statement in the message box of the drop box. Collaboration means whoever or wherever you received help with your code, even if it was only the text book. This is worth 5 of your overall 40 points for programming assignments. If you have used the Internet, you need to specify the URL where you received help. Failure to do so will result in an Academic Integrity violation.

Any output that is representing money must be formatted to look like US currency. You will lose 5 points if it is not. Chapter 2 has a section on formatting output. Include your last name in filenames.

You will be submitting only the *.cpp file to the drop box. 
*/

#include <iostream>
#include <set>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream inputFile;
	string uFile, word;
	set<string> words;

	cout << "Enter the name of the file: ";
	cin >> uFile;

	// Open the file
	inputFile.open(uFile);

	// check to see if it was successful
	if (inputFile)
	{
		while (inputFile >> word) 
		{
			words.insert(word);
		}
	}
	else
	{
		cout << "This file does not exist" << endl;
	}

	// display the elements
	for (string ele : words)
	{
		cout << ele << endl;
	}

	return 0;
}


/*
* Complete #1 at the end of the chapter. Use the text file from Chapter 12, forChap12.txt.

Write a program that opens a specified text file then displays a list of all the unique words found in the file. 

Addition to the text book specifications,  print the total of unique words in the file.

Hint: Store each word as an element of a set.
*/


/*
//Valeria Benetti - 2183227

//Octover 24, 2020 © (the current date and alt+0169 on the number pad to get © Windows; Option G Mac)

//Chapter 12 Assignment - Line Numbers

If using a version of Visual Studio prior to 2019, make sure you follow the Visual Studio Startup word document directions. You must include a system("pause"); in your code if you are using a PC (not a Mac). Visual Studio 2019 does not require this statement.

You should NOT have # include stdfax; in your code. If you do, you have NOT created an empty project.

You must include a collaboration statement in the message box of the drop box. Collaboration means whoever or wherever you received help with your code, even if it was only the text book. 
This is worth 5 of your overall 40 points for programming assignments. If you have used the Internet, you need to specify the URL where you received help. Failure to do so will result in an Academic Integrity violation.

Any output that is representing money must be formatted to look like US currency. You will lose 5 points if it is not. Chapter 2 has a section on formatting output. Include your last name in filenames.

You will be submitting only the *.cpp file to the drop box.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	// declaring a string variable for the file that was provided
	string ch12NumLine;

	// decalring a string variable for reading saird file
	string readFile;

	// defining the file stream object
	ifstream inputFile;

	// Get the file name from the user
	cout << "Enter the name of the file that you want to read (Please make sure to add the file type ex: filename.txt): ";
	cin >> ch12NumLine;

	// lets open the file
	inputFile.open(ch12NumLine);

	// making a validation if the file doesn't open or there is something wrong
	if (!inputFile) 
	{
		cout << "Error! Can not open file or the file does not exist.\n";
	}

	// Lets ignore any newline characters
	cin.ignore();

	// Making a for to read the file until the end of the file is reached
	for (int count = 1; !inputFile.eof(); count++)
	{
		// check if the following 24 lines have been printed with an if statement
		if (count % 25 == 0)
		{
			system("Pause");
		}

		// read and print line
		getline(inputFile, readFile);
		cout << count << ": " << readFile << endl;

	}

	// Lets close the file
	inputFile.close();

	return 0;
}

/*
(this assignemnt could be done as a modification of the program in Programming Challenge 2.) 
Write a program that asks the user for the name of a file. The program should display the 
contents of the file on the screen. Each line of  of screen output should be preceded with a line number, followed by a colon.
The line numbering should start at 1. 
Example:
1: George Rolland
2: 127 Academy Street
3: Brasstown, NC 28706

If the file's contents won't fit on a single screen, the program should display 24 lines of output at a time, and the puse. 
Each time the program pauses, it should wait for the user to strike a key before the next 24 lines are displayed.
*/

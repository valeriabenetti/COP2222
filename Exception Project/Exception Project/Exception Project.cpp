/*
For each programming assignment you will include comments at the start of your code:


Valeria Benetti - 2183227

November 18, 2020 © (the current date and alt+0169 on the number pad to get © Windows; Option G Mac)

//Chapter 16 Assignment Programming Challenges 1-3

If using a version of Visual Studio prior to 2019, make sure you follow the Visual Studio Startup word document directions. You must include a system("pause"); in your code if you are using a PC (not a Mac). Visual Studio 2019 does not require this statement.

You should NOT have # include stdfax; in your code. If you do, you have NOT created an empty project.

You must include a collaboration statement in the message box of the drop box. Collaboration means whoever or wherever you received help with your code, even if it was only the text book.
This is worth 5 of your overall 40 points for programming assignments.
If you have used the Internet, you need to specify the URL where you received help. Failure to do so will result in an Academic Integrity violation.

Any output that is representing money must be formatted to look like US currency. You will lose 5 points if it is not. Chapter 2 has a section on formatting output. Include your last name in filenames.

You will be submitting only the *.cpp file to the drop box.
*/

#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "ProductionWorker.h"
using namespace std;

int main()
{

	// I might at some point add in a user input for all of this. The homework doesn't state it. But I'll be doing that on my free time during the holidays

	cout << "--------- Now Starting Chapter 15 Program Challenge 1 -------------------\n";
	// Creating Production Worker
	cout << "Creating Production Worker\n";
	ProductionWorker worker;

	// Format output
	cout << fixed << setprecision(2);

	// Setting Data
	worker.setName("Dwight Shrute");
	worker.setNumber(8675309);
	worker.setHireDate(15, 10, 1992);
	worker.setShift(1);
	worker.setPayRate(20.5);


	// Display Data
	cout << "Displaying Worker Data: \n";
	cout << "Employee Name: " << worker.getName() << endl;
	cout << "Employee Number: " << worker.getNumber() << endl;
	cout << "Employee Hire Date: " << worker.getHireDate() << endl;
	cout << "Work Shift: " << worker.getShift() << endl;
	cout << "Employee Pay Rate: $" << worker.getPayRate() << "/hr" << endl;

	// Creating invalid values for employee
	cout << "\n Setting employee number to a negative value of: -5";
	try
	{
		worker.setNumber(-5);
	}
	catch (Employee::InvalidEmployeeNumber e)
	{
		cout << "\n ERROR! " << e.getNumber() << " is not a valid number!\n";
	}

	// Creating inlvaid value for shift
	cout << "\n Setting shift to 3 \n";
	try
	{
		worker.setShift(3);
	}
	catch(ProductionWorker::InvalidShift e)
	{
		cout << "\n ERROR! " << e.getShift() << " is not a valid shift!\n";
	}

	// creating invalid value for pay rate
	cout << "\n Setting pay rate to -15 \n";
	try
	{
		worker.setPayRate(-15);
	}
	catch(ProductionWorker::InvalidPayRate e)
	{
		cout << "\n ERROR! " << e.getPayRate() << " is not a valid pay rate!\n";
	}

	return 0;
}


/*
* Instructions
Complete #13 at the end of the chapter. Dependent on Chapter 15 #1 Employee and ProductionWorker classes. 
Modify the Employee and ProductionWorker classes so they throw exceptions when the following errors occur:

	- The Employee class should throw an exception named InvalidEmployeeNumber when it receives an employee number that is less than 0 or greater than 9999.
	- The ProductionWorker class should throw an exception named InvalidShift when it receives an invalid shift.
	- The ProductionWorker class should throw an exception named InvalidPayRate when it receives a negative number for the hourly pay rate.


Write a driver program that demonstrates how each of these exception conditions works.

*
*/

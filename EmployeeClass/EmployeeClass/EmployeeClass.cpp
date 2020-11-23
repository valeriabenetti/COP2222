/*
Valeria Benetti - 2183227

//October 30, 2020 © (the current date and alt+0169 on the number pad to get © Windows; Option G Mac)

//Chapter 13 Employee Class (the current assignment)

If using a version of Visual Studio prior to 2019, make sure you follow the Visual Studio Startup word document directions. You must include a system("pause"); in your code if you are using a PC (not a Mac). Visual Studio 2019 does not require this statement.

You should NOT have # include stdfax; in your code. If you do, you have NOT created an empty project.

You must include a collaboration statement in the message box of the drop box. Collaboration means whoever or wherever you received help with your code, even if it was only the text book. This is worth 5 of your overall 40 points for programming assignments. If you have used the Internet, you need to specify the URL where you received help. Failure to do so will result in an Academic Integrity violation.

Any output that is representing money must be formatted to look like US currency. You will lose 5 points if it is not. Chapter 2 has a section on formatting output. Include your last name in filenames.

You will be submitting only the *.cpp file to the drop box.
*/

#include <iostream>
#include <string>
#include "empClass.h"
using namespace std;

int main()
{
	// Lets create the array for the three employees from page 808
	Employee employees[3] =
	{
		Employee("Susan Meyer", 47899, "Accounting", "Vice President"),
		Employee("Mark Jones", 39119) // The following elements for this employee will be created with default constuctor
	};

	// Using the SET functions for the objects that are missing
	employees[1].setDepartment("IT\t");
	employees[1].setPosition("Programmer");

	// Using the SET functions for the last employee
	employees[2].setName("Joy Rogers");
	employees[2].setID(81774);
	employees[2].setDepartment("Manufacturing");
	employees[2].setPosition("Engineer");

	// Display the 3 Employees
	cout << "Name    \tID Number\tDepartment\tPosition\n";
	for (int i =0; i < 3; i++)
	{
		cout << employees[i].getName() << "\t";
		cout << employees[i].getID() << "   \t ";
		cout << employees[i].getDepartment() << "\t";
		cout << employees[i].getPosition() << "\t\n";
	}
	return 0;
}


/*
Write a class named Employee that has the following member variables:

name - a string that holds the employee's name
idNumber - an int variable that holds the employee's ID number
department - a string that holds the name of the department where the employee works
position - a string that holds the employee's job title

The class should ahve the following constructors:
A constructor that accepts the followoing values as arguments and assigns them to the appropriate variables: employee's name, employee's ID numbers, department, and position.
A constructor that accepts the follwoing values as arguments and assigns them ot the appropriate member variables: employee's name and ID number. 
The department and position fields should be assigned an empty string ("").
A default constructor that assigns empty strings ("") to the name, department, and position member variables, and 0 to the idNumber member variable.

Write appropriate mutator functions that store values in these member variables and accessor functions that return the values in these member variables. 
Once you have written the class, write a separate program that creates three Employee objects to hold the folowing data: see pg. 808

*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;


#pragma once
class Employee
{
private:
	string eName;
	int eNumber,
		hDay,
		hMonth,
		hYear;

public:

	// Create default constructor
	Employee()
	{
		eName = "";
		eNumber = 0;
		hDay = 0;
		hMonth = 0;
		hYear = 0;
	}

	// Creating the overloaded constructor
	Employee(string n, int num, int d, int m, int y)
	{
		eName = n;
		eNumber = num;

		// Check for validation on the Hire Date...
		if (d < 0 || d > 31 || m < 0 || m > 12 || y < 1900 || y > 2020)
		{
			// Print out an error stating that the hire date is incorrect
			cout << "Error: The Emplyee's Hire Date is invalid. Please enter a date between 1900-2020.\n";
			exit(EXIT_FAILURE);
		}
		else
		{
			// Set Hire Date
			hDay = d;
			hMonth = m;
			hYear = y;
		}
	}

	// GET Functions
	string getName()
	{
		return eName;
	}

	int getNumber() const
	{
		return eNumber;
	}

	string getHireDate()
	{
		// Empty string
		string date = "";

		// Fill string
		date += to_string(hDay) + "/" + to_string(hMonth) + "/" + to_string(hYear);

		// Return 
		return date;
	}

	// SET Function
	void setName(string n)
	{
		eName = n;
	}

	void setNumber(int num) 
	{
		eNumber = num;
	}

	void setHireDate(int d, int m, int y)
	{
		// Check for validation on the Hire Date...
		if (d < 0 || d > 31 || m < 0 || m > 12 || y < 1900 || y > 2020)
		{
			// Print out an error stating that the hire date is incorrect
			cout << "Error: The Emplyee's Hire Date is invalid. Please enter a date between 1900-2020.\n";
			exit(EXIT_FAILURE);
		}
		else
		{
			// Set Hire Date
			hDay = d;
			hMonth = m;
			hYear = y;
		}
	}
};


#endif // !EMPLOYEE_H

/*
*  1. Employee and ProductionWorker Classes
* Design a class named Employee. The class should keep the following information:
*	-Employee name
*	-Employee number
*	-Hire date
* 
* Write one or more contructors, and the appropriate accessor and mutator functions, for the class.
* 
* Next, write a class named ProductionWorker that is derived from the EMployee class. The ProductionWorker class hsould have member variables to hold the follwoing information:
*	-Shift(an integer)
*	- Hourly pay rate ( a double)
* 
* The workday is divided into two shifts: day and night. The shift variable will hold an integer value representing the shift that the employee works. 
* The day shift is shift 1, and the night shift is shift 2. 
* Write one or more constructors, and the appropriate accessor and mutator functions, for the class. Demonstrate the classes by writing a program that uses a ProductionWorker object.
*/

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include <string>
#include "Employee.h"

#pragma once
// This class should inherit from the Employee class
class ProductionWorker : public Employee
{
private:
	int shift;
	double payRate;

public:
	// Error Class for Shift
	class InvalidShift
	{
	private:
		int shift;
	public:
		// create error constructor
		InvalidShift(double sh)
		{
			shift = sh;
		}

		// GET Function
		int getShift() const
		{
			return shift;
		}
	};

	// Error Class for Pay Rate
	class InvalidPayRate
	{
	private: 
		double payRate;
	public:
		// create error constructor
		InvalidPayRate(double pr)
		{
			payRate = pr;
		}

		// GET Function
		double getPayRate() const
		{
			return payRate;
		}
	};

	// Original Constructor
	ProductionWorker() : Employee()
	{
		shift = 1;
		payRate = 0.0;
	}

	// Overload Constructor
	ProductionWorker(string n, int num, int d, int m, int y, int sh, double pr) : Employee(n, num, d, m, y)
	{
		// Validation input
		if ((sh != 1 && sh != 2) || pr < 0)
		{
			cout << "Error: Invalid Shift Input and Pay Rate.\n";
			cout << "Now Exiting. \n";
			exit(EXIT_FAILURE);
		}
		else
		{
			// Set Data
			shift = sh;
			payRate = pr;
		}

	}

	// GET Functions
	string getShift() const
	{
		// Return Day/Night Shift
		if (shift == 1)
		{
			return "Day";
		}
		return "NIght";
	}

	double getPayRate() const
	{
		return payRate;
	}

	// SET Function
	void setShift(int sh)
	{
		// Validation Input
		if (sh != 1 && sh != 2)
		{
			cout << "Error: Invalid Shift.\n";
			cout << "Now Exiting. \n";
			exit(EXIT_FAILURE);
		}
		else
		{
			shift = sh;
		}
	}

	void setPayRate(double pr)
	{
		// Validation Input
		if (pr < 0)
		{
			// Print Error and exit
			cout << "Error: Pay Rate cannot be negative.\n";
			cout << "Now Exiting. \n";
			exit(EXIT_FAILURE);
		}
	}
};

#endif // !PRODUCTIONWORKER_H


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
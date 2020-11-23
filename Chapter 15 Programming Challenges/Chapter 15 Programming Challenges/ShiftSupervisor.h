#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H


#include <iostream>
#include <string>
#include "Employee.h"


using namespace std;

class ShiftSupervisor : public Employee
{
private:
	// Creating variables for the Shift Supervior
	double salary,
		yearlyBonus;
public:
	// Making default constructor
	// Should call the employee class
	ShiftSupervisor() : Employee()
	{
		salary = 0.0;
		yearlyBonus = 0.0;
	}

	// Create an overload constucto that should have the Employee's overload constuctor
	ShiftSupervisor(string n, int num, int d, int m, int y, double s, double b) : Employee(n, num, d, m, y)
	{
		 // Validation check
		if (s < 0 || b < 0)
		{
			cout << "Salary and Bonus cannot be negative numbers!\n";
			exit(EXIT_FAILURE);
		}
		else
		{
			// Set the shift supervisor's info
			salary = s;
			yearlyBonus = b;
		}
	}

	// GET Functions
	double getSalary() const
	{
		return salary;
	}

	double getBonus() const
	{
		return yearlyBonus;
	}

	// SET Functions
	void setSalary(double s)
	{
		// validation for input
		while (s < 0)
		{
			cout << "Salary cannot be a negative number. Enter again: ";
			cin >> s;
		}
		// input salary
		salary = s;
	}

	void setBonus(double b)
	{
		// validation for input
		while (b < 0)
		{
			cout << "Bonus cannot be a negative number. Enter again: ";
			cin >> b;
		}
		// input bonus
		yearlyBonus = b;
	}

};









#endif // !SHIFTSUPERVISOR_H

/*
* 2. ShiftSupervisor Class
* In a particular factory, a shift supervisor is a salaried employee who supervises a shift. In addidtion to aa salary, the shift supervisor earns a yearly bonus when his or her shift meets production goals.
* Design a ShiftSupervisor class that is derived from the Employee class you created in Programming Challenge 1. The ShiftSupervisor class should have a member variable that holds the annual salary, and a member variable that holds the annual production bonus
* that a shift supervisor has earned. Write one or more constructors and the appropriate accessor and mutator functions for the class. Demonstrate the class by writing a program that uses a ShiftSupervisor object.
* 
*/

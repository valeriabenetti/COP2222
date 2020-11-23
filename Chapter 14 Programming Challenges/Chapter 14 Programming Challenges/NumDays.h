#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>
#include <string>
using namespace std;

// Creating the class NumDays
class NumDays
{
private:
	double hours,
		days;
public:
	// Creating the constructor
	NumDays(double hrs = 0)
	{
		hours = hrs;
		days = hrs / (8.00);
	}

	// GET functions
	double getHrs()
	{
		return hours;
	}

	double getDays()
	{
		return days;
	}

	//SET Functions
	void setHrs(double hrs)
	{
		hours = hrs;
		days = hrs / (8.00);
	}

	void setDays(double d)
	{
		days = d;
		hours = d * (8.00);
	}

	//  + operator
	double operator+ (const NumDays& right)
	{
		return hours + right.hours;
	}

	// - operator
	double operator- (const NumDays& right)
	{
		// Make sure it's not a negative number
		if (hours < right.hours)
		{
			cout << "Error: Cannot subtract! Now closing the program\n";
			exit(0);
		}

		return hours - right.hours;

	}

	// Prefix ++ operator
	NumDays operator++()
	{
		// Incrememnt hours
		++hours;

		// Update days
		days = hours / (8.00);

		//return object
		return *this;
	}

	// Postfix ++ operator
	NumDays operator++(int)
	{
		// Post increment
		hours++;

		// Update Days
		days = hours / (8.00);

		// return object
		return *this;
	}

	// Prefix --operator
	NumDays operator--()
	{
		// Decrement Hours
		--hours;

		//Update days
		days = hours / (8.00);

		// return object
		return *this;
	}

	// Postfix --operator
	NumDays operator-- (int)
	{
		// Decrement Hours
		hours--;

		// update days
		days = hours / (8.00);

		// return object
		return *this;
	}
};

#endif // !NUMDAYS_H
/*
* 4. NumDays Class
* Design a class called NumDays. The class's purpose is to store a value that represents a number of work hours and convert it to a number of days.
For example, 8 hours would be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would be converted to 2.25 days. 
The class should have a constructor that accepts a number of hours, as well as member functions for stroing and retrieving the hours and days.
The class should also have the following overloaded operators:

+ Addition operator: When two NumDays objects are added together, the overloaded + operator should return the sum of the two objects' hours members.

- Subtraction operator: When one NumDays object is subtracted from another, the overloaded - operator should return the differenct of the two objects' hours members.

++ Prefix and postfix increment operators: These operators should increment the number of hours stored in the object. When incremented, the number of days should be automatically recalculated.

-- Prefix and postfix decrement operators: These operators should decrement the number of hours stored in the object. When decremented, the number of days should be automatically recalculated.
*/
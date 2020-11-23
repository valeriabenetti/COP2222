/*
* Valeria Benetti
  
  November 1, 2020 © (the current date and alt+0169 on the number pad to get © Windows; Option G Mac)

  Chapter 14 Assignments (the current assignment)
  
  If using a version of Visual Studio prior to 2019, make sure you follow the Visual Studio Startup word document directions. 
  You must include a system("pause"); in your code if you are using a PC (not a Mac). Visual Studio 2019 does not require this statement.
  
  You should NOT have include #stdfax; in your code. If you do, you have NOT created an empty project.
  
  You must include a collaboration statement in the message box of the drop box. Collaboration means whoever or wherever you received help with your code, even if it was only the text book. 
  
  This is worth 5 of your overall 40 points for programming assignments. If you have used the Internet, you need to specify the URL where you received help. Failure to do so will result in an Academic Integrity violation.
  
  Any output that is representing money must be formatted to look like US currency. You will lose 5 points if it is not. Chapter 2 has a section on formatting output. Include your last name in filenames.
  
  You will be submitting only the *.cpp file to the drop box. 
*/

#include <iostream>
#include <string>
#include "TimeOff.h"
#include "NumDays.h"
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

class TimeOff
{
private:
	// Store Employee's Name and ID Number
	string name,
		idNum;

	//Creating NumDays objects to be able to hold the required info that is needed
	NumDays maxSickDays,
		sickTaken,
		maxVacation,
		vacTaken,
		maxUnpaid,
		unpaidTaken;
public:
	// Creating a constructor with some default values
	TimeOff(string n = "", string id = "")
	{
		name = n;
		idNum = id;
	}

	//GET Functions
	string getName() const
	{
		return name;
	}

	string getID() const
	{
		return idNum;
	}

	double getMaxSickDays()
	{
		return maxSickDays.getDays();
	}

	double getSickTaken()
	{
		return sickTaken.getDays();
	}

	double getMaxVacation()
	{
		return maxVacation.getDays();
	}

	double getVacTaken()
	{
		return vacTaken.getDays();
	}

	double getMaxUnpaid()
	{
		return maxUnpaid.getDays();
	}

	double getUnpaidTaken()
	{
		return unpaidTaken.getDays();
	}

	// SET Functions
	void setName(string n)
	{
		name = n;
	}

	void setID(string id)
	{
		idNum = id;
	}

	void setMaxSickDays(double hrs)
	{
		maxSickDays.setHrs(hrs);
	}

	void setSickTaken(double hrs)
	{
		sickTaken.setHrs(hrs);
	}

	void setMaxVacation(double hrs)
	{
		if (hrs > 240)
		{
			maxVacation.setHrs(240);
		}
		else
		{
			maxVacation.setHrs(hrs);
		}
	}

	void setVacTaken(double hrs)
	{
		vacTaken.setHrs(hrs);
	}

	void setMaxUnpaid(double hrs)
	{
		maxUnpaid.setHrs(hrs);
	}

	void setUnpaidTaken(double hrs)
	{
		unpaidTaken.setHrs(hrs);
	}

};

int main()
{
	// Creating the first: For Program Challenge 4
	cout << "Starting Program Challenge 4" << endl;
	cout << "Creating the first 8 hours of work...\n";
	NumDays workhrs1(8);
	cout << workhrs1.getHrs() << "hours = " << workhrs1.getDays() << " days. \n";

	// Creating the second 
	cout << "Creating the next 14 hours of work...\n";
	NumDays workhrs2(14);
	cout << workhrs2.getHrs() << "hours = " << workhrs2.getDays() << " days. \n";

	// Testing the + operator
	cout << endl << "Adding the hours... " << workhrs1 + workhrs2 << " hours.\n";
	
	// Testing the - operator
	cout << endl << "Subtracting the hours... " << workhrs2 - workhrs1 << " hours.\n";

	// Testing the ++ operator
	cout << "Pre and Post Increments of the first day of work\n";
	++workhrs1;
	cout << workhrs1.getHrs() << " hours = " << workhrs1.getDays() << " days.\n.";

	workhrs1++;
	cout << workhrs1.getHrs() << " hours = " << workhrs1.getDays() << " days.\n";

	//Testing --operator
	cout << "Pre and Post Decrements of the second work day\n";
	--workhrs2;
	cout << workhrs2.getHrs() << " hours = " << workhrs2.getDays() << " days.\n";

	workhrs2--;
	cout << workhrs2.getHrs() << " hours = " << workhrs2.getDays() << " days.\n";

	cout << "-----------------------------------------------------------------------------------\n";
	cout << "Starting Program Challenge 6" << endl;

	// Creating items needed for Programming Challenge 6
	// Creating TimeOff employee
	TimeOff employee;

	// Set the name and id
	employee.setName("Valeria Benetti");
	employee.setID("g34652n");

	// Ask user to tell the program how many months the employee has worked
	int months;
	cout << "How many months has " << employee.getName() << " worked here? \n";
	cin >> months;

	// Creatings constants for Vacation and Sick leave that the employee earns per month;
	const int PTO = 12;
	const int SICK_TIME = 8;

	// Setting max vacation
	employee.setMaxVacation(months * PTO);

	// Setting max sick time
	employee.setMaxSickDays(months * SICK_TIME);

	// Print the employee's PTO and Sick Time
	cout << employee.getName() << " has earned " << employee.getMaxVacation() << " days of paid time off.\n";

	cout << employee.getName() << " has earned " << employee.getMaxSickDays() << " days of sick leave. \n";

	return 0;
}

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

*5. Time Off
* Design a class named TimeOff. The Purpose of the class is to track an employee's sick leave, vacation, and unpaid time off. 
It should have, as members, the following instances of the NumDays class described in Programming Challenge 4:
	* maxSickDays: A NumDays object that records the maximum number of days of sick leave the employee may take.
	* sickTaken: A NumDays object that records the number of days of sick leave the employee has already taken.
	* maxVacation: A NumDays object that records the maximum number of days of paid vacation the employee may take.
	* vacTaken: A NumDays object that records the number of days of paid vacation the employee has already taken.
	* maxUnpaid: A NumDays object that records the maximum number of days of unpaid vacation the employee may take.
	* unpaidTaken: A NumDays object that records the number of days of unpaid leave the employee has taken.
Additionally, the class should have members for holding the employee's name and id number. 
It should have an appropriate constructor and member functions for storing and retrieving data in any of the member objects.

Input Validation: Company policay states that an employee may not accumulate more than 240 hours of paid vacation. The class should not allow the maxVacation object to store a value greater than this amount.

*6. Personnel Report
* Write a program that uses an instance of the TimeOff class you designed in Programming Challenge 5. The program shoudl ask the user to enter the number of months an employee has worked for the company. 
It should then use the TimeOff object to calculate and dispaly the employee's maximum object to calculate and display the employee's maximum number of sick leave and vacation days. 
Employees earn 12 hours of vacation leave and 8 hours of sick leave per month.
*/
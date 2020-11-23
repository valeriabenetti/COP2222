#pragma once

#ifndef TIMEOFF_H
#define TIMEOFF_H

#include <string>
#include "NumDays.h"
using namespace std;

// Bringing in the NumDays class
class NumDays;

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


#endif // !TIMEOFF_H

/*
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
*/


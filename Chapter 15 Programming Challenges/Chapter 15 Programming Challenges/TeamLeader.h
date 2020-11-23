#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include <iostream>
#include <string>
#include "ProductionWorker.h"

using namespace std;

// Team Leader class  need to inherit from the Production Worker class
class TeamLeader : public ProductionWorker
{
private:
	double monthlyBonus;
	int hrsRequired,
		hrsAttended;
public:
	// Make default constructor that should call from the Production Worker
	TeamLeader() : ProductionWorker()
	{
		monthlyBonus = 0.0;
		hrsRequired = 40;
		hrsAttended = 0;
	}

	// Overload Constructor that call Production Worker
	TeamLeader(string n, int num, int d, int m, int y, int sh, double pr, double mb, int hr, int ha) : ProductionWorker(n, num, d, m, y, sh, pr)
	{
		// Validation Input
		if (mb < 0)
		{
			cout << "Monthly bonus cannot be negative.\n";
		}
		if (hr < 0)
		{
			cout << "Hours required cannot be negative.\n";
		}
		if (ha < 0)
		{
			cout << "Hours attended cannot be negative.\n";
		}

		// Terminate program if values are less than 0
		if (mb < 0 || hr < 0 || ha < 0)
		{
			cout << "Exiting the Program.\n";
			exit(EXIT_FAILURE);
		}
		else
		{
			monthlyBonus = mb;
			hrsRequired = hr;
			hrsAttended = ha;
		}
	}

	// GET Functions
	double getBonus() const
	{
		return monthlyBonus;
	}

	int getHrsRequired() const
	{
		return hrsRequired;
	}

	int gethrsAttended() const
	{
		return hrsAttended;
	}

	// SET Functions
	void setBonus(double mb)
	{
		// Validate Input
		while (mb < 0)
		{
			cout << "Monthly bonus cannot be negative. Enter again: ";
			cin >> mb;
		}
		monthlyBonus = mb;
	}

	void setHrsRequired(int hr)
	{
		// Validate Input
		while (hr < 0)
		{
			cout << "Hours required cannot be negative. Enter again: ";
			cin >> hr;
		}
		hrsRequired = hr;
	}

	void setHrsAttended(int ha)
	{
		// Validate Input
		while (ha < 0)
		{
			cout << "Hours attended cannot be negative. Enter again: ";
			cin >> ha;
		}
		hrsAttended = ha;
	}
};

#endif // !TEAMLEADER_H

/*
* 3. TeamLeader Class
* In a particular factory, a team leader is an hourly paid production worker who leads a small team. In addition to hourly pay, team leaders earn a fixed monthly bonus. Team leaders are required to attend a minimum number of hours of training per year.
* Desgin a TeamLeader class that extends the ProductionWorker class you designed in Programming Challenge 1. The TeamLeader classh should have member variables for the monthly bonus amount, the required number of training hours, and the nubmer of training hours that the team leader
* has attended. Write one or more constructors and the appropriate accessor and mutator function for the class. Demonstrate the class by writing a program that uses a TeamLeader object.
*/
/*
For each programming assignment you will include comments at the start of your code:


Valeria Benetti - 2183227

November 3, 2020 © (the current date and alt+0169 on the number pad to get © Windows; Option G Mac)

//Chapter 15 Assignment Programming Challenges 1-3

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
#include "ShiftSupervisor.h"
#include "TeamLeader.h"
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

	cout << "--------- Now Starting Chapter 15 Program Challenge 2 -------------------\n";
	// Creating Shift Supervisor
	cout << "Creating Shift Supervisor\n";
	ShiftSupervisor super;

	// Format output
	cout << fixed << setprecision(2);

	// Set Shift Supervisor Data
	super.setName("Micheal Scott");
	super.setNumber(2277858);
	super.setHireDate(10, 10, 1989);
	super.setSalary(4000.00);
	super.setBonus(2000.00);

	// Display Data
	cout << "Displaying Shift Supervisor Data: \n";
	cout << "Supervisor Name: " << super.getName() << endl;
	cout << "Supervisor Number: " << super.getNumber() << endl;
	cout << "Supervisor Hire Date: " << super.getHireDate() << endl;
	cout << "Supervisor Salary: $" << super.getSalary() << endl;
	cout << "Super's Yearly Bonus: $" << super.getBonus() << endl;


	cout << "--------- Now Starting Chapter 15 Program Challenge 3 -------------------\n";
	// Creating Team Leader
	cout << "Creating Team Leader\n";
	TeamLeader lead;

	// Format
	cout << fixed << setprecision(2);

	// Set Team Leader Data
	lead.setName("Doug Judy");
	lead.setNumber(9955398);
	lead.setHireDate(5, 12, 2000);
	lead.setShift(2);
	lead.setPayRate(25.5);
	lead.setBonus(250.00);
	lead.setHrsRequired(25);
	lead.setHrsAttended(10);

	// Display Data
	cout << "Dispalying Leam Leader Data: \n";
	cout << "Team Leader's Name: " << lead.getName() << endl;
	cout << "Team Leader's Number: " << lead.getNumber() << endl;
	cout << "Lead's Hire Data: " << lead.getHireDate() << endl;
	cout << "Lead's Shift: " << lead.getShift() << endl;
	cout << "Lead's Pay Rate: $" << lead.getPayRate() << endl;
	cout << "Lead's Monthly Bonus: $" << lead.getBonus() << endl;
	cout << "Required Hours: " << lead.getHrsRequired() << endl;
	cout << "Attended Hours: " << lead.gethrsAttended() << endl;

	// Creating another Team Lead with other values
	cout << "\n Creating another Team Leader with another set of values\n";
	TeamLeader lead2("Tony Scranton", 5482647, 4, 8, 1999, 1, 30.99, 349.95, 70, 45);

	// Display the new Leader
	cout << "Dispalying Leam Leader Data: \n";
	cout << "Team Leader's Name: " << lead2.getName() << endl;
	cout << "Team Leader's Number: " << lead2.getNumber() << endl;
	cout << "Lead's Hire Data: " << lead2.getHireDate() << endl;
	cout << "Lead's Shift: " << lead2.getShift() << endl;
	cout << "Lead's Pay Rate: $" << lead2.getPayRate() << endl;
	cout << "Lead's Monthly Bonus: $" << lead2.getBonus() << endl;
	cout << "Required Hours: " << lead2.getHrsRequired() << endl;
	cout << "Attended Hours: " << lead2.gethrsAttended() << endl;

	return 0;
}

/*
* 1. Employee and ProductionWorker Classes
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
* 
* 2. ShiftSupervisor Class
* In a particular factory, a shift supervisor is a salaried employee who supervises a shift. In addidtion to aa salary, the shift supervisor earns a yearly bonus when his or her shift meets production goals.
* Design a ShiftSupervisor class that is derived from the Employee class you created in Programming Challenge 1. The ShiftSupervisor class should have a member variable that holds the annual salary, and a member variable that holds the annual production bonus
* that a shift supervisor has earned. Write one or more constructors and the appropriate accessor and mutator functions for the class. Demonstrate the class by writing a program that uses a ShiftSupervisor object.
* 
* 3. TeamLeader Class
* In a particular factory, a team leader is an hourly paid production worker who leads a small team. In addition to hourly pay, team leaders earn a fixed monthly bonus. Team leaders are required to attend a minimum number of hours of training per year.
* Desgin a TeamLeader class that extends the ProductionWorker class you designed in Programming Challenge 1. The TeamLeader classh should have member variables for the monthly bonus amount, the required number of training hours, and the nubmer of training hours that the team leader
* has attended. Write one or more constructors and the appropriate accessor and mutator function for the class. Demonstrate the class by writing a program that uses a TeamLeader object.
* */

#ifndef empClass
#define empClass


#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
	// Member variables
	string name, department, position;
	int idNumber;
	
public:
	// First constructor
	Employee(string n, int id, string dep, string pos)
	{
		name = n;
		idNumber = id;
		department = dep;
		position = pos;
	}

	// Second constructor
	Employee(string n, int id)
	{
		name = n;
		idNumber = id;
		department = "";
		position = "";
	}

	// Default Constructor
	Employee()
	{
		name = "";
		idNumber = 0;
		department = "";
		position = "";
	}

	//GET functions
	string getName() const 
	{
		return name;
	}

	int getID() const
	{
		return idNumber;
	}

	string getDepartment() const
	{
		return department;
	}

	string getPosition() const
	{
		return position;
	}

	// SET functions
	void setName(string n)
	{
		// Check if name input is empty
		if (n.size() == 0)
		{
			cout << "Name cannot be empty. Please enter Employee's Name.\n";
			return;

		}
		else
		{
			name = n;
		}
	}

	void setID(int id)
	{
		// Check if id is not greater than 0. They did not put an id
		if (id <= 0)
		{
			cout << "This is not a valid ID. Please enter Eployee's ID Number\n";
			return;
		}
		else
		{
			idNumber = id;
		}
	}

	void setDepartment(string dep)
	{
		// Check if department is empty
		if (dep.size() == 0)
		{
			cout << "Department cannot be empty. Please enter the Employee's Department\n";
			return;
		}
		else
		{
			department = dep;
		}
	}

	void setPosition(string pos) 
	{
		// Check if position is empty
		if (pos.size() == 0)
		{
			cout << "Position cannot be empty. Please enter the Employee's Position\n";
			return;
		}
		else
		{
			position = pos;
		}
	}

};

#endif // !empClass

/* Valeria Benetti - 2183227

October 21, 2020 ©

//Chapter 11 Assignment (Customer Accounts and Search Function)

If using a version of Visual Studio prior to 2019, make sure you follow the Visual Studio Startup word document directions. You must include a system("pause"); in your code if you are using a PC (not a Mac). Visual Studio 2019 does not require this statement.
You should NOT have # include stdfax; in your code. If you do, you have NOT created an empty project.
You must include a collaboration statement in the message box of the drop box. Collaboration means whoever or wherever you received help with your code, even if it was only the text book. This is worth 5 of your overall 40 points for programming assignments. 
If you have used the Internet, you need to specify the URL where you received help. 
Failure to do so will result in an Academic Integrity violation.
Any output that is representing money must be formatted to look like US currency. You will lose 5 points if it is not. Chapter 2 has a section on formatting output. Include your last name in filenames.
You will be submitting only the *.cpp file to the drop box.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
using std::cout;
using std::cin;

// Creating a struct for Customer Account
struct customerAccount
{
    // Creating strings for all of the required data
    string name,
        address,
        city,
        state,
        zip,
        telephone,
        dateOfLastPayment;

    // Creating a double for Account Balance
    double accountBalance;
};

// Functions
void mainMenu(const unsigned);
void modifyMenu();
void newCustomer(customerAccount[], const unsigned, unsigned&);
void updateCustomer(customerAccount[], const unsigned);
void displayCustomers(customerAccount[], const unsigned);
void searchCustomer(customerAccount[], const unsigned);

// Providing minor functions to validate the data
void nameSet(customerAccount&);
void addressSet(customerAccount&);
void citySet(customerAccount&);
void stateSet(customerAccount&);
void zipSet(customerAccount&);
void telephoneSet(customerAccount&);
void accBalanceSet(customerAccount&);
void dateOfLastPaymentSet(customerAccount&);
void displayCustomer(const customerAccount&);
void findIndex(const customerAccount[], const unsigned, const string, vector<unsigned>&);

string ordinal(const unsigned);

// main validation
bool empty(const string);


int main()
{
    // creating an array of 100 for the struct...we can have at least 10 and maybe a max of 100 so there's cushion
    const unsigned SIZE = 100;

    //Set the struct
    customerAccount customer[SIZE];

    // creating the start of the index
    unsigned firstInIndex = 0;

    // User's choice being set to 0
    int choice = 0;

    do
    {
        mainMenu(firstInIndex);
        cout << "Please make a choice: ";
        cin >> choice;

        // Proccess through the choice
        if (choice == 1)
        {
            newCustomer(customer, SIZE, firstInIndex);

        }
        else if (choice == 2)
        {
            updateCustomer(customer, firstInIndex);
        }
        else if (choice == 3)
        {
            displayCustomers(customer, firstInIndex);
        }
        else if (choice == 4)
        {
            searchCustomer(customer, firstInIndex);
        }
        else if (choice > 4 || choice < 1)
        {
            cout << "Wrong choice number. Please enter either 1/2/3/4: ";
        }
    } while (choice != 0);

    return 0;
}

// Give the user the main menu of the program
void mainMenu(const unsigned totalCustomers)
{
    cout << "Main Menu \n";
    cout << "[ Current number of accounts : " << totalCustomers << " ]\n";
    cout << "1. Add new account.\n";
    cout << "2. Update an existing account.\n";
    cout << "3. Display all data stored.\n";
    cout << "4. Search by user name.\n";
    cout << "0. Exit.\n";
    cout << endl;
}

// When the user decideds to update an existing account. Let them see this to that way they can choose what to update 
void modifyMenu() 
{
    cout << "1. Update the customer's name.\n";
    cout << "2. Update the customer's address.\n";
    cout << "3. Update the customer's city.\n";
    cout << "4. Update the customer's state.\n";
    cout << "5. Update the customer's ZIP code.\n";
    cout << "6. Update the customer's telephone number.\n";
    cout << "7. Update the customer's account balance.\n";
    cout << "8. Update the date of last payment.\n";
    cout << "0. Exit.\n";
}

void newCustomer(customerAccount customer[], const unsigned SIZE,unsigned& index) 
{

    // get the customer's name
    nameSet(customer[index]);

    // get the customer's address
    addressSet(customer[index]);

    // get the customer's city
    citySet(customer[index]);

    // get the customer's state
    stateSet(customer[index]);
    
    // get the customer's ZIP Code
    zipSet(customer[index]);
    
    // get the customer's Telephone
    telephoneSet(customer[index]);
    
    // get the customer's Account Balance
    accBalanceSet(customer[index]);
    
    //Date of last Payment
    dateOfLastPaymentSet(customer[index]);
    

    // Make into an index and point it to the next available place in the array.
    index++;

    cout << "Customer account number [" << index << "] was successfully" << " stored\n";
}

// This function will let the user update the customer account
void updateCustomer(customerAccount customer[], const unsigned NUM_ACCOUNTS) {

    // If the array is empty, return
    if (NUM_ACCOUNTS == 0) {
        cout << "Sorry, but we could not update the customer account because the program is empty.\n";
        cout << "[ Current number of accounts : " << NUM_ACCOUNTS << " ]\n";
        return;
    }

    // Placement marker for the customer account that the user wants to update
    int account = -1;

    // Placement for the user's choice
    int choice = 0;
    
    // Get the account number from user to start the update
    cout << "Please enter the account number, you want to modify. \n";
    cout << "[ Current number of accounts : " << NUM_ACCOUNTS << " ]";
    cout << endl;
    cout << "Your Account : ";
    cin >> account;
    // Error, as long as the account number is non-positive
    //        or exceeds the number of accounts
    while (account<1 || account>NUM_ACCOUNTS) {
        cout << "Please enter a valid number that isn't a negative number!\n";
        cout << "[ Current number of accounts : " << NUM_ACCOUNTS << " ]\n";
        cout << "Your Choice : ";
        cin >> account;
    }
    
    // decrement it to be a valid index
    account--;
    
    // Making a do loop to let the user choose what they want to update 
    do {
        cout << "Please choose your option,\n\n";
        
        // now show the modify menu
        modifyMenu();
        cout << "Your Choice : ";
        cin >> choice;
        cin.ignore();
        // Making the if statement once they choose one othe options for update
        if (choice == 1) 
        {
            cout << "You choose the name of the\n";
            cout << (account + 1) << ordinal(account + 1) << " account,\n";
            cout << "Original Value : " << customer[account].name << endl;
            cout << "Now please enter the new value: ";
            nameSet(customer[account]);
        }
        else if (choice == 2) 
        {
            cout << "You choose the address of the";
            cout << (account + 1) << ordinal(account + 1) << " account,\n";
            cout << "Original Value : " << customer[account].address << endl;
            cout << "Now please enter the new value : ";
            addressSet(customer[account]);
        }
        else if (choice == 3) 
        {
            cout << "You choose the city of the";
            cout << (account + 1) << ordinal(account + 1) << " account,\n";
            cout << "Original Value : " << customer[account].city << endl;
            cout << "Now please enter the new value: ";
            citySet(customer[account]);
        }
        else if (choice == 4) {
            cout << "You choose the state of the";
            cout << (account + 1) << ordinal(account + 1) << " account,\n";
            cout << "Original Value : " << customer[account].state << endl;
            cout << "Now please enter the new value: ";
            stateSet(customer[account]);
        }
        else if (choice == 5) {
            cout << "You choose the ZIP code of the";
            cout << (account + 1) << ordinal(account + 1) << " account\n";
            cout << "Original Value : " << customer[account].zip << endl;
            cout << "Now please enter the new value: ";
            zipSet(customer[account]);
        }
        else if (choice == 6) {
            cout << "You choose the telephone number of the\n";
            cout << (account + 1) << ordinal(account + 1) << " account,\n";
            cout << "Original Value : " << customer[account].telephone << endl;
            cout << "Now please enter the new value: ";
            telephoneSet(customer[account]);
        }
        else if (choice == 7) {
            cout << "You choose the customer account balance of the";
            cout << (account + 1) << ordinal(account + 1) << " account,\n";
            cout << "Original Value : " << customer[account].accountBalance << endl;
            cout << "Now please enter the new value: ";
            accBalanceSet(customer[account]);
        }
        else if (choice == 8) {
            cout << "You choosed the date of last payment of the\n";
            cout << (account + 1) <<ordinal(account + 1)
                << " account,\n";
            cout << "Original Value : " << customer[account].dateOfLastPayment << endl;
            cout << "Now please enter the new value: ";
            dateOfLastPaymentSet(customer[account]);
        }
        else if (choice != 0) {
            cout << "Wrong choice value,\n";
            cout << "Please enter a valid choice\n";
        }
    } while (choice != 0);
    cout << "Thank you for updating the information. Good Bye!\n";
}


//  This function should display the customer accounts
void displayCustomers(customerAccount customer[], const unsigned NUM_ACCOUNTS) {
    // This function would display total account list,
    if (NUM_ACCOUNTS == 0) {
        // There are no accounts
        // show an informative message and return
        cout << "Sorry, but the array is empty.\n";
        cout << "[ Current number of accounts : " << NUM_ACCOUNTS << " ]\n";
        return;
    }
    
    // There are some account, display them in a formatted manner.
    for (unsigned i = 0; i < NUM_ACCOUNTS; i++) {
        cout << "The information about " << (i + 1) << ordinal(i + 1) << " account,\n";

        // now show the information,

        displayCustomer(customer[i]);

        if (i < (NUM_ACCOUNTS - 1)) 
        {
            cout << "--------------------------------------------\n";
        }
    }
}

// This function prints the information about specific
void displayCustomer(const customerAccount& customer) {

    // The information,
    cout << "Name: " << customer.name << endl;
    cout << "Address: " << customer.address << endl;
    cout << "City: " << customer.city << endl;
    cout << "State: " << customer.state << endl;
    cout << "ZIP Code: " << customer.zip << endl;
    cout << "Telephone: " << customer.telephone << endl;
    cout << "Balance: $" << customer.accountBalance << endl;
    cout << "Date of last Payment: " << customer.dateOfLastPayment << endl;
}


//This function should help with searching for a customer account 
void searchCustomer(customerAccount customer[], const unsigned NUM_ACCOUNTS) {

    // If there are no customer accounts
    if (NUM_ACCOUNTS == 0) {

        cout << "Sorry, but the program list is empty.\n";
        cout << "[ Current number of accounts : " << NUM_ACCOUNTS << " ]\n";
        return;
    }

    // this is used to hold the name from the user
    string name;

    //  Using avector to hold all indexes of the account having the name
    vector<unsigned> vec;

    // ask the name from the name
    cout << "Please enter the name you want to search for\n";
    cout << "Name : ";
    getline(cin, name);
    // There is no empty name, Input validation
    while (empty(name)) {
        cout << "Sorry but the name can not be empty,\n";
        cout << "Name: ";
        getline(cin, name);
    }
    

    // got the name, now search for it and get the indices
    findIndex(customer, NUM_ACCOUNTS, name, vec);

    // if  list is empty show message and return
    if (vec.empty()) {
        cout << "Sorry, but we did not find any account that matches your name.\n";
        cout << "Enter a Name: \"" << name << "\"\n";
        cout << "[ Number of Results : 0 ]\n";
        return;
    }

    // If list does shows result, show the list of names
    unsigned numResults = vec.size();
    cout << "Enter a Name : \"" << name << "\"\n";
    cout << "Number of Results : " << numResults << " \n";
    cout << "Here is the result list: \n\n";

    for (unsigned i = 0; i < numResults; i++) {
        cout << "The information about " << (i + 1) << ordinal(i + 1) << " account found,\n";
        // now show the information,
        displayCustomer(customer[vec[i]]);

        if (i < (numResults - 1))
            cout << "--------------------------------------------\n";
    }
    

}

// This function sets the name of an account
void nameSet(customerAccount& customer) 
{
    // get the name
    cout << "Name: ";
    getline(cin, customer.name);
    // Input validation
    while (empty(customer.name)) {
        cout << "Sorry but the name could not be empty,\n";
        cout << "Name: ";
        getline(cin, customer.name);
    }
}

// This function sets the address of an account
void addressSet(customerAccount& customer) 
{
    // Getting address,
    cout << "Address: ";
    getline(cin, customer.address);
    // Input validation
    while (empty(customer.address)) {
        cout << "Sorry but the address could not be empty,\n";
        cout << "Address: ";
        getline(cin, customer.address);
    }
}

// This function sets the city of an account
void citySet(customerAccount& customer) 
{
    // Getting city,
    cout << "City: ";
    getline(cin, customer.city);
    // Input validation
    while (empty(customer.city)) {
        cout << "Sorry but the city could not be empty,\n";
        cout << "City: ";
        getline(cin, customer.city);
    }
}

// This function sets the state of an account
void stateSet(customerAccount& customer) 
{
    // Getting state,
    cout << "State: ";
    getline(cin, customer.state);
    // Input validation
    while (empty(customer.state)) {
        cout << "Sorry but the state could not be empty,\n";
        cout << "State: ";
        getline(cin, customer.state);
    }
}
// This function sets the ZIP code of an account
void zipSet(customerAccount& customer) 
{
    // Getting ZIP Code,
    cout << "ZIP Code: ";
    getline(cin, customer.zip);
    // Input validation
    while (empty(customer.zip)) {
        cout << "Sorry but the ZIP code could not be empty,\n";
        cout << " ZIP Code : ";
        getline(cin, customer.zip);
    }
}

// This function sets the telephone number of an account
void telephoneSet(customerAccount& customer) 
{
    // Getting Telephone,
    cout << "Telephone: ";
    getline(cin, customer.telephone);
    // Input validation
    while (empty(customer.telephone)) {
        cout << "Sorry but the telephone could not be empty,\n";
        cout << "Telephone : ";
        getline(cin, customer.telephone);
    }
}


void accBalanceSet(customerAccount& customer) 
{
    // This function sets the balance of an account

    // we pass account by reference in order to be able to
    // modify the original account structure.

    // Getting user's Balance,
    cout << "Balance: $";
    cin >> customer.accountBalance;
    // Input validation
    while (customer.accountBalance < 0) {
        cout << "Sorry but the balance could not be negative,\n";
        cout << "Balance: $";
        cin >> customer.accountBalance;
    }
    cin.ignore();
}

// This function sets the date of the last payment
void dateOfLastPaymentSet(customerAccount& customer) 
{
    // Getting Date of last Payment,
    cout << "Date of last Payment : ";
    getline(cin, customer.dateOfLastPayment);
    // Input validation
    while (empty(customer.dateOfLastPayment)) {
        cout << "Sorry but the date could not be empty,\n";
        cout << "Date of last Payment : ";
        getline(cin, customer.dateOfLastPayment);
    }
}



// Input validation so that way they aren't putting in anythign blank
bool empty(const string str) {
    if (str.empty())
        return true;
    unsigned len = str.length();
    for (unsigned i = 0; i < len; i++) {
        // if there is a non-space letter
        // return false
        if (!isspace(str[i]))
            return false;
    }
    return true;
}

// This function returns an ordinal indicator
string ordinal(const unsigned num) {
    
    // first check the leftmost two digits
    unsigned parser = num;  100;
    if (parser < 20 && parser > 10) {
        return "th";
    }
    // if not then get the leftmost digit
    parser = num;  10;
    if (parser == 1) {
        // st for first
        return "st";
    }
    else if (parser == 2) {
        // nd for second
        return "nd";
    }
    else if (parser == 3) {
        // rd for third
        return "rd";
    }
    else {
        // th for any other digit
        return "th";
    }
}

// This function searches for the string name
void findIndex(const customerAccount customer[], const unsigned NUM_ACCOUNTS, const string name, vector<unsigned>& vec) 
{
    // first clear the vector, if it has some previous elements.
    if (!vec.empty()) {
        vec.clear();
    }

    // now loop over all elements of the array, if any element found
    for (unsigned i = 0; i < NUM_ACCOUNTS; i++) {
        // find function is used to check whether 
        // string contains another string or not
        // npos is a special value defined in string class
        // which is returned if not found
        if (customer[i].name.find(name) != string::npos) {

            // we found the name
            vec.push_back(i);
        }
    }
}
/*

Homework Challenge 7:
Write a program that uses a structure to store the following data about a customer account:
Name
Address
City, State, and ZIP
Telephone Number
Account Balance
Date of Last Payment

The program should  use an array of at LEAST 10 structures. It should let the user enter the data into the array, change the contents of any element, and display all the data stored in the array.
The program shoudl have a menu-driven user interface.... NOTE TO SELF...check the last homework 

Input Validation: When the data for a new account is entered, be sure the user enters data for ALL the fields. NO negative account balances should be enters.



Homework Challenege 8:

Add a function to Programming Challenge 7 that allows the user to search the structure array for a particular customer's account.
It should accept part of the customer's name as an argument then search for an account with a name that matches it. All accounts that match should be displayed. 
If no account matches, a message saying so should be displayed.
*/
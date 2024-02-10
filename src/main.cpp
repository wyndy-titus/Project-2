// SUMMARY: Project 2: First Glance into OOP - implementing classes
// AUTHOR:  Wyndy Titus
// VERSION: 2024-02-08

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

// ------------- DECLARATIONS -------------

class CDAccount
{
public:
    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance() const;
    double get_balance_at_maturity() const;
    double get_interest_rate() const;
    int get_term() const;
    void input(istream& in);
    void output(ostream& out);    

private:
    int dollar, cent, term; // "term" is the number of months until maturity 
    double interest_rate;    
};

// ------------------------------------------

void displayMenu();
//Postcondition: Displays the menu, which shows the user different options for testing

// ------------------------------------------

int selectOption();
//Postcondition: reads in the selected menu item and returns the value for the variable "choice"

// ------------------------------------------

bool tryAgain();

// ------------------------------------------

int main()
{
  // Declaring the class object and calling the constructor to initialize it  
    CDAccount account = CDAccount();
    int choice;    
    ifstream istream;
    ofstream ostream;

    do
    {
        system("cls");
        displayMenu();
        choice = selectOption();

        switch(choice)
        {
            case 1:
            case 2:
            {
                cout << "\nEnter the following account details: " << "initial balance,"
                     << " interest rate, and term (in months). Press \"enter\" when complete.\n";
                account.input(cin);                
                break;
            }

            case 3:
            case 4:
            {
                string fileName;
                cout << "\nPlease enter the file name: ";
                cin.ignore(1, '\n');
                getline(cin, fileName);
                istream.open(fileName);
                if (istream.fail())
                {
                    cout << "Could not read file. Returning to menu.";
                    main();
                }
                account.input(istream);
                break;
            }

            case 5:
            {
                cout << "Goodbye!";
                exit(1);
                break;
            }

            default:
            {
                cout << "Error - returning to menu.";
                main();
                break;
            }
        }

        if ((choice == 2) || (choice == 4))
        {
            ostream.open("results.txt");
            if (ostream.fail())
            {
                cout << "Output file opening failed.";
                exit(1);
            }
            account.output(ostream);
            cout << "Successfully exported to file: results.txt";            
        }
        else
        {
            account.output(cout);
        }

        cout << endl << endl;       

    } while (tryAgain());

    cout << "\n\t--- Thank you for testing this program! Goodbye." << endl;
    exit(1);
}

// ----------------- DEFINITIONS -----------------
// The default constructor within the scope of class CDAccount
CDAccount::CDAccount()  
{
    // Setting the values of the variables to 0
    dollar = 0;
    cent = 0;
    term = 0;
    interest_rate = 0;
}

// -----------------------------------------------

CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term)
{
    // Setting the values of the variables to the values of the args passed in    = ;
    dollar = floor(new_balance);
    cent = (new_balance - dollar) * 100;
    interest_rate = new_interest_rate;
    term = new_term;
}

// -----------------------------------------------

double CDAccount::get_initial_balance() const
{
    return this->dollar + (this->cent / 100);
}

// -----------------------------------------------
    
double CDAccount::get_interest_rate() const
{
    return this->interest_rate;
}

// -----------------------------------------------

int CDAccount::get_term() const
{
    return this->term;
}

// -----------------------------------------------

double CDAccount::get_balance_at_maturity() const
{
    // This is based on the simple interest formula (I = PRT)
    double interest = get_initial_balance() * (this->interest_rate / 100) * (this->term / 12.0);
    // Total balance at maturity is initial balance + interest earned
    return interest + get_initial_balance();
}
// -----------------------------------------------

void CDAccount:: input(istream& in)
{
    double balance;
    in >> balance >> interest_rate >> term;
    dollar = floor(balance);
    cent = (balance - dollar) * 100;
}

// -----------------------------------------------

void CDAccount::output(ostream& out)
{
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);

    out << "\n\n--- CD Account Specifications ---\n" << endl;
    out << "Initial balance: $" << get_initial_balance() << endl 
        << "Interest rate: " << get_interest_rate() << "%" << endl           
        << "Time until account maturity: " << get_term() << " months" << endl
        << "Balance at maturity: $" << get_balance_at_maturity() << endl 
        << endl << "---------------------------------\n";
}

// -----------------------------------------------

void displayMenu()
{
    cout << "\n\t**************************************************************"
	     << "\n\t*                        MENU                                *"
	     << "\n\t*    1. Input account details and print to screen            *"
	     << "\n\t*    2. Input account details and print to file              *"
         << "\n\t*    3. Read account details from file and print to screen   *"
         << "\n\t*    4. Read account details from file and print to file     *"	    
         << "\n\t*    5. Quit                                                 *"
	     << "\n\t**************************************************************\n"; 
}

// -----------------------------------------------

int selectOption()
{
    int option;
    cout << "\nPlease select an option from the menu: ";    
    while ((option < 1) || (option > 5))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nInvalid input - try again: ";
        cin >> option;
    }
    return option;    
}

// -----------------------------------------------

bool tryAgain()
{
    cout << "Would you like to run another test? Enter (Y or N): ";
    char choice;
    cin >> choice;
    choice = tolower(choice);   
    
    while ((choice != 'y') && (choice != 'n'))
    {
        cout << "Invalid input - try again: ";
        cin >> choice;
        choice = tolower(choice);      
    }

    if (choice == 'y')
    {
        cout << endl << endl;
        return true;
    }
    
    cout << endl << endl;  
    return false;
}

// -------------END OF DEFINITIONS----------------

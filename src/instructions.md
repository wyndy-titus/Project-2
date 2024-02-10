/* Do Programming Project 2 on page 611. You may watch the video note for 
 * Programming Project 1 on page 611 to get some idea. Then try to finish
 * independently by complete this sample file.
 * 
 * Author: Your Name
 * Version: Date
 */

#include <iostream>
using namespace std;

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
    int dollar;
    int cent;
    double interest_rate;
    int term; // months until maturity
};

int main()
{
    // You implement the test code here
    // You may watch the video note to get the idea
    // notice that user will only enter balance as a double value
    // You may implement it as a menu oriented testing program
    // which be able to test constructors, methods of CDAccount class
}

// Implement the class definition here. Notice that the interfaces are the
// same as in Programming Project 1. However, the implementation will be
// different since the private information balance is stored differently
// for example, the input function will only read the balance, itnerest rate
// and term from the user. So it should be modified as following
void CDAccount::input(istream& in)
{
    double balance;
    in >> balance; // get initial balance from user
    
    // convert balance to dollars and cents since this is how balance stored
    dollar = (int) balance; // dollar is the interger part of balace
    cent = (int) ((balance - dollar)*100); // cent is the fraction part * 100
    
    in >> interest_rate; // get interest rate from user
    in >> term; // get term from user
}

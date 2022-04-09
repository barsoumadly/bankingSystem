#include <string>

#ifndef _ACCOUNT_H
#define _ACCOUNT_H
using namespace std;

class Account {
private:
    string first_name;
    string last_name;
    double balance;
    int account_number;
public:
   static int number;

    void set_first_name(string firstName);

    string get_first_name();

    void set_last_name(string lastName);

    string get_last_name();

    void set_balance(double initialBalance);

    double get_balance() const;

    void increment_account_number();

    void set_account_number(int account_number);

    int get_account_number() const;

    void set_deposit(double deposit);

    void set_withdrawal(double withdrawal);
};


#endif //_ACCOUNT_H

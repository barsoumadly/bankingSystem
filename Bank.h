#include <vector>
#include "Account.h"

#ifndef _BANK_H
#define _BANK_H
using namespace std;

class Bank {
public:
    Bank();

    vector<Account> accounts;

    void get_data();

    void open_account(string first_name, string last_name, double balance);

    void add_account(const Account &account);

    int get_account_number();

    double get_balance();

    Account search_for_account_number(int account_number);

    void display_created_account(Account account);

    void display_accounts();

    void show_searched_account();
};

#endif //_BANK_H

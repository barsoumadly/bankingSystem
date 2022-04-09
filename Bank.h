#include <vector>
#include "Account.h"

#ifndef _BANK_H
#define _BANK_H
using namespace std;

class Bank {
public:
    Bank();

    static vector<Account> accounts;

    static vector<string> get_data();

    static string get_first_name();

    static string get_last_name();

    static string get_balance();

    static void open_account();

    static Account set_account_data(vector<string> data);

    static void add_in_file(Account account);

    static void save_account(const Account &account);

    static int get_account_number();

    static Account *search_for_account_number(int account_number);

    static void display_created_account(Account account);

    static void display_accounts();

    static void show_searched_account();

    static void deposit();

    static void withdrawal();

    static void close_account();

    static void rewrite_file();

};

#endif //_BANK_H

#include "Application.h"
#include <iostream>
#include <iomanip>
#include "Bank.h"

using namespace std;

Bank bank;
Account account;

void Application::start() {
    cout << setw(50);
    cout << "***Banking System***" << endl;
    while (true) {
        option_list();
        string command = choose_command();
        if (command == "7") {
            break;
        } else {
            perform_command(command);
        }
    }
}

void Application::option_list() {
    cout << setw(30) << "Select one option below" << endl
         << setw(24) << "1 Open an Account" << endl
         << setw(24) << "2 Balance Enquiry" << endl
         << setw(16) << "3 Deposit" << endl
         << setw(19) << "4 Withdrawal" << endl
         << setw(25) << "5 Close an Account" << endl
         << setw(26) << "6 Show all Accounts" << endl
         << setw(13) << "7 Quit" << endl;
}

string Application::choose_command() {
    cout << "Enter your choice: ";
    string command = " ";
    cin >> command;
    return command;
}

void Application::perform_command(string &command) {
    if (command == "1") {
        bank.get_data();
    } else if (command == "2") {
        bank.show_searched_account();
    } else if (command == "3") {
        bank.get_account_number();
        account.set_deposit(bank.get_balance());
    } else if (command == "4") {
        bank.get_account_number();
        account.set_withdrawal(bank.get_balance());
    } else if (command == "5") {
    } else if (command == "6") {
        bank.display_accounts();
    } else {
        cout << "Wrong option" << endl;
    }
}





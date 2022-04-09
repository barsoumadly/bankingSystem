#include "Application.h"
#include <iostream>
#include <iomanip>
#include "Bank.h"

using namespace std;

Bank bank;
Account account;

class Commands {
public:
    static const int OPEN_ACCOUNT;
    static const int BALANCE_ENQUIRY;
    static const int DEPOSIT;
    static const int WITHDRAWAL;
    static const int SHOW_ACCOUNTS;
    static const int CLOSE_ACCOUNT;
    static const int EXIT;
};

const int Commands::OPEN_ACCOUNT = 1;
const int Commands::BALANCE_ENQUIRY = 2;
const int Commands::DEPOSIT = 3;
const int Commands::WITHDRAWAL = 4;
const int Commands::CLOSE_ACCOUNT = 5;
const int Commands::SHOW_ACCOUNTS = 6;
const int Commands::EXIT = 7;

void Application::start() {
    commands_list_header();
    while (true) {
        commands_list();
        string commandStr = choose_command();
        int command = command_string_to_integer(commandStr);
        if (command == Commands::EXIT) {
            break;
        } else {
            perform_command(command);
        }
        clear_console();
    }
}

void Application::commands_list_header() {
    cout << setw(50);
    cout << "***Banking System***" << endl;
}

void Application::commands_list() {
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

int Application::command_string_to_integer(string &commandStr) {
    int command = 0;
    try {
        command = stoi(commandStr);
    } catch (...) {
    }
    return command;
}

void Application::perform_command(int command) {
    switch (command) {
        case Commands::OPEN_ACCOUNT:
            bank.get_data();
            break;
        case Commands::BALANCE_ENQUIRY:
            bank.show_searched_account();
            break;
        case Commands::DEPOSIT:
            bank.get_account_number();
            account.set_deposit(bank.get_balance());
            break;
        case Commands::WITHDRAWAL:
            bank.get_account_number();
            account.set_withdrawal(bank.get_balance());
            break;
        case Commands::CLOSE_ACCOUNT:
            break;
        case Commands::SHOW_ACCOUNTS:
            bank.display_accounts();
            break;
        default:
            cout << "Wrong option" << endl;
            break;
    }
}

void Application::clear_console() {
    string x;
    getline(cin, x);
    cin.ignore();
    system("clear");
}





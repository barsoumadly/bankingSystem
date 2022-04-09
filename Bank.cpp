#include "Bank.h"
#include <iostream>
#include <fstream>

using namespace std;

ofstream out_file("../bank_system.txt", ios::app);

void Bank::get_data() {
    cout << "Enter First Name: ";
    string first_name;
    cin >> first_name;
    cout << "Enter Last Name: ";
    string last_name;
    cin >> last_name;
    cout << "Enter initial balance: ";
    double initial_balance = 0.0;
    cin >> initial_balance;
    open_account(first_name, last_name, initial_balance);
}

void Bank::open_account(string first_name, string last_name, double balance) {
    Account account;
    account.set_first_name(first_name);
    account.set_last_name(last_name);
    account.set_balance(balance);
    account.increment_account_number();
    if (accounts.size() != 0) {
        out_file << endl;
    }
    out_file << account.get_first_name() << ","
             << account.get_last_name() << ","
             << account.get_account_number()
             << "," << account.get_balance() << endl;
    add_account(account);
}

void Bank::add_account(const Account &account) {
    accounts.push_back(account);
    display_created_account(account);
}

void Bank::display_created_account(Account account) {
    cout << "Congratulation Account is Created" << endl;
    cout << "First Name: " << account.get_first_name() << endl;
    cout << "Last Name: " << account.get_last_name() << endl;
    cout << "Account Number: " << account.get_account_number() << endl;
    cout << "Balance: " << account.get_balance() << endl;
}

void Bank::display_accounts() {
    for (int i = 0; i < accounts.size(); i++) {
        cout << "Account " << i + 1 << endl;
        cout << "First Name: " << accounts[i].get_first_name() << endl;
        cout << "Last Name: " << accounts[i].get_last_name() << endl;
        cout << "Account Number: " << accounts[i].get_account_number() << endl;
        cout << "Balance: " << accounts[i].get_balance() << endl;
        cout << "--------------------------------------------------" << endl;
    }
}

void Bank::show_searched_account() {
    int account_number = get_account_number();
    Account account = search_for_account_number(account_number);
    cout << "Your Account Details" << endl;
    cout << "First Name: " << account.get_first_name() << endl
         << "Last Name: " << account.get_last_name() << endl
         << "Account Number: " << account.get_account_number() << endl
         << "Balance: " << account.get_balance() << endl;
}

int Bank::get_account_number() {
    cout << "Enter the Account Number: ";
    int account_number;
    cin >> account_number;
    return account_number;
}

double Bank::get_balance() {
    cout << "Enter Balance: ";
    double balance = 0.0;
    cin >> balance;
    return balance;
}


Account Bank::search_for_account_number(int account_number) {
    for (auto &account: accounts) {
        if (account.get_account_number() == account_number)
            return account;
    }
}


vector<string> split(string line) {
    vector<string> array;
    string temp;
    for (char x: line) {
        if (x == ',') {
            array.push_back(temp);
            temp = "";
        } else {
            temp += x;
        }
    }
    array.push_back(temp);
    return array;
}

Bank::Bank() {
    string line;
    ifstream in_file;
    in_file.open("../bank_system.txt", ios::in);
    while (!in_file.eof()) {
        getline(in_file, line);
        if (!line.empty()) {
            vector<string> array = split(line);
            Account account;
            account.set_first_name(array[0]);
            account.set_last_name(array[1]);
            account.set_account_number(stoi(array[2]));
            account.set_balance(stod(array[3]));
            accounts.push_back(account);
        }
    }
}

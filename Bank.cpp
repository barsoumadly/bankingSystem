#include "Bank.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<Account> Bank::accounts;

ofstream out_file("../bank_system.txt", ios::app);

vector<string> Bank::get_data() {
    vector<string> data;
    data.push_back(get_first_name());
    data.push_back(get_last_name());
    data.push_back(get_balance());
    return data;
}

string Bank::get_first_name() {
    cout << "Enter First Name: ";
    string first_name;
    cin >> first_name;
    return first_name;
}

string Bank::get_last_name() {
    cout << "Enter Last Name: ";
    string last_name;
    cin >> last_name;
    return last_name;
}

string Bank::get_balance() {
    cout << "Enter Balance: ";
    string balance = " ";
    cin >> balance;
    return balance;
}

void Bank::open_account() {
    vector<string> data = get_data();
    Account account = set_account_data(data);
    save_account(account);
}

Account Bank::set_account_data(vector<string> data) {
    Account account;
    account.set_first_name(data[0]);
    account.set_last_name(data[1]);
    account.set_balance(stod(data[2]));
    account.increment_account_number();
    return account;
}

void Bank::save_account(const Account &account) {
    add_in_file(account);
    accounts.push_back(account);
    display_created_account(account);
}

void Bank::add_in_file(Account account) {
    if (!accounts.empty()) {
        out_file << endl;
    }
    out_file << account.get_first_name() << ","
             << account.get_last_name() << ","
             << account.get_account_number()
             << "," << account.get_balance();
}

void Bank::display_created_account(Account account) {
    cout << "Congratulation Account is Created" << endl;
    cout << "First Name: " << account.get_first_name() << endl;
    cout << "Last Name: " << account.get_last_name() << endl;
    cout << "Account Number: " << account.get_account_number() << endl;
    cout << "Balance: " << account.get_balance() << endl;
}

void Bank::display_accounts() {
    for (auto &account: accounts) {
        cout << "Account " << account.get_account_number() << endl;
        cout << "First Name: " << account.get_first_name() << endl;
        cout << "Last Name: " << account.get_last_name() << endl;
        cout << "Account Number: " << account.get_account_number() << endl;
        cout << "Balance: " << account.get_balance() << endl;
        cout << "--------------------------------------------------" << endl;
    }
}

void Bank::show_searched_account() {
    int account_number = get_account_number();
    Account *account = search_for_account_number(account_number);
    cout << "Your Account Details" << endl;
    cout << "First Name: " << account->get_first_name() << endl
         << "Last Name: " << account->get_last_name() << endl
         << "Account Number: " << account->get_account_number() << endl
         << "Balance: " << account->get_balance() << endl;
}

int Bank::get_account_number() {
    cout << "Enter the Account Number: ";
    int account_number;
    cin >> account_number;
    return account_number;
}

Account *Bank::search_for_account_number(int account_number) {
    for (Account &account: accounts) {
        if (account.get_account_number() == account_number)
            return &account;
    }
}

vector<string> split(string &line) {
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
            Account::number = stoi(array[2]);
        }
    }
}

void Bank::deposit() {
    int account_number = get_account_number();
    double balance = stod(get_balance());
    Account *account = search_for_account_number(account_number);
    account->set_deposit(balance);
    rewrite_file();
}

void Bank::withdrawal() {
    int account_number = get_account_number();
    double balance = stod(get_balance());
    Account *account = search_for_account_number(account_number);
    account->set_withdrawal(balance);
    rewrite_file();
}

void Bank::close_account() {
    int account_number = get_account_number();
    accounts.erase(accounts.begin() + account_number - 1);
    rewrite_file();
}

void Bank::rewrite_file() {
    out_file.close();
    out_file.open("../bank_system.txt", ofstream::out | ofstream::trunc);
    for (auto &account: accounts) {
        out_file << account.get_first_name() << ","
                 << account.get_last_name() << ","
                 << account.get_account_number() << ","
                 << account.get_balance() << endl;
    }
}

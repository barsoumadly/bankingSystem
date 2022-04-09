#include "Account.h"

int Account::number = 0;

void Account::set_first_name(string firstName) {
    this->first_name = firstName;
}

string Account::get_first_name() {
    return first_name;
}

void Account::set_last_name(string lastName) {
    this->last_name = lastName;
}

string Account::get_last_name() {
    return last_name;
}

void Account::set_balance(double initialBalance) {
    this->balance = initialBalance;
}

double Account::get_balance() const {
    return balance;
}

void Account::increment_account_number() {
    number += 1;
    this->account_number = number;
}

int Account::get_account_number() const {
    return account_number;
}

void Account::set_deposit(double deposit) {
    this->balance += deposit;
}

void Account::set_withdrawal(double withdrawal) {
    this->balance -= withdrawal;
}

void Account::set_account_number(int account_number) {
    this->account_number = account_number;
}


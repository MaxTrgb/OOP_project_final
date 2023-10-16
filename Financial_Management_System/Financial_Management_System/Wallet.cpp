#include "Wallet.h"
#include <iostream>

// Default constructor for Wallet
Wallet::Wallet()
{
    walletName = "";
    balance = 0.0;
}

// Parameterized constructor for Wallet
Wallet::Wallet(const string& walletName, double balance) {
    this->walletName = walletName;
    this->balance = balance;
}

// Function to deposit a specified amount into the wallet
void Wallet::Deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "\n\t\t\tDeposited " << amount << " into " << walletName << " wallet." << endl;
    }
}

// Function to withdraw a specified amount from the wallet
void Wallet::Withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "\n\t\t\tWithdrawn " << amount << " from " << walletName << " wallet." << endl;
    }
    else {
        cout << "\n\t\t\tInsufficient balance in " << walletName << " wallet." << endl;
    }
}

// Function to get the current balance of the wallet
double Wallet::GetBalance() const {
    return balance;
}

// Function to get the name of the wallet
string Wallet::GetName() const {
    return walletName;
}

#pragma once
#include <string>
#include <limits>
using namespace std;

class Wallet {
private:
    string walletName; 
    double balance;   

public:
    // Default constructor for the Wallet class
    Wallet();

    // Constructor with parameters for the Wallet class
    Wallet(const string& walletName, double balance = 0.0);

    // Member function to deposit a specified amount into the wallet
    void Deposit(double amount);

    // Member function to withdraw a specified amount from the wallet
    void Withdraw(double amount);

    // Member function to get the current balance of the wallet
    double GetBalance() const;

    // Member function to get the name of the wallet
    string GetName() const;
};
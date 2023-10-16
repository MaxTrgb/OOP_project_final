#include "Card.h"  
#include <iostream>  

Card::Card() {
    // Default constructor: Initialize member variables with default values
    cardName = "";
    cardBalance = 0.0;
    creditLimit = 0.0;
}

Card::Card(const string& cardName, double cardBalance, double creditLimit) {
    // Parameterized constructor: Initialize member variables with provided values
    this->cardName = cardName;
    this->cardBalance = cardBalance;
    this->creditLimit = creditLimit;
}

void Card::Deposit(double amount) {
    if (amount > 0) {
        // Deposit funds into the card's balance
        cardBalance += amount;
        cout << "\n\t\t\tDeposited " << amount << " into " << cardName << " card." << endl;
    }
}

void Card::MakePurchase(double amount) {
    if (amount > 0 && amount <= cardBalance + creditLimit) {
        // Check if the purchase amount is valid based on available balance and credit limit
        cardBalance -= amount;
        cout << "\n\t\t\tMade a purchase of " << amount << " using " << cardName << " card." << endl;
    }
    else {
        cout << "\n\t\t\tPurchase declined for " << cardName << " card due to insufficient balance/limit." << endl;
    }
}

double Card::CheckBalance() const {
    // Retrieve and return the current balance of the card
    return cardBalance;
}

string Card::GetName() const {
    // Retrieve and return the name of the card
    return cardName;
}
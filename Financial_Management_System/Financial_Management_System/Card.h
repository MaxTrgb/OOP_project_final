#pragma once
#include <string>
using namespace std;

class Card {
private:
    string cardName;        
    double cardBalance;     
    double creditLimit;     

public:
    // Default constructor for the Card class
    Card();

    // Constructor with parameters for the Card class
    Card(const string& cardName, double cardBalance, double creditLimit);

    // Member function to deposit a specified amount into the card
    void Deposit(double amount);

    // Member function to make a purchase with the card for a specified amount
    void MakePurchase(double amount);

    // Member function to check the current balance of the card
    double CheckBalance() const;

    // Member function to get the name of the card
    string GetName() const;
};
#pragma once
#include "Wallet.h"
#include "Card.h"
#include <vector>
#include <limits>
#include "RecordsRatings.h"
using namespace std;

class PersonalFinanceManager {
private:
    vector<Wallet> wallets;        // A vector to store instances of Wallet.
    vector<Card> cards;            // A vector to store instances of Card.
    RecordsRatings recordsRatings; // An instance of RecordsRatings to manage financial records.

public:
    void AddWallet(const string& name);
    void AddCard(const string& name, double limit);

    // Function to get a wallet by its name.
    Wallet* GetWallet(const string& name);

    // Function to get a card by its name.
    Card* GetCard(const string& name);

    // Function to display balances of all wallets.
    void ShowWalletBalances() const;

    // Function to display balances of all wallets and cards.
    void ShowAllBalances() const;

    // Function to wait for the user to press Enter.
    void WaitForEnter();

    // Function to check the balance of a specific wallet or card.
    void checkBalance();

    // Function to perform a deposit into a wallet or card.
    void deposit();
};

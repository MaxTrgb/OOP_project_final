#include "PersonalFinanceManager.h"
#include <iostream>

// Function to add a new wallet to the manager.
void PersonalFinanceManager::AddWallet(const string& name) {
    for (const Wallet& wallet : wallets) {
        if (wallet.GetName() == name) {
            cout << "\n\t\t\tA wallet with the name " << name << " already exists." << endl;
            WaitForEnter();
            return;
        }
    }

    Wallet newWallet(name);
    wallets.push_back(newWallet);
    cout << "\n\t\t\tAdded a new " << name << " wallet." << endl;
    WaitForEnter();
    return;
}

// Function to add a new card to the manager with a given name and credit limit.
void PersonalFinanceManager::AddCard(const string& name, double limit) {
    for (const Card& card : cards) {
        if (card.GetName() == name) {
            cout << "\n\t\t\tA card with the name " << name << " already exists." << endl;
            return;
        }
    }

    Card newCard(name, 0, limit);
    cards.push_back(newCard);
    cout << "\n\t\t\tAdded a new " << name << " card with a credit limit of " << limit << "." << endl;
    WaitForEnter();
    return;
}

// Function to get a wallet by its name.
Wallet* PersonalFinanceManager::GetWallet(const string& name) {
    for (Wallet& wallet : wallets) {
        if (wallet.GetName() == name) {
            return &wallet;
        }
    }
    return nullptr; // Return nullptr if the wallet is not found.
}

// Function to get a card by its name.
Card* PersonalFinanceManager::GetCard(const string& name) {
    for (Card& card : cards) {
        if (card.GetName() == name) {
            return &card;
        }
    }
    return nullptr; // Return nullptr if the card is not found.
}

// Function to display balances of all wallets.
void PersonalFinanceManager::ShowWalletBalances() const {
    cout << "\t\t\tWallet Balances:" << endl;
    for (const Wallet& wallet : wallets) {
        cout << "\t\t\t" << wallet.GetName() << ": " << wallet.GetBalance() << endl;
    }
}

// Function to display balances of all wallets and cards.
void PersonalFinanceManager::ShowAllBalances() const {
    cout << "\t\t\tWallet Balances:" << endl;
    for (const Wallet& wallet : wallets) {
        cout << "\t\t\t" << wallet.GetName() << ": " << wallet.GetBalance() << endl;
    }

    cout << "\t\t\tCard Balances:" << endl;
    for (const Card& card : cards) {
        cout << "\t\t\t" << card.GetName() << ": " << card.CheckBalance() << endl;
    }
}

// Function to wait for the user to press Enter.
void PersonalFinanceManager::WaitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(); // Ignore any previous newline characters.
    cin.get();    // Wait for the user to press Enter.
}

// Function to check the balance of a specific wallet or card.
void PersonalFinanceManager::checkBalance() {
    string name;
    cout << "\nEnter wallet/card name: ";
    cin >> name;

    Wallet* wallet = GetWallet(name);
    Card* card = GetCard(name);

    if (wallet || card) {
        double balance = wallet ? wallet->GetBalance() : card->CheckBalance();
        cout << "\n\t\t\tBalance for " << name << ": " << balance << endl;
    }
    else {
        cout << "\n\t\t\tWallet/Card not found." << endl;
    }
}

// Function to perform a deposit into a wallet or card.
void PersonalFinanceManager::deposit() {
    string name;
    double amount;

    cout << "Enter wallet/card name: ";
    cin >> name;

    Wallet* wallet = GetWallet(name);
    Card* card = GetCard(name);

    if (wallet || card) {
        cout << "Enter deposit amount: ";
        cin >> amount;

        if (wallet) {
            wallet->Deposit(amount);
        }
        else {
            card->Deposit(amount);
        }
    }
    else {
        cout << "\n\t\t\tWallet/Card not found." << endl;
    }
}
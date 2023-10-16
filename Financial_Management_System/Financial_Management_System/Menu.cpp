#include "Menu.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Constructor for the Menu class
Menu::Menu() {
    recordsRatings.LoadRecordsFromFile("expense_records.txt");
}

// Function to clear the console screen
void Menu::ClearConsole() const {
    cout << "\033[2J\033[H"; // This code clears the console screen.
}

// Function to start the menu and handle user input
void Menu::Run() {
    recordsRatings.currentDate(); // Set the current date.

    while (true) {
        DisplayMenu(); // Display the main menu.
        int choice;
        cin >> choice; // Get the user's choice.
        HandleChoice(choice); // Handle the user's choice.
    }
}

// Function to display the main menu
void Menu::DisplayMenu() const {
    ClearConsole();
    cout << "\n\t\t\tPersonal Finance Manager Menu:" << endl;
    cout << "\t\t\t1. Open balance" << endl;
    cout << "\t\t\t2. Transactions" << endl;
    cout << "\t\t\t3. Check Balance" << endl;
    cout << "\t\t\t4. Print Records" << endl;
    cout << "\t\t\t5. Display TOP-Week" << endl;
    cout << "\t\t\t6. Display TOP-Month" << endl;
    cout << "\t\t\t7. Exit" << endl;
    cout << "Enter your choice: ";
}

// Functions for sub-menus

// Function for the "Open Balance" sub-menu
int Menu::subMenuOpenB() {
    cout << "\t\t\t1. Add wallet" << endl;
    cout << "\t\t\t2. Add card" << endl;
    cout << "\t\t\t3. Return to main menu" << endl;
    int choice = 0;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Function for the "Transactions" sub-menu
int Menu::subMenuTransactions() {
    cout << "\t\t\t1. Deposit" << endl;
    cout << "\t\t\t2. Withdraw" << endl;
    cout << "\t\t\t3. Return to main menu" << endl;
    int choice = 0;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Function for the "Check Balance" sub-menu
int Menu::subMenuCheckB() {
    cout << "\t\t\t1. Check specific balance " << endl;
    cout << "\t\t\t2. Check all balances" << endl;
    cout << "\t\t\t3. Return to main menu" << endl;
    int choice = 0;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Function for the "Print Records" sub-menu
int Menu::subMenuPrecords() {
    cout << "\t\t\t1. Print Records by day" << endl;
    cout << "\t\t\t2. Print Records by month" << endl;
    cout << "\t\t\t3. Print Records by week" << endl;
    cout << "\t\t\t4. Return to main menu" << endl;
    int choice = 0;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Functions to handle sub-menu options

// Function to handle the "Open Balance" sub-menu
void Menu::openBalance() {
    int choice = subMenuOpenB();

    if (choice == 1) {
        ClearConsole();
        AddWallet();
    }
    else if (choice == 2) {
        ClearConsole();
        AddCard();
    }
    else if (choice == 3) {
        // Return to the main menu
    }
    else {
        ClearConsole();
        cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        WaitForEnter();
        return;
    }
}

// Function to handle the "Transactions" sub-menu
void Menu::Transactions() {
    int choice = subMenuTransactions();

    if (choice == 1) {
        ClearConsole();
        MakeDeposit();
    }
    else if (choice == 2) {
        ClearConsole();
        MakeWithdrawal();
        WaitForEnter();
        return;
    }
    else if (choice == 3) {
        // Return to the main menu
    }
    else {
        ClearConsole();
        cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        WaitForEnter();
        return;
    }
}

// Function to handle the "Check Balance" sub-menu
void Menu::checkBalanceMenu() {
    int choice = subMenuCheckB();

    if (choice == 1) {
        ClearConsole();
        CheckBalance();
    }
    else if (choice == 2) {
        ClearConsole();
        ShowAll();
    }
    else if (choice == 3) {
        // Return to the main menu
    }
    else {
        ClearConsole();
        cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        WaitForEnter();
        return;
    }
}

// Function to handle the "Print Records" sub-menu
void Menu::printRecordsMenu() {
    int choice = subMenuPrecords();

    if (choice == 1) {
        ClearConsole();
        recordsRatings.recordsByDay();
    }
    else if (choice == 2) {
        ClearConsole();
        recordsRatings.recordsByMonth();
    }
    else if (choice == 3) {
        ClearConsole();
        recordsRatings.recordsByWeek();
    }
    else if (choice == 4) {
        // Return to the main menu
    }
    else {
        ClearConsole();
        cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        WaitForEnter();
        return;
    }
}

// Function to handle the main menu choices
void Menu::HandleChoice(int choice) {
    switch (choice) {
    case 1:
        ClearConsole();
        openBalance();
        break;
    case 2:
        ClearConsole();
        Transactions();
        break;
    case 3:
        ClearConsole();
        checkBalanceMenu();
        break;
    case 4:
        ClearConsole();
        printRecordsMenu();
        break;
    case 5:
        recordsRatings.DisplayTopCostForWeek();
        WaitForEnter();
        return;
    case 6:
        recordsRatings.DisplayTopCostForMonth();
        WaitForEnter();
        return;
    case 7:
        recordsRatings.SaveRecordsToFile("expense_records.txt");
        exit(0); // Exit the program.
    default:
        ClearConsole();
        cout << "\n\t\t\tInvalid choice. Please try again." << endl;
        WaitForEnter();
        return;
    }
}

// Function to add a wallet to manage finances
void Menu::AddWallet() {
    string walletName;
    cout << "\nEnter wallet name: ";
    cin >> walletName;
    manager.AddWallet(walletName);
}

// Function to add a card to manage finances
void Menu::AddCard() {
    string cardName;
    double creditLimit;
    cout << "\nEnter card name: ";
    cin >> cardName;
    cout << "Enter credit limit: ";
    cin >> creditLimit;
    manager.AddCard(cardName, creditLimit);
}

// Function to perform a withdrawal transaction
void Menu::MakeWithdrawal() {
    string name;
    double amount;
    int category;
    Wallet* wallet = nullptr;  // Pointer to a wallet.
    Card* card = nullptr;      // Pointer to a card.

    int day = recordsRatings.getCurrentDay();
    int month = recordsRatings.getCurrentMonth();

    bool found = GetWalletOrCard(name, wallet, card);

    if (found) {
        cout << "Enter withdrawal amount: ";
        cin >> amount;

        category = GetCategory();

        if (wallet) {
            wallet->Withdraw(amount);
        }
        else {
            card->MakePurchase(amount);
        }

        RecordsRatings::ExpenseRecord record = { name, amount, category, day, month };
        recordsRatings.addExpenseRecord(record);
    }
    else {
        cout << "\t\t\tWallet/Card not found." << endl;
    }
}

// Function to get a wallet or card by name
bool Menu::GetWalletOrCard(string& name, Wallet*& wallet, Card*& card) {
    cout << "\nEnter wallet/card name: ";
    cin >> name;

    wallet = manager.GetWallet(name);
    card = manager.GetCard(name);

    return wallet || card;
}

// Function to get a category for financial transactions
int Menu::GetCategory() {
    int category;

    do {
        cout << "Choose category:\n1. Food\n2. Rent\n3. Online\n4. Other" << endl;
        cin >> category;
    } while (category < 1 || category > 4);

    return category;
}

// Function to perform a deposit
void Menu::MakeDeposit() {
    manager.deposit();
    WaitForEnter();
    return;
}

// Function to check the current balance
void Menu::CheckBalance() {
    manager.checkBalance();
    WaitForEnter();
    return;
}

// Function to show all financial records
void Menu::ShowAll() {
    manager.ShowAllBalances();
    WaitForEnter();
    return;
}

// Function to wait for the user to press Enter
void Menu::WaitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

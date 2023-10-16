    #pragma once
    #include <fstream>
    #include "PersonalFinanceManager.h"
    #include <vector>
    #include <limits>
    #include <cstdlib>
    #include "RecordsRatings.h"

// Define a structure to hold category expenses.
struct CategoryExpenses {
    int category;     // An identifier for the category.
    double totalAmount; // The total amount spent in this category.
};

class Menu {
private:
    // Private member variables for the Menu class.
    double topWeekTotal = 0.0;   
    double topMonthTotal = 0.0;  
    vector<CategoryExpenses> topWeekCategories; 
    vector<CategoryExpenses> topMonthCategories; 
    PersonalFinanceManager manager; 
    RecordsRatings recordsRatings;  

public:
    Menu(); // Constructor for the Menu class.
    void Run(); // A method to start the menu.

private:
    // Private member functions for the Menu class.
    void DisplayMenu() const; 
    void ClearConsole() const;
    void HandleChoice(int choice); 
    void openBalance(); 
    void Transactions(); 
    void checkBalanceMenu();
    void printRecordsMenu();
    void AddWallet(); 
    void AddCard();
    void MakeWithdrawal(); 
    void MakeDeposit();
    void CheckBalance(); 
    void ShowAll(); // Show all financial records.
    void WaitForEnter(); // Wait for the user to press Enter.
    int subMenuOpenB(); // Sub-menu for opening a balance.
    int subMenuTransactions(); // Sub-menu for financial transactions.
    int subMenuCheckB(); // Sub-menu for checking the balance.
    int subMenuPrecords(); // Sub-menu for printing financial records.
    bool GetWalletOrCard(string& name, Wallet*& wallet, Card*& card); // Helper function to get a wallet or card by name.
    int GetCategory(); // Get a category for financial transactions.
};
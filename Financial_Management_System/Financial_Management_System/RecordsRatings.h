#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class RecordsRatings {
public:
    struct ExpenseRecord {
        string name;       
        double amount;     
        int category;      
        int day;           
        int month;         
    };
    struct CategoryExpenses {
        int category;      // Category of expenses (e.g., food, rent)
        double totalAmount; // Total amount spent in this category
    };

private:
    int currentDay = 0;                      
    int currentMonth = 0;                    
    double topMonthTotal = 0.0;             // Total expenses for the current month
    vector<CategoryExpenses> topMonthCategories; // Categories with the highest expenses for the month
    vector<ExpenseRecord> expenseRecords;    // Records of expenses

public:
    // Getter and Setter functions for class members
    void setCurrentDay(int day);
    void setCurrentMonth(int month);
    double getTopMonthTotal() const;
    const vector<CategoryExpenses>& getTopMonthCategories() const;
    const vector<ExpenseRecord>& getExpenseRecords() const;
    int getCurrentDay() const;
    int getCurrentMonth() const;

    // Function to set the current date by taking user input
    void currentDate();

    // Setter functions
    void setTopMonthTotal(double total);
    void setExpenseRecords(const vector<ExpenseRecord>& records);

    // Functions to print tables for displaying records
    void tablePrint();
    void tableTwoPrint();
    void tableThreePrint();

    // Functions to load and save expense records to/from a file
    void LoadRecordsFromFile(const string& filename);
    void SaveRecordsToFile(const string& filename);

    // Functions to display expense records by day, month, and week
    void recordsByDay();
    void recordsByMonth();
    void recordsByWeek();

    // Function to switch and print expense category based on category ID
    void switchRecCat(ExpenseRecord record);

    // Function to sort categories by total expenses
    void SortCategoriesByTotal(std::vector<CategoryExpenses>& categories);

    // Functions to display the top expenses for a specific week or month
    void DisplayTopCostForWeek();
    void DisplayTopCostForMonth();

    // Function to get the name of an expense category based on the category ID
    string GetCategoryName(int category);

    // Function to add a new expense record to the list
    void addExpenseRecord(const ExpenseRecord& record);

    // Function to calculate the total expenses for a specific month
    double CalculateTotalExpensesForMonth(vector<CategoryExpenses>& topCategories);

    // Function to display the top expense categories for a specific period
    void DisplayTopCategories(const string& period, const vector<CategoryExpenses>& topCategories, double totalExpenses);

    // Function to calculate and display the top expenses for a specific week
    void CalculateTopWeekExpenses(double& topWeekTotal, vector<CategoryExpenses>& topWeekCategories, int startDay, int endDay);

    // Function to wait for the user to press Enter
    void WaitForEnter();
};

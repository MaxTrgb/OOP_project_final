        #include "RecordsRatings.h"
        #include <algorithm>
        #include <unordered_map>
        #include <string>

    void RecordsRatings::currentDate() {
        cout << "Enter current day: ";
        cin >> currentDay;
        cout << "Enter current month: ";
        cin >> currentMonth;
    }
    // Setter functions
    void RecordsRatings::setCurrentDay(int day) 
    {
        currentDay = day;
    }
    void RecordsRatings::setCurrentMonth(int month) 
    {
        currentMonth = month;
    }
    void RecordsRatings::setTopMonthTotal(double total) 
    {
        topMonthTotal = total;
    }
    void RecordsRatings::setExpenseRecords(const vector<RecordsRatings::ExpenseRecord>& records) 
    {
        expenseRecords = records;
    }

    // Getter functions
    double RecordsRatings::getTopMonthTotal() const 
    {
        return topMonthTotal;
    }
    const vector<RecordsRatings::CategoryExpenses>& RecordsRatings::getTopMonthCategories() const 
    {
        return topMonthCategories;
    }
    const vector<RecordsRatings::ExpenseRecord>& RecordsRatings::getExpenseRecords() const 
    {
        return expenseRecords;
    }
    int RecordsRatings::getCurrentDay() const 
    {
        return currentDay;
    }
    int RecordsRatings::getCurrentMonth() const 
    {
        return currentMonth;
    }
    string RecordsRatings::GetCategoryName(int category) {
        if (category == 1) {
            return "Food";
        }
        else if (category == 2) {
            return "Rent";
        }
        else if (category == 3) {
            return "Online";
        }
        else if (category == 4) {
            return "Other";
        }
        else {
            return "Unknown";
        }
    }

    // Load expense records from a file
    void RecordsRatings::LoadRecordsFromFile(const string& filename)
    {
        ifstream file(filename);

        if (!file.is_open())
        {
            // If the file does not exist, notify the user and return.
            cout << "File does not exist. No expense records loaded." << endl;
            return;
        }

        // Clear existing expense records.
        expenseRecords.clear();
        ExpenseRecord record;

        // Read data from the file and populate the expenseRecords vector.
        while (file >> record.name >> record.amount >> record.category >> record.day >> record.month)
        {
            expenseRecords.push_back(record);
        }

        file.close(); // Close the file.
    }

    // Save expense records to a file
    void RecordsRatings::SaveRecordsToFile(const string& filename)
    {
        ofstream file(filename);

        if (!file.is_open())
        {
            cerr << "Error: Unable to open the file for writing." << endl;
            return;
        }

        // Write expense records to the file in a structured format.
        for (const ExpenseRecord& record : expenseRecords)
        {
            file << record.name << "\t" << record.amount << "\t" << record.category << "\t" << record.day << "\t" << record.month << endl;
        }

        if (file.fail()) {
            cerr << "Error: Failed to write data to the file." << endl;
        }
        else {
            cout << "Expense records saved to " << filename << endl;
        }

        file.close(); // Close the file.
    }

    // Add an expense record to the records collection
    void RecordsRatings::addExpenseRecord(const ExpenseRecord& record) {
        // Add the provided expense record to the vector of expense records.
        expenseRecords.push_back(record);
    }

    // Functios to print table
    // Function to print a table header for expense records
    void RecordsRatings::tablePrint() {
        cout << "--------------------------------------------------------------" << endl;
        cout << "Name\tAmount\tCategory\tDay\tMonth" << endl;
        cout << "--------------------------------------------------------------" << endl;
    }
    // Function to print a separator in the table
    void RecordsRatings::tableTwoPrint() {
        cout << "--------------------------------------------------------------" << endl;
    }
    // Function to print the table headers for top categories
    void RecordsRatings::tableThreePrint() {
        cout << "--------------------------------------------------------------" << endl;
        cout << "Category\tTotal Amount" << endl;
        cout << "--------------------------------------------------------------" << endl;
    }

        // Display records functions 
    // Function to display expense records for a specific day
    void RecordsRatings::recordsByDay()
    {
        int searchDay = 0;
        int searchMonth = 0;
        cout << "Enter day to search: "; cin >> searchDay;
        cout << "Enter month to search: "; cin >> searchMonth;

        cout << "\nExpense Records by day " << searchDay << ":" << endl;
        tablePrint();

        for (const ExpenseRecord& record : expenseRecords) {
            if ((record.day == searchDay) && record.month == searchMonth)
            {
                cout << record.name << "\t" << record.amount << "\t";

                switchRecCat(record);

                cout << "\t" << record.month << endl;
            }
        }
        tableTwoPrint();
        WaitForEnter();
        return;

    }
    // Function to display expense records for a specific month
    void RecordsRatings::recordsByMonth()
    {
        int searchMonth = 0;
        cout << "Enter month to search: "; cin >> searchMonth;

        cout << "\nExpense Records by month " << searchMonth << ":" << endl;
        tablePrint();

        for (const ExpenseRecord& record : expenseRecords) {
            if (record.month == searchMonth)
            {
                cout << record.name << "\t" << record.amount << "\t";

                switchRecCat(record);

                cout << "\t" << record.day << endl;
            }
        }
        tableTwoPrint();
        WaitForEnter();
        return;

    }
    // Function to display expense records for a specific week of a month
    void RecordsRatings::recordsByWeek() {
        int searchWeek = 0;
        int searchMonth = 0;
        cout << "Enter week to search: "; cin >> searchWeek;
        cout << "Enter month to search: "; cin >> searchMonth;

        cout << "\nExpense Records by week " << searchWeek << " of the " << searchMonth << " month" << ":" << endl;
        tablePrint();

        for (const ExpenseRecord& record : expenseRecords) {
            int weekStartDay = (searchWeek - 1) * 7 + 1;
            int weekEndDay = searchWeek * 7;

            if ((record.day >= weekStartDay && record.day <= weekEndDay) && record.month == searchMonth) {
                cout << record.name << "\t" << record.amount << "\t";
                switchRecCat(record);
                cout << "\t" << record.day << endl;
            }
        }
        tableTwoPrint();
        WaitForEnter();
        return;

    }

    
    // Function to print the category name for an expense record
    void RecordsRatings::switchRecCat(ExpenseRecord record) {
        cout << GetCategoryName(record.category) << "\t";
    }

    // Function to sort expense categories by total amount in descending order
    void RecordsRatings::SortCategoriesByTotal(vector<CategoryExpenses>& categories) {
        sort(categories.begin(), categories.end(), [](const CategoryExpenses& a, const CategoryExpenses& b) {
            return a.totalAmount > b.totalAmount;
            });
    }

    // Calculate and display TOP

// Function to display the top expense categories for a specific week
    void RecordsRatings::DisplayTopCostForWeek() {
        int weekToDisplay;
        cout << "Enter the month: ";
        cin >> currentMonth;
        cout << "Enter the week of the month: ";
        cin >> weekToDisplay;

        // Create a vector to store category expenses, initialized with zeros
        vector<CategoryExpenses> topWeekCategories = {
            {1, 0.0},  // Food category
            {2, 0.0},  // Rent category
            {3, 0.0},  // Online category
            {4, 0.0}   // Other category
        };

        double topWeekTotal = 0.0;
        int startDay = (weekToDisplay - 1) * 7 + 1;  // Calculate the start day of the specified week
        int endDay = min(startDay + 6, 31);  // Calculate the end day of the specified week (assuming 31 days max)

        // Calculate and collect the top expenses for the specified week
        CalculateTopWeekExpenses(topWeekTotal, topWeekCategories, startDay, endDay);

        // Display the top categories and total expenses for the specified week
        DisplayTopCategories("Week " + to_string(weekToDisplay), topWeekCategories, topWeekTotal);
    }

    // Function to display the top expense categories for a specific month
    void RecordsRatings::DisplayTopCostForMonth() {
        cout << "Enter the month you want to display: ";
        cin >> currentMonth;

        // Create an unordered_map to store category totals
        unordered_map<int, double> categoryTotals;

        // Calculate total expenses for each category within the specified month
        for (const ExpenseRecord& record : expenseRecords) {
            if (record.month == currentMonth) {
                categoryTotals[record.category] += record.amount;
            }
        }

        // Convert the category totals into a vector of pairs for sorting
        vector<pair<int, double>> sortedCategories(categoryTotals.begin(), categoryTotals.end());

        // Sort categories in descending order of total expenses
        sort(sortedCategories.begin(), sortedCategories.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.second > b.second;
            });

        cout << "\nTop Categories for Month " << currentMonth << ":" << endl;
        tableThreePrint();

        // Display the top categories and their total expenses for the specified month
        for (int i = 0; i < min(3, static_cast<int>(sortedCategories.size())); i++) {
            int category = sortedCategories[i].first;
            string categoryName = GetCategoryName(category);

            cout << "\t" << categoryName << ":\t\t$" << sortedCategories[i].second << endl;
        }
        tableTwoPrint();
    }

    // Function to calculate the top expenses for a specific week and update the category totals
    void RecordsRatings::CalculateTopWeekExpenses(double& topWeekTotal, vector<CategoryExpenses>& topWeekCategories, int startDay, int endDay) {
        for (const ExpenseRecord& record : expenseRecords) {
            if (record.day >= startDay && record.day <= endDay && record.month == currentMonth) {
                topWeekTotal += record.amount;
                topWeekCategories[record.category - 1].totalAmount += record.amount;
            }
        }

        // Sort the category expenses in descending order to get the top categories
        SortCategoriesByTotal(topWeekCategories);
    }
    // Function to calculate the total expenses for a specific month and update the category totals
    double RecordsRatings::CalculateTotalExpensesForMonth(vector<CategoryExpenses>& topCategories) {
        double totalExpenses = 0.0;

        for (const ExpenseRecord& record : expenseRecords) {
            if (record.month == currentMonth && record.category >= 1 && record.category <= 4) {
                totalExpenses += record.amount;
                topCategories[record.category - 1].totalAmount += record.amount;
            }
        }
        return totalExpenses;
    }

    // Function to display the top categories and total expenses for a specific period
    void RecordsRatings::DisplayTopCategories(const string& period, const vector<CategoryExpenses>& topCategories, double totalExpenses) {
        cout << "\nTop Categories for " << period << " of " << currentMonth << ":" << endl;
        tableThreePrint();

        // Display the top categories and their total expenses, limited to the top 3 categories
        for (int i = 0; i < min(3, static_cast<int>(topCategories.size())); i++) {
            int category = topCategories[i].category;
            string categoryName = GetCategoryName(category);

            cout << "\t" << categoryName << ":\t\t$" << topCategories[i].totalAmount << endl;
        }

        cout << "--------------------------------------------------------------" << endl;
        cout << "Total Expenses for " << period << ": $" << totalExpenses << endl;
        cout << "--------------------------------------------------------------" << endl;
    }

    // Function to pause execution until the user presses Enter
    void RecordsRatings::WaitForEnter() {
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

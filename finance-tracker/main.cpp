#include <iostream>
#include "finance.h"
using namespace std;

int main() {
    int choice = 0;
    double balance = 0;

    while (choice != 4) {
        cout << "\n==== Personal Finance Tracker ====" << endl;
        cout << "1. Add Income" << endl;
        cout << "2. Add Expense" << endl;
        cout << "3. Show Balance" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addIncome(balance);
        else if (choice == 2) addExpense(balance);
        else if (choice == 3) showBalance(balance);
        else if (choice == 4) cout << "Goodbye!" << endl;
        else cout << "Invalid option." << endl;
    }

    return 0;
}

//Compile: g++ main.cpp finance.cpp -o finance
//Run: ./finance
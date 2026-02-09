#include <iostream>
using namespace std;

void addIncome(double &balance) {
    double income;
    cout << "Enter income amount: ";
    cin >> income;
    balance += income;
    cout << "Income added!" << endl;
}

void addExpense(double &balance) {
    double expense;
    cout << "Enter expense amount: ";
    cin >> expense;
    balance -= expense;
    cout << "Expense added!" << endl;
}

void showBalance(double balance) {
    cout << "Current balance: $" << balance << endl;
}
#include <iostream>
#include <vector>
using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};

int main() {
    vector<Item> inventory;
    int choice = 0;

    while (choice != 3) {
        cout << "\n==== Inventory Management System ====" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Show Items" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Item newItem;

            cout << "Enter item name: ";
            cin >> newItem.name;

            cout << "Enter quantity: ";
            cin >> newItem.quantity;

            cout << "Enter price: ";
            cin >> newItem.price;

            inventory.push_back(newItem);
            cout << "Item added successfully!" << endl;
        }
        else if (choice == 2) {
            if (inventory.empty()) {
                cout << "No items in inventory." << endl;
            } else {
                cout << "\n--- Inventory List ---" << endl;
                for (const auto &item : inventory) {
                    cout << item.name << " | Qty: "
                         << item.quantity << " | $"
                         << item.price << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}

//Compile: g++ filename.cpp -o inventory
//Run: ./inventory
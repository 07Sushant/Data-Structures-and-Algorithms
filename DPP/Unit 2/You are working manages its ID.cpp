// You are using GCC
#include <iostream>
using namespace std;

class Item {
public:
    int id;
    string name;
    int quantity;
    double price;
    Item* prev;
    Item* next;
};

class Inventory {
private:
    Item* head;

public:
    Inventory() {
        head = nullptr;
    }

    void insert(int id, string name, int quantity, double price) {
        Item* newItem = new Item();
        newItem->id = id;
        newItem->name = name;
        newItem->quantity = quantity;
        newItem->price = price;
        newItem->prev = nullptr;
        newItem->next = nullptr;

        if (head == nullptr) {
            head = newItem;
        } else {
            newItem->next = head;
            head->prev = newItem;
            head = newItem;
        }
    }

    bool searchItem(int searchId) {
        Item* current = head;
        while (current != nullptr) {
            if (current->id == searchId) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    Inventory inventory;

    for (int i = 0; i < n; i++) {
        int id, quantity;
        double price;
        string name;
        cin >> id;
        cin.ignore(); 
        getline(cin, name);
        cin >> quantity >> price;
        inventory.insert(id, name, quantity, price);
    }

    int searchId;
    cin >> searchId;

    if (inventory.searchItem(searchId)) {
        cout << "Item with ID " << searchId << " is present in the list." << endl;
    } else {
        cout << "Item with ID " << searchId << " is not found in the list." << endl;
    }

    return 0;
}


//Sushant

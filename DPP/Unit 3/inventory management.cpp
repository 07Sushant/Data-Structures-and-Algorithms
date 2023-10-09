#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Book {
    string title;
    int quantity;
    int priority;

    bool operator<(const Book& other) const {
        return priority > other.priority;
    }
};

int main() {
    priority_queue<Book> inventory;

    while (true) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            string title;
            int quantity, priority;
            cin.ignore(); // Clear the newline character from the previous input
            getline(cin, title);
            cin >> quantity >> priority;
            
            Book book;
            book.title = title;
            book.quantity = quantity;
            book.priority = priority;
            
            inventory.push(book);
            
            cout << "Book added to the inventory." << endl;
        } else if (choice == 2) {
            if (inventory.empty()) {
                cout << "No books in the inventory." << endl;
            } else {
                Book book = inventory.top();
                inventory.pop();
                cout << "Restocked book: " << book.title << endl;
            }
        } else if (choice == 3) {
            if (inventory.empty()) {
                cout << "No books in the inventory." << endl;
            } else {
                Book book = inventory.top();
                cout << "Next book to restock: " << book.title << endl;
            }
        } else if (choice == 4) {
            cout << "Exiting the application." << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}

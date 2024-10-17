#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract class for library items
class LibraryItem {
public:
    virtual void checkout() = 0;       // Pure virtual function for checkout
    virtual void returnItem() = 0;     // Pure virtual function for returning item
    virtual string getDetails() const = 0; // Pure virtual function for getting details
    virtual bool isAvailable() const = 0;  // Check availability

    virtual ~LibraryItem() {} // Virtual destructor
};

// Derived class for Book
class Book : public LibraryItem {
private:
    string title;
    string author;
    bool available;

public:
    Book(string t, string a) : title(t), author(a), available(true) {}

    void checkout() override {
        if (available) {
            available = false;
            cout << "You have checked out: " << title << endl;
        } else {
            cout << "Sorry, " << title << " is currently unavailable." << endl;
        }
    }

    void returnItem() override {
        available = true;
        cout << "You have returned: " << title << endl;
    }

    string getDetails() const override {
        return "Book - Title: " + title + ", Author: " + author;
    }

    bool isAvailable() const override {
        return available;
    }
};

// Derived class for Magazine
class Magazine : public LibraryItem {
private:
    string title;
    int issueNumber;
    bool available;

public:
    Magazine(string t, int issue) : title(t), issueNumber(issue), available(true) {}

    void checkout() override {
        if (available) {
            available = false;
            cout << "You have checked out: " << title << " (Issue " << issueNumber << ")" << endl;
        } else {
            cout << "Sorry, " << title << " (Issue " << issueNumber << ") is currently unavailable." << endl;
        }
    }

    void returnItem() override {
        available = true;
        cout << "You have returned: " << title << " (Issue " << issueNumber << ")" << endl;
    }

    string getDetails() const override {
        return "Magazine - Title: " + title + ", Issue Number: " + to_string(issueNumber);
    }

    bool isAvailable() const override {
        return available;
    }
};

// Derived class for DVD
class DVD : public LibraryItem {
private:
    string title;
    int duration; // Duration in minutes
    bool available;

public:
    DVD(string t, int d) : title(t), duration(d), available(true) {}

    void checkout() override {
        if (available) {
            available = false;
            cout << "You have checked out: " << title << " (Duration: " << duration << " minutes)" << endl;
        } else {
            cout << "Sorry, " << title << " is currently unavailable." << endl;
        }
    }

    void returnItem() override {
        available = true;
        cout << "You have returned: " << title << endl;
    }

    string getDetails() const override {
        return "DVD - Title: " + title + ", Duration: " + to_string(duration) + " minutes";
    }

    bool isAvailable() const override {
        return available;
    }
};

// Function to display options and perform operations
void libraryMenu(vector<LibraryItem*>& items) {
    int choice;
    do {
        cout << "\nLibrary Management System Menu:\n";
        cout << "1. View Items\n";
        cout << "2. Check Out Item\n";
        cout << "3. Return Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // View Items
                cout << "Available Items:\n";
                for (size_t i = 0; i < items.size(); ++i) {
                    cout << i + 1 << ". " << items[i]->getDetails();
                    if (!items[i]->isAvailable()) {
                        cout << " (Checked Out)";
                    }
                    cout << endl;
                }
                break;
            }
            case 2: { // Check Out Item
                int index;
                cout << "Enter the item number to check out: ";
                cin >> index;
                if (index > 0 && index <= items.size()) {
                    items[index - 1]->checkout();
                } else {
                    cout << "Invalid item number.\n";
                }
                break;
            }
            case 3: { // Return Item
                int index;
                cout << "Enter the item number to return: ";
                cin >> index;
                if (index > 0 && index <= items.size()) {
                    items[index - 1]->returnItem();
                } else {
                    cout << "Invalid item number.\n";
                }
                break;
            }
            case 4: // Exit
                cout << "Exiting the system. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

int main() {
    // Creating a collection of library items
    vector<LibraryItem*> items;
    items.push_back(new Book("The Great Gatsby", "F. Scott Fitzgerald"));
    items.push_back(new Magazine("National Geographic", 2023));
    items.push_back(new DVD("Inception", 148));

    // Start the library menu
    libraryMenu(items);

    // Clean up memory
    for (LibraryItem* item : items) {
        delete item;
    }

    return 0;
}

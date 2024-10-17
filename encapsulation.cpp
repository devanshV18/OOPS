#include <iostream>
using namespace std;

class BankAccount {
private:
    // Private attributes
    string accountNumber;
    double balance;

public:
//public properties
    string accountHolderName;

    // Constructor
    BankAccount(string accNumber, double initialBalance, string name) {
        accountNumber = accNumber;
        balance = initialBalance;
        accountHolderName = name;
    }

    // Public method to deposit money (SETTER FOR PVT MEMBER BALANCE)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Deposit amount should be positive." << endl;
        }
    }

    // Public method to withdraw money (SETTER FOR PVT MEMBER BALANCE)
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Invalid withdraw amount." << endl;
        }
    }

    // Public method to get the current balance (GETTER FOR PVT MEMBER BALANCE)
    double getBalance() {
        return balance;
    }

    // Public method to get the account number (GETTER FOR PVT MEMBER ACC NO.)
    string getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    // Create a new bank account
    BankAccount account("123456789", 1000.0, "Devansh verma");

    //ACCOUNT HOLDER'S NAME 
    cout << account.accountHolderName << endl;

    // Check initial balance
    cout << "Initial Balance: " << account.getBalance() << endl;

    // Deposit money
    account.deposit(500);

    //balance after deposit
    cout << "Balance after deposit: " << account.getBalance() << endl;

    // Withdraw money
    account.withdraw(300);

    //balance after withdrawl
    cout << "Balance after withdrawal: " << account.getBalance() << endl;

    // Trying to access private attributes directly would cause an error:
    // account.balance;  // Not allowed as 'balance' is private

    return 0;
}

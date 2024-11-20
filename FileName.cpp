#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account {
protected:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    Account(string name, int number, double initialBalance)
        : accountHolder(name), accountNumber(number), balance(initialBalance) {}

    virtual ~Account() {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        }
        else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
        else {
            cout << "Insufficient funds or invalid withdrawal amount." << endl;
        }
    }

    void viewBalance() const {
        cout << "Current balance for account " << accountNumber << ": " << balance << endl;
    }

    virtual void applyInterest() {
        cout << "Interest application not supported for this account type." << endl;
    }

    virtual void displayAccountInfo() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string name, int number, double initialBalance, double rate)
        : Account(name, number, initialBalance), interestRate(rate) {}

    void applyInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest applied at rate " << interestRate << "%. New balance: " << balance << endl;
    }

    void displayAccountInfo() const override {
        Account::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    Account* acc1 = new Account("John Doe", 12345, 1000.0);
    SavingsAccount* acc2 = new SavingsAccount("Alice Smith", 67890, 2000.0, 3.5);

    cout << "Account 1 info:" << endl;
    acc1->displayAccountInfo();
    cout << endl;

    cout << "Account 2 info:" << endl;
    acc2->displayAccountInfo();
    cout << endl;

    acc1->deposit(500);
    acc1->withdraw(200);
    acc1->viewBalance();

    cout << endl;

    acc2->deposit(1000);
    acc2->withdraw(500);
    acc2->applyInterest();
    acc2->viewBalance();

    delete acc1;
    delete acc2;

    return 0;
}

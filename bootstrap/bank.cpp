
#include <stdio.h>
#include <stdlib.h>

// Structure for bank account
typedef struct {
    int accountNumber;
    char accountHolderName[50];
    float balance;
} BankAccount;

// Function to create a new bank account
BankAccount createAccount() {
    BankAccount account;
    printf("Enter account number: ");
    scanf("%d", &account.accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", account.accountHolderName);
    account.balance = 0.0;
    return account;
}

// Function to deposit money into an account
void depositMoney(BankAccount *account) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    account->balance += amount;
    printf("Deposit successful. New balance: %.2f\n", account->balance);
}

// Function to withdraw money from an account
void withdrawMoney(BankAccount *account) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > account->balance) {
        printf("Insufficient balance.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", account->balance);
    }
}

// Function to display account details
void displayAccountDetails(BankAccount account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder Name: %s\n", account.accountHolderName);
    printf("Balance: %.2f\n", account.balance);
}

int main() {
    BankAccount account = createAccount();
    int choice;
    while (1) {
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Display Account Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                depositMoney(&account);
                break;
            case 2:
                withdrawMoney(&account);
                break;
            case 3:
                displayAccountDetails(account);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
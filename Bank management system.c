#include <stdio.h>

typedef struct BankAccount {
    char accountNumber[20];
    char accountHolderName[100];
    float balance;
} BankAccount;

void displayAccountInfo(BankAccount account) {
    printf("Account Number: %s\n", account.accountNumber);
    printf("Account Holder Name: %s\n", account.accountHolderName);
    printf("Balance: $%.2f\n", account.balance);
}

void deposit(BankAccount *account, float amount) {
    account->balance += amount;
}

void withdraw(BankAccount *account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawn $%.2f\n", amount);
    } else {
        printf("Insufficient funds to withdraw $%.2f\n", amount);
    }
}

int main() {
    BankAccount account = {"1234567890", "John Doe", 1000.00};

    printf("Initial Account Information:\n");
    displayAccountInfo(account);

    float depositAmount = 500.00;
    printf("\nDepositing $%.2f\n", depositAmount);
    deposit(&account, depositAmount);
    displayAccountInfo(account);

    float withdrawAmount = 200.00;
    printf("\nWithdrawing $%.2f\n", withdrawAmount);
    withdraw(&account, withdrawAmount);
    displayAccountInfo(account);

    float insufficientWithdrawAmount = 10000.00;
    printf("\nWithdrawing $%.2f (insufficient funds)\n", insufficientWithdrawAmount);
    withdraw(&account, insufficientWithdrawAmount);
    displayAccountInfo(account);

    return 0;
}
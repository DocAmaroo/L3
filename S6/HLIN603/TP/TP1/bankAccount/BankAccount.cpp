#include <iostream>
#include "BankAccount.h"

using namespace std;

// Bank Account
BankAccount::BankAccount() : balance(1000) {}
BankAccount::~BankAccount(){ cout << getBalance() << endl; }

double BankAccount::getBalance(){ return balance; }
void BankAccount::setBalance(double sum){ balance = sum; }
void BankAccount::deposit(double sum){ setBalance( getBalance() + sum );}

// PaidAccount
PaidAccount::PaidAccount() : balance(1000),bonus(0.10){}
PaidAccount::~PaidAccount(){ setBalance(getBalance()*(1+bonus)); }

void PaidAccount::deposit(double sum){ setBalance( getBalance() + sum + (0.1*sum) );}

// PaidAccountWithCreditCard
PaidAccountWithCreditCard::PaidAccountWithCreditCard() : balance(1000), charges(0.10){}
PaidAccountWithCreditCard::~PaidAccountWithCreditCard(){ setBalance(getBalance()-charges); }


// DepositAccount
DepositAccount::DepositAccount() : balance(1000), charges(100){}
DepositAccount::~DepositAccount(){ setBalance(getBalance() - charges); }

void DepositAccount::deposit(double sum){
    double balance = getBalance();
    if ( balance > 1000 ){
        setBalance( balance + sum + 10 );
    }else{
        setBalance( balance + sum - 1 );
    }
}

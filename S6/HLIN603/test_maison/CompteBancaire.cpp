#include <iostream>
#include "CompteBancaire.h"

using namespace std;

// Bank Account
BankAccount::BankAccount() : balance(1000) {}
BankAccount::~BankAccount(){ cout << "BA : " << getBalance() << endl; }

double BankAccount::getBalance(){ return balance; }
void BankAccount::setBalance(double sum){ balance = sum; }
void BankAccount::deposit(double sum){ setBalance( getBalance() + sum );}

// PaidAccount
PaidAccount::PaidAccount() : balance(1000),bonus(0.10){}
PaidAccount::~PaidAccount(){ getBalance()*(1+bonus); }

void PaidAccount::deposit(double sum){ setBalance( getBalance()*(1+bonus) );}

// DepositAccount
DepositAccount::DepositAccount() : balance(1000), charges(100){}
DepositAccount::~DepositAccount(){ getBalance() - charges; }

void DepositAccount::deposit(double sum){ setBalance( getBalance() - charges; );}
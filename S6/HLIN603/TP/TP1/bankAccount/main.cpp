#include <iostream>
#include "BankAccount.h"

using namespace std;

int main(int argc, const char** argv) {

    // BankAccount BA;
    // PaidAccount PA;
    // PaidAccountWithCreditCard PAC;
    // DepositAccount DA;

    // BA.deposit(100);
    // PA.deposit(100);
    // PAC.deposit(100);
    // DA.deposit(100);
    
    // delete BA;
    // delete PA;
    // delete PAC;
    // delete DA;

    int n = 4;
    BankAccount* VP_account[n];
    VP_account[0] = new BankAccount();
    VP_account[1] = new PaidAccount();
    VP_account[2] = new DepositAccount();
    VP_account[3] = new PaidAccountWithCreditCard();

    for(int i=0; i < n; i++){
        VP_account[i]->deposit(1000);
        cout << VP_account[i]->getBalance() << endl;
    }

    delete *VP_account;

    return 0;
}

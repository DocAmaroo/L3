#include <iostream>
#include "BankAccount.h"

using namespace std;

int main(int argc, const char** argv) {

    BankAccount BA;
    PaidAccount PA;
    PaidAccountWithCreditCard PAC;
    DepositAccount DA;

    BA.deposit(100);
    PA.deposit(100);
    PAC.deposit(100);
    DA.deposit(100);
    
    BankAccount* VP_account[2];
    VP_account[0] = new PaidAccount();
    VP_account[1] = new DepositAccount();

    for(int i=0; i < 2; i++){
        VP_account[i]->deposit(1000);
    }

    return 0;
}

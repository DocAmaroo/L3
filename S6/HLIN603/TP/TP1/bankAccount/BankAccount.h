#ifndef _BANK_ACCOUNT_
#define _BANK_ACCOUNT_

class BankAccount{

    private :
        double balance;

    public :
        BankAccount();
        virtual ~BankAccount();

        //accessor
        virtual double getBalance();
        virtual void setBalance(double);

        void deposit(double);
};

class PaidAccount : public virtual BankAccount{

    private :
        double balance;
        double bonus;
        
    public :
        PaidAccount();
        virtual ~PaidAccount();
        void deposit(double);
};

class DepositAccount : public virtual BankAccount{

    private :
        double balance;
        double charges;
        
    public :
        DepositAccount();
        virtual ~DepositAccount();
        void deposit(double);
};


class PaidAccountWithCreditCard : public virtual BankAccount{

    private :
        double balance;
        double charges;
        
    public :
        PaidAccountWithCreditCard();
        virtual ~PaidAccountWithCreditCard();
};

#endif // !_BANK_ACCOUNT_
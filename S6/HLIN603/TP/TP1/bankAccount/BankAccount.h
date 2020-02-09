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

        virtual void deposit(double);
};

class PaidAccount : public virtual BankAccount{

    private :
        double balance;
        double bonus;
        
    public :
        PaidAccount();
        virtual ~PaidAccount();
        virtual void deposit(double);
};

class PaidAccountWithCreditCard : public virtual PaidAccount{

    private :
        double balance;
        double charges;
        
    public :
        PaidAccountWithCreditCard();
        virtual ~PaidAccountWithCreditCard();
};

class DepositAccount : public virtual BankAccount{

    private :
        double balance;
        double charges;
        
    public :
        DepositAccount();
        virtual ~DepositAccount();
        virtual void deposit(double);
};

#endif // !_BANK_ACCOUNT_
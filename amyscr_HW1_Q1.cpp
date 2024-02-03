#include <iostream>
using namespace std;
#include <string>

struct Check
{
    int checkNum = 1;
    string checkMemo = {" "};
    float checkAmount = 0.0;
};

const int N = 5;

class CheckBook{
public:
    CheckBook(): balance(0), numOfChecks(0){} //default constructor
    CheckBook(float initBalance): balance(initBalance), numOfChecks(0){}

    Check checks[N];

    float deposit(float amount);
    void DisplayChecks();

    bool writeCheck(float amount); //basically a setter fcn

private:
    float balance; //keep track of balance
    float lastDeposit; //last deposited amt
    int numOfChecks;
    int checkLimit = N;
};

float CheckBook::deposit(float amount)
{
    balance=balance+amount;
    lastDeposit = amount;
    return balance;
}

void CheckBook::DisplayChecks()
{
    for(int i=numOfChecks; i>0; i--)
    {
       cout<<"Checks in order:";
       cout<<checks[i].checkNum<<"   "<<checks[i].checkMemo<<"   $"<<checks[i].checkAmount<<endl;
    }
}

bool CheckBook::writeCheck(float amount)
{
    if(balance>=amount)
    {
        //update numofchecks
        numOfChecks++;
        //add amount info to check
        checks[numOfChecks].checkAmount = amount;
        //ask
        cout<<"\nCheck Memo: ";
        cin.ignore();
        getline(cin,checks[numOfChecks].checkMemo);
        //cin>>checks[numOfChecks].checkMemo;

        //set checknum
        checks[numOfChecks].checkNum = numOfChecks;
        //update balance
        balance = balance - amount;
        return true;
    }
    else
    {
        cout<<"Cannot write check for that amount. Try a lower amount next time."<<endl;
        return false;
    }
}



int main()
{
    float localAmount = 0;
    char userOption;
    bool exitBank = false;

    CheckBook Balance, Balance2(500);

    cout<<"Give initial balance: "; cin>>localAmount;
    Balance.deposit(localAmount);

    while(exitBank == false)
    {
        cout<<"\nHit 'd' to deposit, 's' to display all checks, 'w' to write check, and 'e' to exit."<<endl;
        cin>>userOption;
        if(userOption == 'd')
        {
            cout<<"\nGive deposit amount: "; cin>>localAmount;
            Balance.deposit(localAmount);
        }
        if(userOption == 's')
        {
            Balance.DisplayChecks();
        }
        if(userOption == 'w')
        {
            cout<<"Writing check... "<<endl;
            cout<<"How much is the check for? "; cin>>localAmount;
            Balance.writeCheck(localAmount);
        }
        if(userOption == 'e')
        {
            exitBank = true;
        }
    }
    return 0;
}

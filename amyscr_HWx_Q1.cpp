#include <iostream>
using namespace std;

struct Check
{
    int checkNum = 1;
    string checkMemo = "";
    float checkAmount = 0.0;
};

const int N = 5;

class CheckBook{
public:
    CheckBook(): balance(0), numOfChecks(0){} //default constructor
    CheckBook(float initBalance): balance(initBalance), numOfChecks(0){}

    Check checks[N];

    void deposit(float amount){balance=balance+amount; numOfChecks++;}
    void DisplayChecks();

    bool writeCheck(float amount); //basically a setter fcn
private:
    float balance; //keep track of balance
    float lastDeposit; //last deposited amt
    int numOfChecks;
    int checkLimit = N;
};

bool CheckBook::writeCheck(float amount)
{
    //ask
    cout<<"Check amount? "; cin>>Check.checkAmount;
    cout<<"\nCheck Memo? "; cin>>Check.checkMemo;
    //set checknum with numofchecks from checkbook
    //update balance
    balance = balance + Check.checkAmount;
    //update numofchecks
    if(balance>amount)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CheckBook::DisplayChecks()
{
    for(int i=0; i<numOfChecks; i++)
    {
        cout<<Check.checkNum;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
    CheckBook check1, check2(2);

    //CheckBook check3(deposit());
}

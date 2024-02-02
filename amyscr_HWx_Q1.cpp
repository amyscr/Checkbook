#include <iostream>

using namespace std;

struct Check
{
    int checkNum;
    string checkMemo;
    float checkAmount;
};

class CheckBook{
public:
    CheckBook(): balance(0), numOfChecks(0){} //default constructor
    CheckBook(float initBalance): balance(initBalance), numOfChecks(0){}

    const int n = 5;
    Check checks[n];

    void deposit(float amount){balance=balance+amount;}
    void DisplayChecks(Check checks);

    bool writeCheck(float amount);
private:
    float balance; //balance to keep track of balance
    float lastDeposit; //last deposited amt
    int numOfChecks;
    int checkLimit = n;
};

void CheckBook::DisplayChecks()
{

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
    CheckBook check1, check2(2);
}

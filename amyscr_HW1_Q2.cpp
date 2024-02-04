#include <iostream>
using namespace std;
#include <string>

class Check
{
public:
    Check():checkNum(0), checkMemo(""), checkAmount(0){number++;} //increments number
    static int number;

    int getCheckNum()const{return checkNum;}
    int setCheckNum(int num){return checkNum;}

    string getCheckMemo()const{return checkMemo;}
    string setCheckMemo(string memo){return checkMemo;}

    float getCheckAmount()const{return checkAmount;}
    float setCheckAmount(float amt){return checkAmount;} //all get/set fcns should be done

    int checkNum = 0;
    string checkMemo = {" "};
    float checkAmount = 0.0;
};


/*************/

const int N = 5;

class CheckBook{
public:
    CheckBook(): balance(0), numOfChecks(0){} //default constructor
    CheckBook(float initBalance): balance(initBalance), numOfChecks(0){}

    Check checks[N];
    float deposit(float amount);
    void displayChecks();

    static int allChecks;
    int getAllChecks(){return allChecks;} //returns all checks

    bool writeCheck(float amount);

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


//work here
void CheckBook::displayChecks()
{
    for(int i=(numOfChecks-1); i>=0; i--)
    {
       //cout<<"Checks in order:";
       cout<<checks[i].checkAmount<<"   "<<checks[i].checkNum<<"   "<<checks[i].checkMemo<<endl;
    }
}



bool CheckBook::writeCheck(float amount)
{
    if(((numOfChecks < N) && (allChecks < 10)) && (amount<=balance))
    {
        //update numofchecks and allChecks


        //add amount info to check
        checks[numOfChecks].checkAmount = amount;
        //ask
        cout<<"\nmemo?"<<endl; cin>>checks[numOfChecks].checkMemo;
        //cin.ignore();
        //getline(cin,checks[numOfChecks].checkMemo);

        //set checknum
        checks[numOfChecks].checkNum = numOfChecks;
        //update balance
        balance = balance - amount;

        numOfChecks++;
        allChecks++;
        return true;
    }
    else
    {
        //cout<<"Cannot write check for that amount. Try a lower amount next time."<<endl;
        return false;
    }
}
//function should let you write checks when numOf Checks < N and allChecks < 10 and you have enough balance
//returns false if any of the three conditions are not met
//increment one to numofchecks and allchecks within this fcn

//c++ forbids initializing a static int within a class
int Check::number = 0;
int CheckBook::allChecks = 0;

int main() //this is bare minimum for main, try to work the code around this
{
    CheckBook cb1(1000), cb2(500);
    for(int i=0; i<10;i++)
    {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }

    cout<<"cb1 check details"<<endl;
    cb1.displayChecks();
    cout<<"cb2 check details"<<endl;
    cb2.displayChecks();
    cout<<cb1.getAllChecks()<<endl;
    cout<<cb2.getAllChecks()<<endl;

    return 0;
}


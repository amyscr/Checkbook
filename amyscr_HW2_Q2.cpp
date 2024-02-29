/*************************************************************************
** Author : Amy Scripture
** Program : hw2, q2
** Date Created : February 23, 2024
** Date Last Modified : February 23, 2024
** Usage : Digital Checkbook
**
** Problem: Create checkbook and checkbook test, a way to update members

Accept balance from user
Create checks until balance is exhausted
Double size of checkbook each time
Print checks
*************************************************************************/
#include <string>
#include <iostream>
using namespace std;

struct Check
{
    int checkNum;
    string checkMemo;
    float checkAmount;
    bool operator >(const Check &obj);
    friend ostream& operator <<(ostream &out, Check &phrase)
    {
    out<<phrase.checkAmount<<"   "<<phrase.checkMemo<<"   "<<phrase.checkNum<<endl;
    return out;
    }
};
//returns true if this instance is bigger
bool Check::operator >(const Check &obj)
{
    return checkAmount>obj.checkAmount;
}


/*************************/

class CheckBook
{
public:
    //constructors
    CheckBook(): balance(0), numOfChecks(0), checkBookSize(4){} //initialize pointer
    CheckBook(float initBalance): balance(initBalance), numOfChecks(0), checkBookSize(4){balance=initBalance; chkPtr = new Check[checkBookSize];}
    //copy constructor
    CheckBook(const CheckBook &obj)
    {
        balance=obj.balance;
        lastDeposit=obj.lastDeposit;
        numOfChecks=obj.numOfChecks;
        checkBookSize=obj.checkBookSize;
        chkPtr=new Check[checkBookSize];
        for(int i=0;i<numOfChecks;i++)
        {
            chkPtr[i] = obj.chkPtr[i];//for every new, a new struct obj is created via ptr array
        }
    }
    //destructor
    ~CheckBook(){delete[] chkPtr;} //initialize pointer

    //getters
    float const getBalance (){return balance;}
    float const getLastDeposit(){return lastDeposit;}
    int const getNumOfChecks(){return numOfChecks;}
    int const getCheckBookSize(){return checkBookSize;}

    //setters
    void setBalance(float amount){balance = balance + amount;}
    void setLastDeposit(float currentDeposit){lastDeposit = currentDeposit;}
    void setNumOfChecks(){numOfChecks++;}
    void setCheckBookSize(){checkBookSize*=2;}

    //other fcns
    void deposit(float amount);//adds desired amount to current balance
    bool writeCheck(Check c_amount);
    void const displayChecks();

    //overloaded assignment operators
    operator =(Check &obj);
    operator <<(Check &obj);

    //string of reasons in class to avoid reinitializing
    Check chkArray[250]; //array

private:
    Check *chkPtr; //pointer to array of checks, capacity is checkBookSize

    float balance;
    float lastDeposit;
    int numOfChecks;
    int checkBookSize;
};

/***************/

CheckBook::operator =(Check &obj)
{
    obj.checkAmount=balance; //change later
}

void CheckBook::deposit(float amount)
{
    balance=balance+amount;
    lastDeposit = amount;
}


bool operator <=(Check &obj, float balance)
{
    if(obj.checkAmount < balance)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*****************/


bool CheckBook::writeCheck(Check c_amount)
{
    if(c_amount<=balance)
    {

        numOfChecks++;
        cout<<"Writing check "<<numOfChecks<<"..."<<endl;
        //check memo
        string reasons[10] = {"ring", "isopods", "legos", "chocolate", "guitar", "gouache", "birthday", "fine art", "glass tumblers", "cabin rental"};
        c_amount.checkMemo = reasons[(rand())%10];

        //check amount
        balance = balance - c_amount.checkAmount;

        //checknum
        c_amount.checkNum = numOfChecks;

        chkArray[numOfChecks] = c_amount;



        //check if should double checkbook
        if(numOfChecks>=(checkBookSize/2))
        {
            checkBookSize *= 2;
            Check* newArray = new Check[checkBookSize];
            cout<<"Halfway through checkbook, new checkbook on the way!"<<endl;
            chkPtr = newArray;
        }
    }
    else
    {
        cout<<"Could not write check."<<endl;
        return false;
    }
}

void const CheckBook::displayChecks()
{
    cout<<"Checks: ";
    cout<<numOfChecks<<endl;
    for(int i=(numOfChecks); i>0; i--) //goes backwards
    {
       //cout<<"Checks in order:";
       cout<<chkArray[i].checkAmount<<"   "<<chkArray[i].checkNum<<"   "<<chkArray[i].checkMemo<<endl;
    }
}
Check c_amount;
void checkTest(CheckBook &obj, float balance)
{
    c_amount.checkAmount = 50;
    cout<<"Check amount: "<<c_amount.checkAmount<<endl;
    while(c_amount <= obj.getBalance())
    {
        obj.writeCheck(c_amount);

    }
}


/*********************/

int main()
{
    float amt;
    CheckBook cb1;
    cout<<"Enter your initial balance."<<endl;
    cin>>amt;
    cb1.setBalance(amt);

    checkTest(cb1, amt);
    cb1.displayChecks();
    return 0;
}

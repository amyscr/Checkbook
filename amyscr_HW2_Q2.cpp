/*************************************************************************
** Author : Amy Scripture
** Program : hw2, q2
** Date Created : February 23, 2024
** Date Last Modified : February 23, 2024
** Usage : Digital Checkbook
**
** Problem: Create checkbook and checkbook test, a way to update members

Accept the following information from the user (keyboard):
- Hw1, hw2 and hw3 (out of 100)
- Midterm (out of 100)
- Final exam (out of 100)
Calculate the total grade out of 100 based on the following grading scale:
Hws --> 30% (10% each)
Midterm --> 30%
Final Exam --> 40%
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
};
//returns true if this instance is bigger
bool Check::operator >(const Check &obj)
{
    return checkAmount>obj.checkNum;
}

ostream& operator <<(ostream &out, Check &phrase)
{
    out<<phrase.checkAmount<<"   "<<phrase.checkMemo<<"   "<<phrase.checkNum<<endl;
    return out;
}

/*************************/

class CheckBook
{
public:
    //constructors
    CheckBook(): balance(0), numOfChecks(0), checkBookSize(4){} //initialize pointer
    CheckBook(float initBalance): balance(initBalance), numOfChecks(0), checkBookSize(4){balance=initBalance; chkPtr = new Check[checkBookSize];}
    //copy constructor
    CheckBook(const CheckBook &obj){balance=obj.balance; lastDeposit=obj.lastDeposit; numOfChecks=obj.numOfChecks; checkBookSize=obj.checkBookSize; chkPtr=obj.chkPtr;}
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

private:
    Check *chkPtr; //array of checks, capacity is checkBookSize
    float balance;
    float lastDeposit;
    int numOfChecks;
    int checkBookSize;
};

/***************/
/***constructors, overloaded operators*****/
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
/**other fncs*****/


bool CheckBook::writeCheck(Check c_amount)
{
    cout<<"Inside writeCheck function."<<endl;
    if(c_amount<=balance)
    {
        //check memo
        string reasons[10] = {"ring", "isopods", "legos", "chocolate", "guitar", "gouache", "birthday", "fine art", "glass tumblers", "cabin"};
        c_amount.checkMemo = reasons[(rand())%10];

        //init struct members
        cout<<c_amount.checkMemo<<endl;
        c_amount.checkNum = numOfChecks;
        //chkPtr[numOfChecks] = c_amount;
        numOfChecks++;

        balance = balance - c_amount.checkAmount;


        //check if should double checkbook
        if(numOfChecks>=(checkBookSize/2))
        {
            cout<<"Ran out of empty checks. New checkbook has been ordered!"<<endl;
            checkBookSize *= 2;

        }
        return true;
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
    for(int i=0; i<numOfChecks; i++)
    {
        cout<<i;
        cout<<chkPtr[i].checkAmount;

       //cout<<chkPtr[i].checkAmount<<"   "<<chkPtr[i].checkNum<<"   "<<chkPtr[i].checkMemo<<endl;
    }
}

void checkTest(CheckBook &obj, float balance)
{
    cout<<"Made it to Check Test."<<endl;
    Check c_amount;
    c_amount.checkAmount = 50;

    while(c_amount <= obj.getBalance())
    {
        obj.writeCheck(c_amount);
    }
    cout<<"done."<<endl;

}


/*********************/

int main()
{
    //initialize a checkbook obj
    float amt;
    CheckBook cb1;
    cout<<"Enter your initial balance."<<endl;
    cin>>amt;
    cb1.setBalance(amt);

    checkTest(cb1, amt);
    cb1.displayChecks();
    return 0;
}

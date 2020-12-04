#include <iostream>
#include <cstring>
using namespace std;
class Base
{

};
class BaseAccount
{
protected:
    char name[10] = { 0 };
    char account[10] = { 0 };
    int balance;

public:
    BaseAccount(char* n, char* ac, int b)
    {
        strcpy(name, n);
        strcpy(account, ac);
        balance = b;
    }
    virtual void deposit(int b)
    {
        balance = balance + b;
    }
    virtual void withdraw(int b)
    {
        if (balance >= b)
        {
            balance = balance - b;
        }
        else
        {
            cout << "insufficient" << endl;
        }
    }
    virtual void display()
    {
        cout << name << " " << account << " "
            << "Balance:" << balance << endl;
    }
};
class BasePlus : public BaseAccount
{
protected:
    int limit = 5000;
    int limit_sum = 0;

public:
    BasePlus(char* n, char* ac, int b) : BaseAccount(n, ac, b)
    {
    }
    virtual void deposit(int b)
    {
        int temp;
        balance = balance + b;
        if (limit_sum > 0)
        {
            if(limit_sum <= balance){
                int temp = limit_sum;
                limit_sum = 0;
                balance = balance - temp;
            }
            else
            {
                limit_sum=limit_sum-balance;
                balance=0;
            }
        }
    }
    virtual void withdraw(int b)
    {
        if (balance + limit >= b)
        {
            if(balance>=b){
                balance = balance - b;
            }
            else{
                limit_sum = limit_sum + b -balance;
                balance = 0;
            }
        }
        else
        {
            cout << "insufficient" << endl;
        }
    }
    virtual void display()
    {
        cout << name << " " << account << " "
            << "Balance:" << balance << " limit_sum:" << limit_sum << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int b;
        char n[10] = { 0 };
        char ac[10] = { 0 };
        int k1, k2, k3, k4;
        cin >> n >> ac >> b;
        BaseAccount* x = NULL;
        if (ac[1] == 'A') {
            BaseAccount a(n, ac, b);
            x = &a;
        }
        if (ac[1] == 'P') {
            BasePlus a(n, ac, b);
            x = &a;
        }
        cin >> k1 >> k2 >> k3 >> k4;
        x->deposit(k1);
        x->withdraw(k2);
        x->deposit(k3);
        x->withdraw(k4);
        x->display();
    }
    return 0;
}
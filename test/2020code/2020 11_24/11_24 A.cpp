#include<iostream>
#include<cstring>
using namespace std;
class CAccount{
protected:
    long account;
    char name[10];
    float balance;
public:
    CAccount(long a, char *n, float b)
    {
        account=a;
        strcpy(name,n);
        balance=b;
    }
    void deposit(float b)
    {
        balance=balance+b;
        cout<<"saving ok!"<<endl;
    }
    virtual void withdraw(float b)
    {
        if(balance<b){
            cout<<"sorry! over balance!"<<endl;
        }
        else{
            balance=balance-b;
            cout<<"withdraw ok!"<<endl;
        }
    }
    void check()
    {
        cout<<"balance is "<<balance<<endl;
    }
};
class CCreditcard:public CAccount{
private:
    float limit;
public:
    CCreditcard(long a, char *n, float b, float l):CAccount(a,n,b)
    {
        limit = l;
    }
    void withdraw(float b)
    {
        if(balance+limit<b){
            cout<<"sorry! over limit!"<<endl;
        }
        else{
            balance=balance-b;
            cout<<"withdraw ok!"<<endl;
        }
    }
};
int main ()
{
    long a;
    char *n = new char[10];
    float b;
    float l;
    cin>>a>>n>>b;
    CAccount AC(a,n,b);
    float b1;
    cin>>b1;
    AC.check();
    AC.deposit(b1);
    AC.check();
    cin>>b1;
    AC.withdraw(b1);
    AC.check();
    cin>>a>>n>>b>>l;
    CCreditcard AC1(a,n,b,l);
    AC1.check();
    cin>>b1;
    AC1.deposit(b1);
    AC1.check();
    cin>>b1;
    AC1.withdraw(b1);
    AC1.check();
    return 0;
}
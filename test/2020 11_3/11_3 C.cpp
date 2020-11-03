#include<iostream>
#include<string>
using namespace std;
class Account
{
public:
    Account(string accno,string name, float balance){
        _accno=accno;
        _accname=name;
        _balance=balance;
        ++count;
    }
    ~Account(){

    }
    void Deposit(float amount){
        _balance=_balance+amount;
        cout<<_balance<<" ";
    }
    void Withdraw(float amount){
        _balance=_balance-amount;
        cout<<_balance<<endl;
        Totalbalance=Totalbalance+_balance;
    }
    float GetBalance(){
        return _balance;
    }
    void Show(){
        cout<<_accno<<" "<<_accname<<" ";
    }
    friend void Update(Account &a){
        a._balance=a._balance+a._balance*Account::GetInterestRate();
        cout<<a._balance<<" ";
    }
    static int GetCount(){
        return count;
    }
    static float GetInterestRate(){
        return InterestRate;
    }
    static void set(float rate,int c1){
        InterestRate=rate;
        count=c1;
    }
    static void print(){
        cout<<Totalbalance<<endl;
    }
private:
    static int count;
    static float InterestRate;
    string _accno,_accname;
    float _balance;
    static float Totalbalance;
};
int Account::count = 0;
float Account::InterestRate = 0;
float Account::Totalbalance = 0;
int main()
{
    float rate;
    int n;
    string name,accnum;
    float bal,cbal,qbal;
    cin>>rate>>n;
    Account::set(rate,n);
    for(int i=0;i<n;i++){
        cin>>accnum>>name>>bal>>cbal>>qbal;
        Account ss(accnum,name,bal);
        ss.Show();
        ss.Deposit(cbal);
        Update(ss);
        ss.Withdraw(qbal);
    }
    Account::print();
    return 0;
}
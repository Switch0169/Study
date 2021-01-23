#include<iostream>
#include<cstring>
using namespace std;
class Member {
protected:
    int number;
    int rank;
    char* name;
public:
    Member(int n, char* na, int r) {
        name = new char[20];
        number = n;
        rank = r;
        strcpy(name, na);
    }
    virtual void add(int x) {
        rank = x + rank;
    }
    virtual int Exchange(int r) {
        int money = 0;
        money = r / 100;
        rank = rank - money * 100;
        return money;
    }
    virtual void print()
    {
        cout << "普通会员" << number << "--" << name << "--" << rank << endl;
    }
};
class VIP :public Member {
protected:
    int addrate;
    int exchangrate;
public:
    VIP(int n, char* na, int r, int ar, int er) :Member(n, na, r)
    {
        addrate = ar;
        exchangrate = er;
    }
    void add(int x) {
        rank = rank + addrate * x;
    }
    int Exchange(int r) {
        int money = 0;
        money = r / exchangrate;
        rank = rank - money * exchangrate;
        return money;
    }
    void print()
    {
        cout << "贵宾会员" << number << "--" << name << "--" << rank << endl;
    }
};
int main()
{
    Member* pm;
    int number = 0;
    char name[20] = { 0 };
    int rank = 0;
    int ar = 0;
    int er = 0;
    cin >> number >> name >> rank;
    Member mm(number, name, rank);
    pm = &mm;
    int x = 0;
    cin >> x;
    pm->add(x);
    int r;
    cin >> r;
    pm->Exchange(r);
    pm->print();
    cin >> number >> name >> rank >> ar >> er;
    VIP vv(number, name, rank, ar, er);
    pm = &vv;
    cin >> x;
    pm->add(x);
    cin >> r;
    pm->Exchange(r);
    pm->print();
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
class CPeople
{
protected:
    char id[20] = {0};
    char name[20] = {0};

public:
    CPeople()
    {
    }
    CPeople(char *i, char *n)
    {
        strcpy(id, i);
        strcpy(name, n);
    }
};
class CInternetUser : public CPeople
{
protected:
    char password[20] = {0};

public:
    CInternetUser()
    {
    }
    void registerUser(char *n, char *i, char *p)
    {
        strcpy(id, i);
        strcpy(name, n);
        strcpy(password, p);
    }
    int login(char *i, char *p)
    {
        if (strcmp(id, i) == 0)
        {
            if (strcmp(password, p) == 0)
            {
                return 1;
            }
            return 0;
        }
        else
            return 0;
    }
};
class CBankCustomer : public CPeople
{
protected:
    double balance;

public:
    CBankCustomer()
    {
        balance = 0;
    }
    void openAccount(char *n, char *i)
    {
        strcpy(name, n);
        strcpy(id, i);
    }
    void deposit(double m)
    {
        balance = balance + m;
    }
    int withdraw(double m)
    {
        if (balance < m)
        {
            return 0;
        }
        else
        {
            balance = balance - m;
            return 1;
        }
    }
};
class CInternetBankCustomer : public CInternetUser, public CBankCustomer
{
private:
    double rest;
    double lastrest;
    double todaywin;
    double todayinterest;
    double lastdayinterest;

public:
    CInternetBankCustomer()
    {
        rest = 0;
        lastrest = 0;
        todaywin = 0;
        todayinterest = 0;
        lastdayinterest = 0;
    }
    int deposit(double m)
    {
        if (balance < m)
        {
            return 0;
        }
        else
        {
            balance = balance - m;
            rest = rest + m;
            return 1;
        }
    }
    int withdraw(double m)
    {
        if (rest < m)
        {
            return 0;
        }
        else
        {
            balance = balance + m;
            rest = rest - m;
            return 1;
        }
    }
    void setInterest(double i)
    {
        lastdayinterest = todayinterest;
        todayinterest = i;
    }
    void calculateProfit()
    {
        todaywin = lastrest / 10000 * lastdayinterest;
        rest = rest + todaywin;
        lastrest = rest;
    }
    int login(char *i, char *p)
    {
        if (CInternetUser::login(i, p) == 0)
        {
            return 0;
        }
        if (strcmp(CBankCustomer::id, CInternetUser::id) != 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    void print()
    {
        cout << "Name: " << CBankCustomer::name << " ID: " << CBankCustomer::id << endl;
        cout << "Bank balance: " << CBankCustomer::balance << endl;
        cout << "Internet bank balance: " << rest << endl;
        cout << endl;
    }
};

int main()
{
    int t, no_of_days, i;
    char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
    double money, interest;
    char op_code;

    //输入测试案例数t
    cin >> t;
    while (t--)
    {
        //输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;

        //输入银行开户用户名,id
        cin >> b_xm >> b_id;

        //输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;

        CInternetBankCustomer ib_user;

        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);

        if (ib_user.login(ib_id, ib_mm) == 0) //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
        {
            cout << "Password or ID incorrect" << endl;
            continue;
        }

        //输入天数
        cin >> no_of_days;
        for (i = 0; i < no_of_days; i++)
        {
            //输入操作代码, 金额, 当日万元收益
            cin >> op_code >> money >> interest;
            switch (op_code)
            {
            case 'S': //从银行向互联网金融帐户存入
            case 's':
                if (ib_user.deposit(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'T': //从互联网金融转入银行帐户
            case 't':
                if (ib_user.withdraw(money) == 0)
                {
                    cout << "Internet bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'D': //直接向银行帐户存款
            case 'd':
                ib_user.CBankCustomer::deposit(money);
                break;
            case 'W': //直接从银行帐户取款
            case 'w':
                if (ib_user.CBankCustomer::withdraw(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            default:
                cout << "Illegal input" << endl;
                continue;
            }
            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            //输出用户名,id
            //输出银行余额
            //输出互联网金融账户余额
            ib_user.print();
        }
    }

    return 0;
}
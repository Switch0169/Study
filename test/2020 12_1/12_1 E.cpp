#include <iostream>
using namespace std;
class Monster;
class Ultraman
{
protected:
    int rank;
    int exp;
    int hp;
    int damage;
    int money;

public:
    Ultraman(int r)
    {
        rank = r;
        exp = 0;
        hp = 10 * rank;
        damage = 3 * rank;
        money = 10 * rank;
    }
    void initial(int r)
    {
        rank = r;
        exp = 0;
        hp = 10 * rank;
        damage = 3 * rank;
        money = 10 * rank;
    }
    void display()
    {
        cout << "奥特曼状态(";
        cout << "rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money;
        cout << ")" << endl;
    }
    void escape()
    {
        money = 0;
    }
    void attacked(int d)
    {
        hp = hp - d / 2;
    }
    void attack(Monster& a);
    int isalive()
    {
        if (hp <= 0)
            return 0;
        else
            return 1;
    }
    int needrestore()
    {
        if (hp < 10 * rank / 2 && hp > 10)
            return 1;
        else
            return 0;
    }
    int needescape()
    {
        if (hp <= 10)
            return 1;
        else
            return 0;
    }
    void restore()
    {
        if (needrestore()) {
            int resthp = 10 * rank - hp;
            if ((money / 10) <= resthp)
            {
                hp = hp + money / 10;
                money = 0;
            }
            else
            {
                hp = rank * 10;
                money = money - resthp * 10;
            }
        }
    }
    int canupgrade()
    {
        if (exp >= rank * 10)
            return 1;
        else
            return 0;
    }
    void upgrade()
    {
        if (exp >= rank * 10)
        {
            exp = exp - rank * 10;
            rank++;
            hp = rank * 10;
            damage = rank * 3;
        }
    }
    void win(Monster& p);
    int getrank()
    {
        return rank;
    }
    int getexp()
    {
        return exp;
    }
    int getHp()
    {
        return hp;
    }
    int getdamage()
    {
        return damage;
    }
    int getmoney()
    {
        return money;
    }
};
class Monster
{
protected:
    int rank;
    int hp;
    int damage;
    int money;
    int exp;

public:

    Monster(int r)
    {
        rank = r;
        exp = 10 * r;
        hp = 20 * rank;
        damage = 2 * rank;
        money = 10 * rank;
    }
    void initial(int r)
    {
        rank = r;
        exp = 10 * r;
        hp = 20 * rank;
        damage = 2 * rank;
        money = 10 * rank;
    }
    void attacked(int d)
    {
        hp = hp - d;
    }
    int isalive()
    {
        if (hp <= 0)
            return 0;
        else
            return 1;
    }
    int getrank()
    {
        return rank;
    }
    int getexp()
    {
        return exp;
    }
    int getHp()
    {
        return hp;
    }
    int getdamage()
    {
        return damage;
    }
    int getmoney()
    {
        return money;
    }
    void fightback(Ultraman& u)
    {
        u.attacked(getdamage());
    }
    virtual void lose()
    {
        cout << "Boss!Help!" << endl;
    }
    virtual void display()
    {
        cout << "怪兽状态(";
        cout << "rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money;
        cout << ")" << endl;
    }
};
class Boss : public Monster
{
public:
    Boss() :Monster(1)
    {
        rank = 10;
        hp = 300;
        exp = 1000;
        damage = 50;
        money = 1001;
    }
    virtual void lose()
    {
        cout << "I'll be back!" << endl;
    }
    void display()
    {
        cout << "Boss怪兽状态(";
        cout << "rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money;
        cout << ")" << endl;
    }
};
void Ultraman::attack(Monster& a)
{
    a.attacked(getdamage());
}
void Ultraman::win(Monster& p)
{
    money = money + p.getmoney();
    exp = exp + p.getexp();
}

int main()
{

    //输入奥特曼的等级值，利用等级值，声明一个奥特曼对象并显示奥特曼对象初始状态。
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int ograd;
    cin >> ograd;

    Ultraman uobj(ograd);

    int t;
    cin >> t; //输入要打的怪兽个数数

    while (t-- && uobj.getHp() > 10)
    { //只要奥特曼没死也没逃跑，就继续与怪兽的战斗

        uobj.display();

        Monster* p;

        char c = 0;

        while (1)
        {

            cin >> c;

            if (c == 'B')
            {
                p = new Boss();
                break;
            }

            else if (c == 'M')
            {
                int r;
                cin >> r;
                p = new Monster(r);
                break;
            }

            else
                cout << "请重新输入怪兽类型" << endl;
        }

        p->display();

        //设置战斗标志flag为true，启动战斗循环，具体如下：

        int flag = 1;

        while (flag) //当战斗未结束就继续

        {
            uobj.attack(*p); //奥特曼攻击1次

            if (p->getHp() > 0) //怪兽没死

            {
                p->fightback(uobj); //怪兽反击1次

                if (uobj.getHp() > 10) //奥特曼生命值大于点，不逃跑

                    uobj.restore(); //奥特曼回血，在方法中判断是否需要加血

                else
                { //奥特曼逃跑，并输出"lose"并回车

                    uobj.escape();

                    cout << "lose" << endl;

                    uobj.display(); //输出奥特曼状态

                    flag = 0; //停止战斗
                }
            }

            else //怪兽死了

            {
                uobj.win(*p); //奥特曼胜利，并输出"win"并回车

                cout << "win" << endl;

                uobj.upgrade(); //奥特曼升级

                p->lose(); //输出怪兽战败信息

                flag = 0; //停止战斗
            }
        }
    }

    return 0;
}
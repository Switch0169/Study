#include<iostream>
using namespace std;
class Monster {
protected:
    int rank;
    int exp;
    int hp;
    int damage;
    int money;
public:
    Monster(int r)
    {
        rank = r;
        exp = 10 * r;
        hp = 20 * rank;
        damage = 2 * rank;
        money = 10 * rank;
    }
    int Getrank() { return rank; }
    int Getexp() { return exp; }
    int Gethp() { return hp; }
    int Getmoney() { return money; }
    int Getdamage() { return damage; }
    void display() {
        cout << "怪兽状态(rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money << ")" << endl;
    }
};
class Ultraman {
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
    void operator++()
    {
        rank = rank * 2;
        hp = 10 * rank;
        damage = 3 * rank;
        exp = exp * 2;
        money = money * 2;
    }
    void operator--()
    {
        hp = hp / 2;
        damage = damage / 2;
        exp = exp / 2;
        money = money / 2;
    }
    bool operator<(Monster& a)
    {
        if (rank > a.Getrank()) {
            hp += a.Gethp() / 2;
            damage += a.Getdamage() / 2;
            exp += a.Getexp() / 2;
            money += a.Getmoney() / 2;
            return 1;
        }
        else
            return 0;
    }
    bool operator==(Monster& a)
    {
        if (rank == a.Getrank()) {
            hp += a.Gethp();
            damage += a.Getdamage();
            exp += a.Getexp();
            money += a.Getmoney();
            return 1;
        }
        else
            return 0;
    }
    void display(ostream& out) {
        cout << "奥特曼状态(rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money << ")" << endl;
    }
    friend ostream& operator<<(ostream& oo, Ultraman& a);
};
ostream& operator<<(ostream& oo, Ultraman& a)
{
    a.display(oo);
    return oo;
}
int main() {

    int ograd;   cin >> ograd;//输入奥特曼的等级值，利用等级值，声明一个奥特曼对象。

    Ultraman uobj(ograd);

    cout << uobj;  //显示奥特曼对象初始状态



    int t;   cin >> t;//输入测试次数

    while (t--) {

        char c = 0;

        while (1) {

            cin >> c;//输入要使用的魔法袋，G代表好事成双，B代表祸不单行，X代表吸星大法，Y代表有缘相会

            if (c == 'G') {

                cout << "****好事成双****" << endl;

                ++uobj;

                cout << "****成功翻倍****" << endl;

                break;

            }

            else if (c == 'B') {

                cout << "****祸不单行****" << endl;

                --uobj;

                cout << "****不幸减半****" << endl;

                break;

            }

            else if (c == 'X') {

                int r; cin >> r;//输入怪兽的等级值，利用等级值，声明一个怪兽对象并显示对象初始状态。

                Monster mobj(r);

                mobj.display();

                cout << "****吸星大法****" << endl;

                if (uobj < mobj) cout << "****大功告成****" << endl;

                else cout << "****尚未成功****" << endl;

                break;

            }

            else if (c == 'Y') {

                int r; cin >> r;//输入怪兽的等级值，利用等级值，声明一个怪兽对象并显示对象初始状态。

                Monster mobj(r);

                mobj.display();

                cout << "****有缘相会****" << endl;

                if (uobj == mobj)cout << "****有缘有分****" << endl;

                else cout << "****无缘无分****" << endl;

                break;

            }

            else cout << "请重新输入魔法袋类型" << endl;

        }

        cout << uobj;

    }

    return 0;

}
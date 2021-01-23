#include<iostream>
using namespace std;
class Ultraman
{
protected:
    int rank;
    int exp;
    int hp;
    int damage;
    int money;
public:
    void initial(int r) {
        rank = r;
        exp = 0;
        hp = 10 * rank;
        damage = 3 * rank;
        money = 10 * rank;
    }
    void display() {
        cout << "奥特曼状态(";
        cout << "rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money;
        cout << ")" << endl;
    }
    void escape() {
        money = 0;
    }
    void attacked(int d) {
        hp = hp - d / 2;
    }
    int isalive() {
        if (hp <= 0)
            return 0;
        else
            return 1;
    }
    int needrestore() {
        if (hp < 10 * rank / 2 && hp>10)
            return 1;
        else
            return 0;
    }
    int needescape() {
        if (hp <= 10)
            return 1;
        else
            return 0;
    }
    void restore() {
        int resthp = 10 * rank - hp;
        if ((money / 10) <= resthp) {
            hp = hp + money / 10;
            money = 0;
        }
        else {
            hp = rank * 10;
            money = money - resthp * 10;
        }
    }
    int canupgrade() {
        if (exp >= rank * 10)
            return 1;
        else
            return 0;
    }
    void upgrade() {
        if (exp >= rank * 10) {
            exp = exp - rank * 10;
            rank++;
            hp = rank * 10;
            damage = rank * 3;
        }
    }
    void win(int m, int e) {
        money = money + m;
        exp = exp + e;
    }
    int getrank() {
        return rank;
    }
    int getexp() {
        return exp;
    }
    int gethp() {
        return hp;
    }
    int getdamage() {
        return damage;
    }
    int getmoney() {
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
    void initial(int r) {
        rank = r;
        exp = 10 * r;
        hp = 20 * rank;
        damage = 2 * rank;
        money = 10 * rank;
    }
    void attacked(int d) {
        hp = hp - d;
    }
    int isalive() {
        if (hp <= 0)
            return 0;
        else
            return 1;
    }
    void display() {
        cout << "rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << exp << " money=" << money << endl;
    }
    int getrank() {
        return rank;
    }
    int getexp() {
        return exp;
    }
    int gethp() {
        return hp;
    }
    int getdamage() {
        return damage;
    }
    int getmoney() {
        return money;
    }
};
class Boss :public Monster {
public:
    Boss()
    {
        rank = 10;
        hp = 300;
        exp = 1000;
        damage = 50;
        money = 1001;
    }
};
int main()
{
    int t;
    cin >> t;
    int urank;
    int mnum;
    int mrank;
    Monster* mon;
    while (t--) {
        int liveflag = 1;
        cin >> urank;
        Ultraman A;
        A.initial(urank);
        A.display();
        cin >> mnum;
        cin >> mrank;
        while (mnum-- && liveflag == 1) {
            Monster B;
            int flag = 1;
            B.initial(mrank);
            while (flag == 1) {
                B.attacked(A.getdamage());
                if (B.isalive()) {
                    A.attacked(B.getdamage());
                    if (A.needescape() == 0 && A.isalive() == 1) {
                        if (A.needrestore()) {
                            A.restore();
                        }
                    }
                    else {
                        A.escape();
                        liveflag = 0;
                        cout << "lose" << endl;
                        A.display();
                        flag = 0;
                    }
                }
                else {
                    A.win(B.getmoney(), B.getexp());
                    while (A.canupgrade()) {
                        A.upgrade();
                    }
                    cout << "win" << endl;
                    flag = 0;
                }
            }
        }
        if (liveflag == 1) {
            A.display();
            Boss C;
            int flag = 1;
            int count = 0;
            while (flag == 1) {
                C.attacked(A.getdamage());
                count++;
                if (C.isalive()) {
                    A.attacked(C.getdamage());
                    if (count % 5 == 0) {
                        A.attacked(C.getdamage());
                        A.attacked(C.getdamage());
                    }
                    if (A.isalive() == 1 && A.needescape() == 0) {
                        if (A.needrestore()) {
                            A.restore();
                        }
                    }
                    else {
                        A.escape();
                        cout << "lose" << endl;
                        A.display();
                        flag = 0;
                    }
                }
                else {
                    A.win(C.getmoney(), C.getexp());
                    cout << "win Boss" << endl;
                    while (A.canupgrade()) {
                        A.upgrade();
                    }
                    A.display();
                    flag = 0;
                }
            }
        }
    }
    return 0;
}
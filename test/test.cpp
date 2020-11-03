#include<iostream>
using namespace std;
class Ultraman
{
private:
    int rank;
    int exp;
    int hp;
    int damage;
    int money;
public:
    void initial(int r){
        rank=r;
        exp=0;
        hp=10*rank;
        damage=3*rank;
        money=10*rank;
    }
    void display(){
        cout<<"rank="<<rank<<" hp="<<hp<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<endl;
    }
    void escape(){
        money=0;
    }
    void attack(){
        ;
    }
    void attacked(char t,int d1, int d2){
        hp=hp-d1/2;
        if(t=='A'){
            hp=hp-d2/2;
        }
    }
    void restore(){
        int resthp=10*rank-hp;
        if((money/10)<=resthp){
            hp=hp+money/10;
            money=0;
        }
        else{
            hp=rank*10;
            money=money-resthp*10; 
        }
    }
    void upgrade(){
        if(exp>=rank*10){
            exp=exp-rank*10;
            rank++;
            hp=rank*10;
            damage=rank*3;
        }
    }
    void win(int m,int e,int m1,int e1,char t){
        if(t=='S'){
            money=money+m*2+m1;
            exp=exp+e*2+e1;
        }
        else{
            money=money+m+m1;
            exp=exp+e+e1;
        }
    }
    int getrank(){
        return rank;
    }
    int getexp(){
        return exp;
    } 
    int gethp(){
        return hp;
    }
    int getdamage(){
        return damage;
    }
    int getmoney(){
        return money;
    }
};
class NMonster
{
private:
    int rank;
    int hp;
    int damage;
    int money;
    int exp;
public:
    void initial(int r){
        rank=r;
        exp=10*rank;
        hp=10*rank;
        damage=2*rank;
        money=10*rank;
    }
    void attack(){
        ;
    }
    void fightback(){
        ;
    }
    void attacked(int d){
        hp=hp-d;
    }
    void display(){
        cout<<"rank="<<rank<<" hp="<<hp<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<endl;
    }
    int getrank(){
        return rank;
    }
    int getexp(){
        return exp;
    } 
    int gethp(){
        return hp;
    }
    int getdamage(){
        return damage;
    }
    int getmoney(){
        return money;
    }
};
class AMonster
{
private:
    int rank;
    int hp;
    int damage;
    int money;
    int exp;
public:
    void initial(int r){
        rank=r;
        exp=10*rank;
        hp=5*rank;
        damage=4*rank;
        money=10*rank;
    }
    void attack(){
        ;
    }
    void fightback(){
        ;
    }
    void attacked(int d){
        hp=hp-d;
    }
    void display(){
        cout<<"rank="<<rank<<" hp="<<hp<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<endl;
    }
    int getrank(){
        return rank;
    }
    int getexp(){
        return exp;
    } 
    int gethp(){
        return hp;
    }
    int getdamage(){
        return damage;
    }
    int getmoney(){
        return money;
    }
};
class DMonster
{
private:
    int rank;
    int hp;
    int damage;
    int money;
    int exp;
public:
    void initial(int r){
        rank=r;
        exp=10*rank;
        hp=20*rank;
        damage=1*rank;
        money=10*rank;
    }
    void attack(){
        ;
    }
    void fightback(){
        ;
    }
    void attacked(int d){
        hp=hp-d/2;
    }
    void display(){
        cout<<"rank="<<rank<<" hp="<<hp<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<endl;
    }
    int getrank(){
        return rank;
    }
    int getexp(){
        return exp;
    } 
    int gethp(){
        return hp;
    }
    int getdamage(){
        return damage;
    }
    int getmoney(){
        return money;
    }
};
class SMonster
{
private:
    int rank;
    int hp;
    int damage;
    int money;
    int exp;
public:
    void initial(int r){
        rank=r;
        exp=20*rank;
        hp=10*rank;
        damage=1*rank;
        money=20*rank;
    }
    void attack(){
        ;
    }
    void fightback(){
        ;
    }
    void attacked(int d){
        hp=hp-d;
    }
    void display(){
        cout<<"rank="<<rank<<" hp="<<hp<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<endl;
    }
    int getrank(){
        return rank;
    }
    int getexp(){
        return exp;
    } 
    int gethp(){
        return hp;
    }
    int getdamage(){
        return damage;
    }
    int getmoney(){
        return money;
    }
};
class Angel
{
private:
    int rank;
    int exp;
    int damage;
    int money;
public:
    void initial(int r){
        rank=r;
        exp=5*rank;
        damage=0.5*rank;
        money=5*rank;
    }
    void attack(){
        ;
    }
    int getrank(){
        return rank;
    }
    int getexp(){
        return exp;
    } 
    int getdamage(){
        return damage;
    }
    int getmoney(){
        return money;
    }
};
int main()
{
    int flag=0;
    int flag1,flag2,flag3,flag4;
    int eflag=0;
    int winflag=0;
    int t;
    cin>>t;
    int rank;
    int Nrank,Srank,Drank,Arank;
    while(t--){
            flag=1;
            flag1=1;
            flag2=1;
            flag3=1;
            flag4=1;
            eflag=0;
            winflag=0;
            cin>>rank;
            cin>>Nrank>>Srank>>Drank>>Arank;
            Ultraman Outman;
            Outman.initial(rank);
            Outman.display();
            Angel OutAngel;
            OutAngel.initial(rank);
            NMonster monsterN;
            monsterN.initial(Nrank);
            monsterN.display();
            SMonster monsterS;
            monsterS.initial(Srank);
            monsterS.display();
            DMonster monsterD;
            monsterD.initial(Drank);
            monsterD.display();
            Angel AngelD;
            AngelD.initial(Srank);
            AMonster monsterA;
            Angel AngelA;
            AngelA.initial(Arank);
            monsterA.initial(Arank);
            monsterA.display();
        while(flag){
            if(flag1==1)
                    monsterN.attacked(Outman.getdamage());
            if(flag2==1)
                    monsterS.attacked(Outman.getdamage());
            if(flag3==1)
                    monsterD.attacked(Outman.getdamage());
            if(flag4==1)
                    monsterA.attacked(Outman.getdamage());
            if(flag1==1){
                if(monsterN.gethp()>0){
                    Outman.attacked('N',monsterN.getdamage(),0);
                    if(Outman.gethp()>10){
                        if(Outman.gethp()<5*Outman.getrank()){
                            Outman.restore();
                        }
                    }
                    else{
                        Outman.escape();
                        eflag=1;
                        cout<<"lose"<<endl;
                        Outman.display();
                        flag=0;
                    }
                }
                else if(monsterN.gethp()<=0){
                    Outman.win(monsterN.getmoney(),monsterN.getexp(),0,0,'N');
                    while(1){
                        if(Outman.getexp()<Outman.getrank()*10)
                            break;
                        Outman.upgrade();
                        OutAngel.initial(Outman.getrank());
                    }
                    flag1=0;
                    cout<<"win"<<endl;
                    Outman.display();
                    winflag++;
                }
            }
            if (flag==0)
            {
                break;
            }
            if(flag2==1){
                if(monsterS.gethp()>0){
                    Outman.attacked('S',monsterS.getdamage(),0);
                    if(Outman.gethp()>10){
                        if(Outman.gethp()<5*Outman.getrank()){
                            Outman.restore();
                        }
                    }
                    else{
                        Outman.escape();
                        eflag=1;
                        cout<<"lose"<<endl;
                        Outman.display();
                        flag=0;
                    }
                }
                else if(monsterS.gethp()<=0){
                    Outman.win(monsterS.getmoney(),monsterS.getexp(),0,0,'S');
                    while(1){
                        if(Outman.getexp()<Outman.getrank()*10)
                            break;
                        Outman.upgrade();
                        OutAngel.initial(Outman.getrank());
                    }
                    flag2=0;
                    cout<<"win"<<endl;
                    Outman.display();
                    winflag++;
                }
            }
            if (flag==0)
            {
                break;
            }
            if(flag3==1){
                if(monsterD.gethp()>0){
                    Outman.attacked('D',monsterD.getdamage(),0);
                    if(Outman.gethp()>10){
                        if(Outman.gethp()<5*Outman.getrank()){
                            Outman.restore();
                        }
                    }
                    else{
                        Outman.escape();
                        eflag=1;
                        cout<<"lose"<<endl;
                        Outman.display();
                        flag=0;
                    }
                }
                else if(monsterD.gethp()<=0){
                    Outman.win(monsterD.getmoney(),monsterD.getexp(),AngelD.getmoney(),AngelD.getexp(),'D');
                    while(1){
                        if(Outman.getexp()<Outman.getrank()*10)
                            break;
                        Outman.upgrade();
                        OutAngel.initial(Outman.getrank());
                    }
                    flag3=0;
                    cout<<"win"<<endl;
                    Outman.display();
                    winflag++;
                }
            }
            if (flag==0)
            {
                break;
            }
            if(flag4==1){
                if(monsterA.gethp()>0){
                    Outman.attacked('A',monsterA.getdamage(),AngelA.getdamage());
                    if(Outman.gethp()>10){
                        if(Outman.gethp()<5*Outman.getrank()){
                            Outman.restore();
                        }
                    }
                    else{
                        Outman.escape();
                        eflag=1;
                        cout<<"lose"<<endl;
                        Outman.display();
                        flag=0;
                    }
                }
                else if(monsterA.gethp()<=0){
                    Outman.win(monsterA.getmoney(),monsterA.getexp(),AngelA.getmoney(),AngelA.getexp(),'N');
                    while(1){
                        if(Outman.getexp()<Outman.getrank()*10)
                            break;
                        Outman.upgrade();
                        OutAngel.initial(Outman.getrank());
                    }
                    flag4=0;
                    cout<<"win"<<endl;
                    Outman.display();
                    winflag++;
                }
            }
            if(winflag==4){
                flag=0;
                cout<<"win all"<<endl;
            }
            if(flag==0){
                break;
            }
        }
    }
    return 0;
}
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
    void attacked(int d,int d1){
        hp=hp-d;
        hp=hp-d1;
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
    void attacked(int d,int d1){
        hp=hp-d;
        hp=hp-(d1+1);
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
    void attacked(int d,int d1){
        hp=hp-d/2;
        hp=hp-(d1+2);
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
    void attacked(int d,int d1){
        hp=hp-d;
        hp=hp-d1;
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
    int eflag=0;
    int t;
    cin>>t;
    int rank;
    int Nrank,Srank,Arank,Drank;
    while(t--){
        while(flag){
            flag=1;
            eflag=0;
            cin>>rank;
            Ultraman Outman;
            Outman.initial(rank);
            Outman.display();
            cin>>Nrank>>Srank>>Arank>>Drank;
            Angel OutAngel;
            OutAngel.initial(rank);
            NMonster monsterN;
            monsterN.initial(Nrank);
            SMonster monsterS;
            monsterS.initial(Srank);
            AMonster monsterA;
            monsterA.initial(Arank);
            DMonster monsterD;
            monsterD.initial(Drank);
            monsterN.attacked(Outman.getdamage(),OutAngel.getdamage());
            monsterS.attacked(Outman.getdamage(),OutAngel.getdamage());
            monsterA.attacked(Outman.getdamage(),OutAngel.getdamage());
            monsterD.attacked(Outman.getdamage(),OutAngel.getdamage());
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
                Outman.win(monsterN.getmoney(),monsterN.getexp(),0,0);
                Outman.upgrade();
                cout<<"win"<<endl;
                Outman.display();
                flag=1;
            }
            if (flag==0)
            {
                break;
            }
            
        }
    }
    return 0;
}
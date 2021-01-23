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
    void attacked(int d){
        hp=hp-d/2;
    }
    void isalive(){

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
    void win(int m,int e){
        money=money+m;
        exp=exp+e;
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
class Monster
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
        exp=10*r;
        hp=20*rank;
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
int main()
{
    int t;
    cin>>t;
    int rank1,rank2;
    int flag;
    while(t--){
        cin>>rank1>>rank2;
        Ultraman Outman;
        Monster boss;
        Outman.initial(rank1);
        boss.initial(rank2);
        Outman.display();
        boss.display();
        flag=1;
        while(flag){
            boss.attacked(Outman.getdamage());
            if(boss.gethp()>0){
                Outman.attacked(boss.getdamage());
                if(Outman.gethp()>10){
                    if(Outman.gethp()<5*Outman.getrank()){
                        Outman.restore();
                    }
                }
                else{
                    Outman.escape();
                    cout<<"lose"<<endl;
                    Outman.display();
                    flag=0;
                }
            }
            else{
                Outman.win(boss.getmoney(),boss.getexp());
                Outman.upgrade();
                cout<<"win"<<endl;
                Outman.display();
                flag=0;
            }
        }
    }
    return 0;
}
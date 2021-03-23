#include<iostream>
#include<cstdio>
using namespace std;
int mm1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int mm2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
class Date{
    int year,month,day;
public:
    Date();
    Date(int y, int m, int d){
        setDate(y,m,d);
    }
    int getYear()   {return year;}
    int getMonth()  {return month;}
    int getDay()    {return day;}
    void setDate(int y, int m, int d){
        year = y;
        month = m;
        day = d;
    }

    void print(){
        printf("Today is %d/%02d/%02d\n",year,month,day);
        addOneDay();
        printf("Tomorrow is %d/%02d/%02d\n",year,month,day);
    }
    bool isRun(){
        if((year%4==0&&year%100!=0)||year%400==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    void addOneDay()
    {
        day++;
        if(isRun()){
            if(day>mm2[month]){
                day = 1;
                month++;
            }
            if(month>12){
                year++;
                month = 1;
            }
        }
        else{
            if(day>mm1[month]){
                day = 1;
                month++;
            }
            if(month>12){
                year++;
                month = 1;
            }
        }
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int y,m,d;
        cin>>y>>m>>d;
        Date myDate(y,m,d);
        myDate.print();
    }
    return 0;
}
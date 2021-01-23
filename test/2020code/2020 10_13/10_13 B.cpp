#include<iostream>
#include<stdio.h>
using namespace std;
class Date{
    int year,month,day;
public:
    Date();
    Date(int y,int m,int d);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int y,int m, int d);
    void print();
    void addOneDay();
};
Date::Date()
{
    year=1900;
    month=1;
    day=1;
}
Date::Date(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
}
int Date::getYear()
{
    return year;
}
int Date::getMonth()
{
    return month;
}
int Date::getDay()
{
    return day;
}
void Date::setDate(int y, int m, int d)
{
    year=y;
    month=m;
    day=d;
}
void Date::print()
{
    cout<<year<<"/"<<month<<"/"<<day<<endl;
}
void Date::addOneDay()
{
    day=day+1;
    if((month==1||month==3||month==5||month==7||month==8||month==10)&&day>31){
        day=1;
        month=month+1;
    }
    else if((month==4||month==6||month==9||month==11)&&day>30){
        day=1;
        month=month+1;
    }
    else if(month==2&&((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))){
        if(day>29){
            month=3;
            day=1;
        }
    }
    else if(month==2&&(year%4!=0||(year%4==0&&year%100==0))||year%100!=0||(year%100==0&&year%400!=0))
    {
        if(day>28){
            month=3;
            day=1;
        }
    }
    else if(month==12&&day>31){
        year=year+1;
        month=1;
        day=1;
    }
}
int main()
{
    int t,y,m,d;
    cin>>t;
    Date a;
    for(int i=0;i<t;i++){
        if(i%2==0){
            cin>>y>>m>>d;
            Date a(y,m,d);
            printf("Today is %04d/%02d/%02d\n",a.getYear(),a.getMonth(),a.getDay());
            a.addOneDay();
            printf("Tomorrow is %04d/%02d/%02d\n",a.getYear(),a.getMonth(),a.getDay());
        }
        if(i%2!=0){
            cin>>y>>m>>d;
            a.setDate(y,m,d);
            printf("Today is %04d/%02d/%02d\n",a.getYear(),a.getMonth(),a.getDay());
            a.addOneDay();
            printf("Tomorrow is %04d/%02d/%02d\n",a.getYear(),a.getMonth(),a.getDay());
        }
    }
    return 0;
}

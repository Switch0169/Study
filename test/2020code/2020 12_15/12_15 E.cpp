#include<iostream>
#include<cstring>
using namespace std;
class Student{
public:
    int year;
    int month;
    int day;
    char name[20]={0};
    Student()
    {

    }
    void aSet(char *na, int y, int m, int d){
        strcpy(name,na);
        year = y;
        month = m;
        day = d;
    }
    void Set(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    friend int operator -(Student &a, Student &b);
    bool IsLeapyear(){
        if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
            return 1;
        return 0;
    }
};
bool IsLeapyear(int year){
    if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
        return 1;
    return 0;
}
int operator -(Student& a, Student& b) {
    int ans = 0;
    int y, m, d;
    int monthless[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int monthmore[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    if ((a.year * 10000 + a.month * 100 + a.day) > (b.year * 10000+ b.month *100+ b.day)) {
        y = b.year;
        m = b.month;
        d = b.day;
        int count = 0;
        while (y != a.year || m != a.month || d != a.day) {
            if (IsLeapyear(y)) {
                d++;
                count++;
                if (d > monthmore[m]) {
                    d = d - monthmore[m];
                    m++;
                }
                if (m > 12) {
                    m = m - 12;
                    y++;
                }
            }
            else {
                d++;
                count++;
                if (d > monthless[m]) {
                    d = d - monthless[m];
                    m++;
                }
                if (m > 12) {
                    m = m - 12;
                    y++;
                }
            }
        }
        return count;
    }
    else {
        y = a.year;
        m = a.month;
        d = a.day;
        int count = 0;
        while (y != b.year || m != b.month || d != b.day) {
            if (IsLeapyear(y)) {
                d++;
                count++;
                if (d > monthmore[m]) {
                    d = d - monthmore[m];
                    m++;
                }
                if (m > 12) {
                    m = m - 12;
                    y++;
                }
            }
            else {
                d++;
                count++;
                if (d > monthless[m]) {
                    d = d - monthless[m];
                    m++;
                }
                if (m > 12) {
                    m = m - 12;
                    y++;
                }
            }
        }
        return count;
    }
}
int main()
{
    int t;
    cin>>t;
    int y,m,d;
    char na[20]={0};
    Student a[50];
    for(int i=0; i<t; i++){
        cin>>na>>y>>m>>d;
        a[i].aSet(na,y,m,d);
    }
    int highest = 0;
    int temp = 0;
    int count1 = 0;
    int count2 = 0;
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            temp = a[i] - a[j];
            if(highest<temp){
                highest = temp;
                count1 = i;
                count2 = j;
            }
        }
    }
    cout<<a[count1].name<<"和"<<a[count2].name<<"年龄相差最大，为"<<highest<<"天。";
    return 0;
}
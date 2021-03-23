#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

int open_number;
int close_number;

class Date{
public:
    int year;
    int month;
    int day;
};



class GuP{
public:
    string type;
    Date time;
    int price_s1;
    int price_s2;
    GuP(){

    }
    void set(int y, int m, int d, string t, int s1, int s2){
        time.year = y;
        time.month = m;
        time.day = d;
        price_s1 = s1;
        price_s2 = s2;
        type = t;
    }
};
bool cmp(const GuP &x,const GuP &y){
    int xx = x.time.year*10000 + x.time.month*100 + x.time.day;
    int yy = y.time.year*10000 + y.time.month*100 + y.time.day;
    return xx<yy;
}
int main()
{
    int y,m,d;
    string str;
    int s1,s2;
    int N,M;
    cin>>N>>M;
    GuP openx[1000];
    GuP closex[1000];
    int t1 = 0, t2 = 0;
    while(N--){
        scanf("%d/%d/%d",&y,&m,&d);
        cin>>str;
        cin>>s1>>s2;
        if(str=="open"){
            openx[t1].set(y,m,d,str,s1,s2);
            t1++;
        }
        else{
            closex[t2].set(y,m,d,str,s1,s2);
            t2++;
        }
    }
    sort(openx,openx+t1,cmp);
    sort(closex,closex+t2,cmp);
    for(int i=M-1; i<t1; i++){
        int arrys1 = 0,arrys2 = 0;
        for(int j=i-M+1; j<=i; j++){
            arrys1 += openx[j].price_s1;
            arrys2 += openx[j].price_s2;
        }
        printf("%d/%d/%d open %d %d\n",openx[i].time.year,openx[i].time.month,openx[i].time.day,arrys1/M,arrys2/M);
    }
    for(int i=M-1; i<t2; i++){
        int arrys1 = 0,arrys2 = 0;
        for(int j=i-M+1; j<=i; j++){
            arrys1 += closex[j].price_s1;
            arrys2 += closex[j].price_s2;
        }
        printf("%d/%d/%d close %d %d\n",closex[i].time.year,closex[i].time.month,closex[i].time.day,arrys1/M,arrys2/M);
    }
    return 0;
}
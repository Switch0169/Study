#include<iostream>
using namespace std;
class counter{
protected:
    int value;    
public:
    counter(int c)
    {
        value = c;
    }
    int increment()
    {
        value++;
    }
    int getvalue()
    {
        return value;
    }
};
class whilecounter:public counter{
private:
    int min_value;
    int max_value;
public:
    whilecounter(int a, int b, int c):counter(c)
    {
        min_value=a;
        max_value=b;
    }
    int increment()
    {
        int flag = 0;
        if(value>=min_value&&value<max_value)
        {
            value++;
            return 0;
        }
        else {
            value = min_value;
            return 1;
        }
    }
};
class NewClock{
private:
    int hour;
    int minute;
    int second;
public:
    NewClock(int h , int m, int s)
    {
        hour=h;
        minute=m;
        second=s;
    }
    void time(int s)
    {
        whilecounter sec(0,59,second);
        whilecounter min(0,59,minute);
        whilecounter hou(0,23,hour);
        while(s--){
            if(sec.increment()){
                if(min.increment()){
                    if(hou.increment()){

                    }
                }
            }
        }
        cout<<hou.getvalue()<<":"<<min.getvalue()<<":"<<sec.getvalue()<<endl;
    }
};
int main ()
{
    int n;
    cin>>n;
    int h,m,s;
    int ss;
    while(n--){
        cin>>h>>m>>s;
        NewClock a(h,m,s);
        cin>>ss;
        a.time(ss);
    }
    return 0;
}
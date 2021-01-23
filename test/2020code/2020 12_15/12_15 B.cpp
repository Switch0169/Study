#include<iostream>
using namespace std;
class myclock{
protected:
    int hour;
    int min;
    int sec;
public:
    myclock(int h, int m, int s){
        hour=h;
        min=m;
        sec=s;
    }
    void add(int s){
        sec = sec + s;
        while(sec>=60){
            sec = sec -60;
            min++;
        }
        while(min>=60){
            min = min -60;
            hour++;
        }
        while(hour>=12){
            hour = hour -12;
        }
    }
    void sub(int s){
        sec = sec - s;
        while(sec<0){
            sec = sec + 60;
            min--;
        }
        while(min<0){
            min = min + 60;
            hour--;
        }
        while(hour<0){
            hour = hour + 12;
        }
    }
    friend myclock operator++(myclock &a, int);
    friend myclock operator--(myclock &a);
    void display()
    {
        cout<<hour<<":"<<min<<":"<<sec<<endl;
    }
};
myclock operator++(myclock &a){
    int m = 1;
    a.add(m);
    return a;
}
myclock operator--(myclock &a, int){
    a.sub(1);
    return a;
}
int main()
{
    int h,m,s;
    cin>>h>>m>>s;
    myclock now(h,m,s);
    int t;
    cin>>t;
    int x;
    while(t--){
        cin>>x;
        if(x>0){
            int temp = x;
            while(temp--){
                ++now;
            }
        }
        if(x<0){
            int temp = x;
            while (temp++)
            {
                now--;
            }
        }
        now.display();
    }
    return 0;
}
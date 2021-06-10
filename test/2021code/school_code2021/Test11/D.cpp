#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
bool isAns(double x){
    if(x < 0){
        x = -x;
    }
    if(x < 0.00001){
        return 1;
    }
    else{
        return 0;
    }
}
double Search(double y){
    double left = 0;
    double right = y;
    double x = 0;
    while(1){
        x = (left + right) / 2;
        if(isAns(pow(x, 2) - y)){
            return x;
        }
        else if(pow(x, 2) > y){
            right = x;
        }
        else if(pow(x, 2) < y){
            left = x;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    while(n--){
        double num;
        cin >> num;
        double ans = Search(num);
        printf("%.3lf\n", ans);
    }
    return 0;
}
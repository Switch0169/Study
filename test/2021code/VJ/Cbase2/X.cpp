#include<iostream>
#include<cstdio>
using namespace std;
double x1, y_1, x2, y2, x3, y3, x4, y4;
void myswap(double &a, double &b){
    if(a > b){
        double t = a;
        a = b;
        b = t;
    }
}
double getyV(){
    double A = y2 - y_1;
    double B = y4 - y3;
    double miny = min(y_1, y3);
    double maxy = max(y2, y4);
    double ans = A + B - (maxy - miny);
    if(ans < 0)
        return 0;
    else
        return ans;
}
double getxV(){
        double A = x2 - x1;
        double B = x4 - x3;
        double minx = min(x1, x3);
        double maxx = max(x2, x4);
        double ans = A + B - (maxx - minx);
        if(ans < 0)
            return 0;
        else
            return ans;
}
int main()
{
    while(cin >> x1 >> y_1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4){
        myswap(x1, x2);
        myswap(y_1, y2);
        myswap(x3, x4);
        myswap(y3, y4);
        double c = getxV();
        double k = getyV();
        printf("%.2lf\n", c * k);
    }
    return 0;
}
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Point
{
    double x,y;
public:
    Point();
    Point(double x_value,double y_value);
    double getX();
    double getY();
    void setX(double x_value);
    void setY(double y_value);
    double distanceToAnotherPoint(Point p);
};
Point::Point()
{
    x=0;
    y=0;
}
Point::Point(double x_value,double y_value)
{
    x=x_value;
    y=y_value;
}
double Point::getX()
{
    return x;
}
double Point::getY()
{
    return y;
}
void Point::setX(double x_value)
{
    x=x_value;
}
void Point::setY(double y_value)
{
    y=y_value;
}
double Point::distanceToAnotherPoint(Point p)
{
    double distance;
    double x1,y1;
    x1=p.getX();
    y1=p.getY();
    distance=(x-x1)*(x-x1)+(y-y1)*(y-y1);
    distance=sqrt(distance);
    return distance;
}
int main()
{
    int t;
    double x1,y1,x2,y2;
    Point p1;
    Point p2;
    double distance;
    cin>>t;
    while (t--)
    {
        cin>>x1>>y1>>x2>>y2;
        p1.setX(x1);
        p1.setY(y1);
        p2.setX(x2);
        p2.setY(y2);
        distance=p1.distanceToAnotherPoint(p2);
        cout<<"Distance of Point"<<"("<<fixed<<setprecision(2)<<p1.getX()<<","<<fixed<<setprecision(2)<<p1.getY()<<")"<<" to Point"<<"("<<fixed<<setprecision(2)<<p2.getX()<<","<<fixed<<setprecision(2)<<p2.getY()<<")"<<" is "<<fixed<<setprecision(2)<<distance<<endl;
    }
    return 0;
}
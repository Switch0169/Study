#include <iostream>
#include <iomanip>
using namespace std;
class Point
{
public:
    void Set();
    int GetX();
    int GetY();

private:
    int x;
    int y;
};
class Circle
{
public:
    void SetCenter();
    void SetRadius();
    float getArea();
    float getLength();
    void Contain(Point p1);

private:
    int x;
    int y;
    int r;
};
void Point::Set()
{
    cin >> x >> y;
}
int Point::GetX()
{
    return x;
}
int Point::GetY()
{
    return y;
}
void Circle::SetCenter()
{
    cin >> x >> y;
}
void Circle::SetRadius()
{
    cin >> r;
}
float Circle::getArea()
{
    float a = 3.14 * r * r;
    return a;
}
float Circle::getLength()
{
    return (2 * 3.14 * r);
}
void Circle::Contain(Point p1)
{
    int d;
    d = (x - p1.GetX()) * (x - p1.GetX()) + ((y - p1.GetY()) * (y - p1.GetY()));
    if (d > r * r)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;
    }
}
int main()
{
    Circle a;
    Point b;
    a.SetCenter();
    a.SetRadius();
    b.Set();
    cout << fixed << setprecision(2) << a.getArea() << " " << fixed << setprecision(2) << a.getLength() << endl;
    a.Contain(b);
    return 0;
}
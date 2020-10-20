#include<iostream>
using namespace std;
class Point
{
protected:
	int x,y;
public:
	Point(){
		x=0;
		y=0;
	}
	Point(int x1,int y1){
		x=x1;
		y=y1;
	}
	~Point(){
		x=0;
		y=0;
		cout<<"point clear"<<endl;
	}
	void setXY(int x2,int y2){
		x=x2;
		y=y2;
	}
	int GetX(){
		return x;
	}
	int GetY(){
		return y;
	}
};
class Circle
{
protected:
	int x,y,r;
public:
	Circle(int x1,int y1,int r1){
		x=x1;
		y=y1;
		r=r1;
	}
	~Circle(){
		x=0;
		y=0;
		r=0;
		cout<<"circle clear"<<endl;
	}
	void Contain(Point &p1){
		int d;
	    d = (x - p1.GetX()) * (x - p1.GetX()) + ((y - p1.GetY()) * (y - p1.GetY()));
	    if (d > r * r)
	    {
	        cout << "out" << endl;
	    }
	    else
	    {
	        cout << "in" << endl;
	    }
	}
};
int main()
{
	int x,y,n;
	int x1,y1;
	int x2,y2,r2;
	cin>>x>>y;
	Point a(x,y);
	cin>>n;
	Point *b=new Point[n];
	for(int i=0;i<n;i++){
		cin>>x1>>y1;
		b[i].setXY(x1,y1);
	}
	cin>>x2>>y2>>r2;
	Circle c(x2,y2,r2);
	c.Contain(a);
	for(int i=0;i<n;i++){
		c.Contain(b[i]);
	}
	return 0;
}

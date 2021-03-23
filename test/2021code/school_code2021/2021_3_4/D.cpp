#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

class Point
{
    double x,y;
public:
    Point(){
        x = 0;
        y = 0;
        cout<<"Constructor."<<endl;
    }
    Point(double x_value, double y_value){
        x = x_value;
        y = y_value;
    }
    Point(Point &p){
        x = p.x;
        y = p.y;
    }
    double getX(){return x;}
    double getY(){return y;}
    void setXY(double x1, double y1){x = x1; y = y1;}
    void setX(double x_value){

    }
    void setY(double y_value){

    }
    double getDisTo(const Point &p){
        double dd = sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
        return dd;
    }
    ~Point(){
        cout<<"Distructor."<<endl;
    }

};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Point *myPoint = new Point [n];
        for(int i=0; i<n; i++){
            int xx,yy;
            cin>>xx>>yy;
            myPoint[i].setXY(xx,yy);
        }
        double maxd = 0;
        int maxnumber1 = 0;
        int maxnumber2 = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                double temp = myPoint[i].getDisTo(myPoint[j]);
                if(temp>maxd){
                    maxd = temp;
                    maxnumber1 = i;
                    maxnumber2 = j;
                }
            }
        }
        cout<<fixed<<setprecision(2)<<"The longeset distance is "<<maxd<<",between p["<<maxnumber1<<"] and p["<<maxnumber2<<"]."<<endl;
        delete []myPoint;
    }

    return 0;
}
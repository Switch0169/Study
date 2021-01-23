#include<iostream>
using namespace std;
class equipment {
protected:
    int number;
    int power;
public:
    equipment(int n, int p) {
        number = n;
        power = p;
    }
    virtual void print() {
        cout << "编号" << number << "--" << "功率" << power << "W" << endl;
    }
};
class fan :public equipment {
protected:
    int direction;
    int strength;
public:
    fan(int n, int p, int d, int s) :equipment(n, p)
    {
        direction = d;
        strength = s;
    }
    void Controldirection(int x) {
        direction = x;
    }
    void Controlstrength(int x) {
        strength = x;
    }
    virtual void print() {
        equipment::print();
        if (direction == 0) {
            cout << "定向吹风--风力" << strength << "级" << endl;
        }
        else {
            cout << "旋转吹风--风力" << strength << "级" << endl;
        }
    }
};
class AddWater :public equipment {
protected:
    double ActualV;
    double MaxV;
public:
    AddWater(int n, int p, double A, double M) :equipment(n, p)
    {
        ActualV = A;
        MaxV = M;
    }
    int Warn() {
        if (ActualV >= (MaxV * 0.5)) {
            return 1;
        }
        else if (ActualV >= (MaxV * 0.1)) {
            return 2;
        }
        else {
            return 3;
        }
    }
    virtual void print() {
        cout << "实际水容量" << ActualV << "升--";
        if (Warn() == 1) {
            cout << "水量正常" << endl;
        }
        if (Warn() == 2) {
            cout << "水量偏低" << endl;
        }
        if (Warn() == 3) {
            cout << "水量不足" << endl;
        }
    }
};
class AddWaterfan :public fan, public AddWater {
protected:
    int rank;
public:
    AddWaterfan(int n, int p, int d, int s, double A, double M, int r) :fan(n, p, d, s), AddWater(n, p, A, M)
    {
        rank = r;
    }
    void Controlrank(int r) {
        rank = r;
        if (rank == 0) {

        }
        else if (rank == 1) {
            fan::Controldirection(0);
            fan::Controlstrength(1);
        }
        else if (rank == 2) {
            fan::Controldirection(1);
            fan::Controlstrength(2);
        }
        else if (rank == 3) {
            fan::Controldirection(1);
            fan::Controlstrength(3);
        }
        print();
        fan::print();
        AddWater::print();
    }
    void print() {
        cout << "加湿风扇--档位" << rank << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, p, d, s, r;
        double A, M;
        cin >> n >> p >> d >> s >> A >> M >> r;
        AddWaterfan a(n, p, d, s, A, M, r);
        cin >> r;
        a.Controlrank(r);
    }
    return 0;
}
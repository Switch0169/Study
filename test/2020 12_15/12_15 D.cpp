#include<iostream>
using namespace std;
class Vector {
protected:
    int vec[11] = { 0 };
public:
    Vector(int m) {
        for (int i = 0; i < 10; i++) {
            cin >> vec[i];
        }
    }
    Vector() {

    }
    Vector(Vector& c) {
        for (int i = 0; i < 10; i++) {
            vec[i] = c.vec[i];
        }
    }
    void display(ostream& out)
    {
        for (int i = 0; i < 10; i++) {
            cout << vec[i];
            if (i != 9) {
                cout << " ";
            }
        }
        cout << endl;
    }
    friend Vector operator +(Vector& a, Vector& b);
    friend Vector operator -(Vector& a, Vector& b);
    friend ostream& operator <<(ostream& oo, Vector& a);
};
Vector operator +(Vector& a, Vector& b) {
    Vector c;
    for (int i = 0; i < 10; i++) {
        c.vec[i] = a.vec[i] + b.vec[i];
    }
    return c;
}
Vector operator -(Vector& a, Vector& b) {
    Vector c;
    for (int i = 0; i < 10; i++) {
        c.vec[i] = a.vec[i] - b.vec[i];
    }
    return c;
}
ostream& operator<<(ostream& oo, Vector& a) {
    a.display(oo);
    return oo;
}
int main()
{
    int m = 1;
    Vector a(m);
    Vector b(m);
    Vector c;
    c = a + b;
    cout << c;
    c = a - b;
    cout << c;
    return 0;
}
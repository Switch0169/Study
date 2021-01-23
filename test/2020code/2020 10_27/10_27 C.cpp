#include<iostream>
#include<cstring>
using namespace std;
class CDate
{
private:
    int year, month, day;
public:
    CDate() {
        year = 0;
        month = 0;
        day = 0;
    }
    CDate(int y, int m, int d) { year = y; month = m; day = d; }
    CDate(CDate& r)
    {
        year = r.getYear();
        month = r.getMonth();
        day = r.getDay();
    }
    void set(int y,int m,int d) {
        year = y;
        month = m;
        day = d;
    }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
};
class phone
{
private:
    char phonetype;
    char phonenumber[14];
    int phonestate;
    CDate stop;
public:
    phone(char pt, char* pn, int ps, int y, int m, int d) :stop(y, m, d)
    {
        phonetype = pt;
        strcpy(phonenumber, pn);
        phonestate = ps;
        cout << "Construct a new phone " << phonenumber << endl;
    }
    phone(phone& r) {
        phonetype = 'D';
        strcpy(phonenumber, r.phonenumber);
        phonenumber[11] = 'X';
        phonenumber [12] = '\0';
        phonestate = r.phonestate;
        cout << "Construct a copy of phone " << r.phonenumber<< endl;
        stop.set(r.stop.getYear(), r.stop.getMonth(), r.stop.getDay());
        cout << "类型=备份||"; 
        cout << "号码=" << phonenumber;
        if (phonestate == 1) {
            cout << "||State=在用" << endl;
        }
        if (phonestate == 2) {
            cout << "||State=未用" << endl;
        }
        if (phonestate == 3) {
            cout << "Stop the phone " << phonenumber << endl;
            cout << "||State=停用||";
            cout << "停机日期=" << stop.getYear() << "." << stop.getMonth() << "." << stop.getDay() << endl;
            cout << "----" << endl;
        }
    }
    void print() {
        if (phonestate == 3) {
            cout << "Stop the phone " << phonenumber << endl;
        }
        if (phonetype == 'A') {
            cout << "类型=机构||";
        }
        if (phonetype == 'B') {
            cout << "类型=企业||";
        }
        if (phonetype == 'C') {
            cout << "类型=个人||";
        }
        cout << "号码=" << phonenumber;
        if (phonestate == 1) {
            cout << "||State=在用" << endl;
        }
        if (phonestate == 2) {
            cout << "||State=未用" << endl;
        }
        if (phonestate == 3) {
            cout << "||State=停用||";
            cout << "停机日期=" << stop.getYear() << "." << stop.getMonth() << "." << stop.getDay() << endl;
            cout << "----" << endl;
        }
    }
    void LetStop() 
    {
        phonestate = 3;
    }
};
int main()
{
    int t;
    cin >> t;
    char pt;
    char* pn;
    pn = new char[14];
    int ps;
    int y, m, d;
    while (t--) {
        cin >> pt >> pn;
        cin >> ps >> y >> m >> d;
        phone a(pt, pn, ps, y, m, d);
        a.print();
        phone b(a);
        a.LetStop();
        a.print();
    }
    return 0;
}

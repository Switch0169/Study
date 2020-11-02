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
    bool isLeapYear() { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getDayofYear()         //计算日期从当年1月1日算起的天数
    {
        int i, sum = day;
        int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        int b[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

        if (isLeapYear())
            for (i = 0; i < month; i++)   sum += b[i];
        else
            for (i = 0; i < month; i++)   sum += a[i];

        return sum;
    }
};
bool isLeapYear(int i)
{
    return (i % 4 == 0 && i % 100 != 0) || i % 400 == 0;
}
class software
{
private:
    char* softname;
    char softtype;
    CDate ddl;
    char media;
public:
    software(char* s1, char st1, char media1, int y, int m, int d) :ddl(y, m, d)
    {
        softname = new char[100];
        media = media1;
        strcpy(softname, s1);
        softtype = st1;
    }
    software(software& p) {
        softname = new char[100];
        ddl.set(p.ddl.getYear(), p.ddl.getMonth(), p.ddl.getDay());
        strcpy(softname, p.softname);
        softtype = 'B';
        media = 'H';
    }
    void print(CDate& dl)
    {
        int rest = 0, a = 0;
        cout << "name:" << softname << endl;
        if (softtype == 'O') {
            cout << "type:" << "original" << endl;
        }
        if (softtype == 'T') {
            cout << "type:" << "trial" << endl;
        }
        if (softtype == 'B') {
            cout << "type:" << "backup" << endl;
        }
        if (media == 'D') {
            cout << "media:" << "optical disk" << endl;
        }
        if (media == 'H') {
            cout << "media:" << "hard disk" << endl;
        }
        if (media == 'U') {
            cout << "media:" << "USB disk" << endl;
        }
        if (ddl.getYear() == 0 && ddl.getMonth() == 0 && ddl.getYear() == 0) {
            cout << "this software has unlimited use" << endl<<endl;
        }
        else if (ddl.getYear() < dl.getYear()) {
            cout << "this software has expired" << endl<<endl;
        }
        else if (ddl.getYear() == dl.getYear()) {
            if (ddl.getDayofYear() <= dl.getDayofYear()) {
                cout << "this software has expired" << endl<<endl;
            }
            if (ddl.getDayofYear() > dl.getDayofYear()) {
                cout << "this software is going to be expired in " << (ddl.getDayofYear() - dl.getDayofYear()) << " days" << endl<<endl;
            }
        }
        else if (ddl.getYear() > dl.getYear()) {
            rest = 365 - dl.getDayofYear() + ddl.getDayofYear();
            for (int i = dl.getYear(); i < ddl.getYear(); i++) {
                if (isLeapYear(i)) {
                    rest = rest + 366;
                }
                else {
                    rest = rest + 365;
                }
            }
            cout << "this software is going to be expired in " << rest << " days" << endl<<endl;
        }
    }
};
int main()
{
    int t;
    char* str;
    char type1;
    char media1;
    int y1, m1, d1;
    cin >> t;
    str = new char[100];
    CDate dl(2015, 4, 7);
    while (t--) {
        cin >> str;
        getchar();
        cin >> type1;
        getchar();
        cin >> media1;
        getchar();
        cin >> y1;
        getchar();
        cin >> m1;
        getchar();
        cin >> d1;
        getchar();
        software a(str, type1, media1, y1, m1, d1);
        a.print(dl);
        software b(a);
        b.print(dl);    
    }
    return 0;
}
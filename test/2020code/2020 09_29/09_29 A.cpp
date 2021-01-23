#include <iostream>
using namespace std;
struct student
{
    int year;
    int month;
    int day;
};
student allone[100] = {0};
int main()
{
    int t;
    student a;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> allone[i].year >> allone[i].month >> allone[i].day;
    }
    for (int i = 1; i < t; i++)
    {
        for (int j = 0; j < t - i; j++)
        {
            if (allone[j].year < allone[j + 1].year)
            {
                continue;
            }
            if (allone[j].year > allone[j + 1].year)
            {
                a = allone[j];
                allone[j] = allone[j + 1];
                allone[j + 1] = a;
                continue;
            }
            if (allone[j].month < allone[j + 1].month)
            {
                continue;
            }
            if (allone[j].month > allone[j + 1].month)
            {
                a = allone[j];
                allone[j] = allone[j + 1];
                allone[j + 1] = a;
                continue;
            }
            if (allone[j].day < allone[j + 1].day)
            {
                continue;
            }
            if (allone[j].day > allone[j + 1].day)
            {
                a = allone[j];
                allone[j] = allone[j + 1];
                allone[j + 1] = a;
                continue;
            }
        }
    }
    cout << allone[1].year << "-" << allone[1].month << "-" << allone[1].day << endl;
    return 0;
}

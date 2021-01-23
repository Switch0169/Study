#include <iostream>
using namespace std;
class student
{
public:
    string name;
    string studentid;
    string xname;
    string xrname;
    string gender;
    string address;
    string pnumber;
};
student allone[100];
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> allone[i].name >> allone[i].studentid >> allone[i].xname >> allone[i].xrname >> allone[i].gender >> allone[i].address >> allone[i].pnumber;
    }
    for (int i = 0; i < t; i++)
    {
        cout << allone[i].name << " " << allone[i].studentid << " " << allone[i].xname << " " << allone[i].xrname << " " << allone[i].gender << " " << allone[i].address << " " << allone[i].pnumber << endl;
    }
    return 0;
}
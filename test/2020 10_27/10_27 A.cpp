#include <iostream>
#include <cstring>
using namespace std;
class CTelNumber
{
private:
    char *number;

public:
    CTelNumber(char *str)
    {
        number = new char[100];
        strcpy(number, str);
    }
    CTelNumber(CTelNumber &s)
    {
        number = new char[100];
        char swnumber[10] = {0};
        int i, j;
        int flag=1;
        for (i = 0; 1; i++)
        {
            if (s.number[i] == 0)
            {
                break;
            }
            if(s.number[i]>'9'||s.number[i]<'0'){
                flag= 0*flag;
            }
        }
        
        if (i == 7&& flag == 1)
        {
            if (s.number[0] == '2' || s.number[0] == '3' || s.number[0] == '4')
            {
                swnumber[0] = '8';
                for (j = 1; j < 8; j++)
                {
                    swnumber[j] = s.number[j - 1];
                }
                cout << swnumber << endl;
            }
            else if (s.number[0] == '5' || s.number[0] == '6' || s.number[0] == '7' || s.number[0] == '8')
            {
                swnumber[0] = '2';
                for (j = 1; j < 8; j++)
                {
                    swnumber[j] = s.number[j - 1];
                }
                cout << swnumber << endl;
            }
            else
            {
                cout << "Illegal phone number" << endl;
            }
        }
        else
        {
            cout << "Illegal phone number" << endl;
        }
    }
    ~CTelNumber()
    {
        delete[] number;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char *str;
        str = new char[100];
        cin >> str;
        CTelNumber a(str);
        CTelNumber b(a);
    }
    return 0;
}
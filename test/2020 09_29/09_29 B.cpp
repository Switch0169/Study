#include <iostream>
#include <string>
using namespace std;
struct student
{
    long int studentid;
    string answer1;
    string answer2;
    string answer3;
};
student allone[100] = {0};
int main()
{
    int t, count = 0;
    int size1, size2;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> allone[i].studentid >> allone[i].answer1 >> allone[i].answer2 >> allone[i].answer3;
    }
    for (int i = 0; i < t; i++)
    {
        size1 = allone[i].answer1.length();
        for (int j = i + 1; j < t; j++)
        {
            count = 0;
            size2 = allone[j].answer1.length();
            if (size1 < size2)
            {
                size1 = size2;
            }
            for (int k = 0; k < size1; k++)
            {
                if (allone[i].answer1[k] == allone[j].answer1[k])
                {
                    count++;
                }
            }
            if (count >= size1 * 9 / 10)
            {
                cout<<allone[i].studentid<<" "<<allone[j].studentid<<" "<<"1"<<endl;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        size1 = allone[i].answer2.length();
        for (int j = i + 1; j < t; j++)
        {
            count = 0;
            size2 = allone[j].answer2.length();
            if (size1 < size2)
            {
                size1 = size2;
            }
            for (int k = 0; k < size2; k++)
            {
                if (allone[i].answer2[k] == allone[j].answer2[k])
                {
                    count++;
                }
            }
            if (count >= size1 * 9 / 10)
            {
                cout<<allone[i].studentid<<" "<<allone[j].studentid<<" "<<"2"<<endl;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        size1 = allone[i].answer3.length();
        for (int j = i + 1; j < t; j++)
        {
            count = 0;
            size2 = allone[j].answer3.length();
            if (size1 < size2)
            {
                size1 = size2;
            }
            for (int k = 0; k < size1; k++)
            {
                if (allone[i].answer3[k] == allone[j].answer3[k])
                {
                    count++;
                }
            }
            if (count >= size1 * 9 / 10)
            {
                cout<<allone[i].studentid<<" "<<allone[j].studentid<<" "<<"3"<<endl;
            }
        }
    }
    return 0;
}

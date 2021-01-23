#include<iostream>
#include<cstring>
using namespace std;
class Hotel
{
public:
    Hotel(char *a_Customer)
    {
        ++m_TotalCustNum;
        m_CustomerNum=2015*10000+m_TotalCustNum;
        m_CustomerName=new char[100];
        strcpy(m_CustomerName,a_Customer);
        m_TotalEarning=m_TotalEarning+m_Rent;
    }
    ~Hotel()
    {
        delete[] m_CustomerName;
    }
    void Display()
    {
        cout<<m_CustomerName<<" "<<m_CustomerNum<<" "<<m_TotalCustNum<<" "<<m_TotalEarning<<endl;
    }
    static void Setrecent(float a){
        m_Rent = a;
    }
private:
    static int m_TotalCustNum;
    static float m_TotalEarning;
    static float m_Rent;
    char * m_CustomerName;
    int m_CustomerID;
    static int m_CustomerNum;
};
int Hotel::m_CustomerNum = 0;
int Hotel::m_TotalCustNum = 0;
float Hotel::m_TotalEarning = 0;
float Hotel::m_Rent = 0;
int main()
{
    float rent;
    char *name;
    name = new char[100];
    int flag;
    cin>>rent;
    Hotel::Setrecent(rent);
    while(scanf("%s",name)&&name[0]!='0'){
        Hotel a(name);
        a.Display();
    }
    return 0;
}
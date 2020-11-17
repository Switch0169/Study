#include<iostream>
#include<cstring>
using namespace std;
class CDate

{

private:

    int year, month, day;

public:
    CDate()
    {
        year=0;
        month=0;
        day=0;
    }
    CDate(int y, int m,int d)
    {
        year = y;
        month = m;
        day = d;
    }
    CDate(CDate &r)
    {
        year=r.year;
        month=r.month;
        day=r.day;
    }
    void setDate(int y, int m, int d)
    {
        year=y;
        month=m;
        day=d;
    }
    bool check() //检验日期是否合法
    {
        int a1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        int a2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
        if(isLeapyear()!=0){
            if(a2[month]<day)
                return 0;
            else
                return 1;
        }
        else{
            if(a1[month]<day)
                return 0;
            else
                return 1;
        }
    }
    bool isLeapyear(){return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;}
    int getday(){return day;}
    int getmonth(){return month;}
    int getyear(){return year;}
    void print()
    {
        cout<<year<<"年"<<month<<"月"<<day<<"日";
    }
};
class COldID

{

protected:

    char *p_id15, *p_name; //15位身份证号码，姓名

    CDate birthday; //出生日期

public:

    COldID(char *p_idval, char *p_nameval, CDate &day)
    {
        p_id15 = new char [20];
        p_name = new char [10];
        strcpy(p_id15, p_idval);
        strcpy(p_name, p_nameval);
        birthday.setDate(day.getyear(),day.getmonth(),day.getday());
    }

    virtual bool check() //验证15位身份证是否合法
    {
        int len;
        len = strlen(p_id15);
        if(len==15){
            for(int i = 0; i<len ; i++){
                if(p_id15[i]<'0'||p_id15[i]>'9'){
                    return 0;
                }
            }
            return 1;
        }
        else
            return 0;
    }
    void print();

    ~COldID()
    {
        delete [] p_id15;
        delete [] p_name;
    }

};
class CNewID: public COldID{
protected:
    char *p_id18;
    CDate issueday;
    int validyear;
public:
    CNewID(char *p_idval, char *p_nameval, CDate &day, char *p_id, CDate isu, int val):COldID(p_idval, p_nameval, day)
    {
        p_id18=new char [20];
        strcpy(p_id18,p_id);
        issueday.setDate(isu.getyear(),isu.getmonth(),isu.getday());
        validyear=val;
    }
    bool check()
    {
        int i=0;
        int sum=0;
        int len=0;
        sum=0;
        int a[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        char b[]={'1','0','X','9','8','7','6','5','4','3','2'};
        for(i=0;i<17;i++){
            sum=(p_id18[i]-'0')*a[i]+sum;
        }
        sum=sum%11;
        if(birthday.check()==0)
            return 0;
        if((issueday.getyear()+validyear)<2015)
            return 0;
        if((issueday.getyear()+validyear)==2015){
            if((issueday.getmonth()*100+issueday.getday())<4007)
                return 0;
        }
        if(COldID::check()!=0){
            len=strlen(p_id18);
            if(len!=18)
                return 0;
            for(i=0;i<18;i++){
                if(p_id18[i]<'0'||p_id18[i]>'9'){
                    return 0;
                }
            }
            for(int i=0;i<6;i++){
                if(p_id18[i]!=p_id15[i])
                    return 0;
            }
            for(int i=10;i<17;i++){
                if(p_id18[i]!=p_id15[i-2])
                    return 0;
            }
            if(p_id18[17]!=b[sum])
                return 0;
            return 1;
        }
        else 
            return 0;
    }
    void print()
    {
        cout<<COldID::p_name<<endl;
        if(check()==0)
            cout<<"illegal id";
        else{
            cout<<p_id18<<" ";
            issueday.print();
            cout<<" ";
            if(validyear==100)
                cout<<"长期"<<endl;
            else
                cout<<validyear<<"年"<<endl;
        }
    }
};
int main()
{
    int t;
    char *na;
    int y,m,d;
    char *p15;
    char *p18;
    int y1,m1,d1;
    int v;
    cin>>t;
    na = new char [20];
    p15 = new char [20];
    p18 = new char [20];
    while(t--){
        cin>>na>>y>>m>>d>>p15>>p18>>y1>>m1>>d1>>v;
        CDate c1(y,m,d);
        CDate c2(y1,m1,d1);
        CNewID op(p15,na,c1,p18,c2,v);
        op.print();
    }
    return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
class Employee
{
protected:
    char name[20]={0};
    char pname[20]={0};
    int workyear;
    int level;
    int year;
public:
    Employee(char *n, char *pn, int l, int wy)
    {
        strcpy(name,n);
        strcpy(pname,pn);
        level=l;
        workyear=wy;
    }
    virtual int salary()
    {
        int s;
        s=1000+500*level+50*workyear;
        return s;
    }
    void print()
    {
        if(strcmp(pname,"Employee")!=0&&strcmp(pname,"Teamleader")!=0&&strcmp(pname,"Manager")!=0){
            cout<<"error position."<<endl;
        }
        else if(level<0||workyear<0){
            cout<<"error grade or year."<<endl;
        }
        else
            cout<<name<<":"<<pname<<",Salary:"<<salary()<<endl;
    }
};
class Teamleader:public Employee
{
protected:

public:
    Teamleader(char *n, char *pn, int l, int wy):Employee(n,pn,l,wy)
    {

    }
    virtual int salary()
    {
        int s;
        s=3000+800*level+100*workyear;
        return s;
    }
};
class Manager:public Employee
{
public:
    Manager(char *n, char *pn, int l, int wy):Employee(n,pn,l,wy)
    {

    }
    virtual int salary()
    {
        int s;
        s=5000+1000*level+1000*workyear;
        return s;
    }
};
int main ()
{
    int t;
    cin>>t;
    while(t--){
        char n[20]={0};
        char pn[20]={0};
        int l = 0;
        int wy = 0;
        cin>>n>>pn>>l>>wy;
        Employee *x=NULL;
        if(strcmp(pn,"Employee")==0){
            Employee a(n,pn,l,wy);
            x=&a;
        }
        else if(strcmp(pn,"Teamleader")==0){
            Teamleader a(n,pn,l,wy);
            x=&a;
        }
        else if(strcmp(pn,"Manager")==0){
            Manager a(n,pn,l,wy);
            x=&a;
        }
        else{
            Employee a(n,pn,l,wy);
            x=&a;
        }
        x->print();
    }
    return 0;
}
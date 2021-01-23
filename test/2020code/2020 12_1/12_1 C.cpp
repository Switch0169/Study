#include<iostream>
#include<cstring>
using namespace std;
class Animal{
protected:
    char pname[10]={0};
    char name[10]={0};
    int age = 0;
public:
    Animal(char *pn, char *n, int a)
    {
        strcpy(pname,pn);
        strcpy(name,n);
        age=a;
    }
    virtual void Speak()
    {
        cout<<"There is no "<<pname<<" in our Zoo."<<endl;
    }
};
class Tiger:public Animal
{
protected:

public:
    Tiger(char *pn, char *n, int a):Animal(pn,n,a)
    {

    }
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};
class Pig:public Animal
{
protected:

public:
    Pig(char *pn, char *n, int a):Animal(pn,n,a)
    {

    }
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
class Dog:public Animal
{
protected:

public:
    Dog(char *pn, char *n, int a):Animal(pn,n,a)
    {

    }
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};
class Duck:public Animal
{
protected:

public:
    Duck(char *pn, char *n, int a):Animal(pn,n,a)
    {

    }
    virtual void Speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        char pn[10]={0};
        char n[10]={0};
        int a = 0;
        cin>>pn>>n>>a;
        Animal *x=NULL;
        if(strcmp(pn,"Tiger")==0)
        {
            Tiger c(pn,n,a);
            x=&c;
        }
        else if(strcmp(pn,"Dog")==0)
        {
            Dog c(pn,n,a);
            x=&c;
        }
        else if(strcmp(pn,"Duck")==0)
        {
            Duck c(pn,n,a);
            x=&c;
        }
        else if(strcmp(pn,"Pig")==0)
        {
            Pig c(pn,n,a);
            x=&c;
        }
        else{
            Animal c(pn,n,a);
            x=&c;
        }
        x->Speak();
    }
    return 0;
}
#include<iostream>
using namespace std;
class Bank
{
protected:
	int card;
	int phone;
	int key;
	int cash;
public:
	void set(int c,int p,int k, int ca){
		card=c;
		phone=p;
		key=k;
		cash=ca;
	}
	int getp(){
		return phone;
	}
	int getk(){
		return key;
	}
	int getca(){
		return cash;
	}
	int killca(int x){
		if(x<=cash){
			cash=cash-x;
			cout<<"����"<<card<<"--"<<"���"<<cash<<endl;
		}
		else{
			cout<<"����"<<card<<"--"<<"����"<<endl;
		}
	}
};
int main()
{
	int n,k;
	int flag,flag1,flag2;
	int c1,p1,k1,ca1;
	int p2,k2,ca2;
	cin>>n;
	Bank *a=new Bank[n];
	for(int i=0;i<n;i++){
		cin>>c1>>p1>>k1>>ca1;
		a[i].set(c1,p1,k1,ca1);
	}
	cin>>k;
	for(int i=0;i<k;i++){
		flag=-1;
		flag1=0;
		flag2=0;
		cin>>p2>>k2>>ca2;
		for(int j=0;j<n;j++){
			if(p2==a[j].getp()){
				flag=j;
				if(k2==a[flag].getk()){
					flag1=1;
					a[flag].killca(ca2);
					break;
				}
			}
		}
		if(flag!=-1&&flag1==0){
			cout<<"�������"<<endl;
		}
		if(flag==-1){
			cout<<"�ֻ��Ų�����"<<endl;
		}
		
	} 
	return 0;
}

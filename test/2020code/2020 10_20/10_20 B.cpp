#include<iostream>
using namespace std;
class fus
{
public:
	fus(){
		sb=1;
		xb=1;
	}
	fus(int s,int x){
		sb=s;
		xb=x;
	}
	void sum(fus &r){
		int ss;
		int xx;
		ss=sb+r.sb;
		xx=xb+r.xb;
		cout<<"sum:";
		if(ss!=0){
			cout<<ss;
		}
		if(ss!=0&&xx==0){
			cout<<endl;
		}
		if(xx<0){
			cout<<xx<<"i"<<endl;		
		}
		if(xx==0&&ss==0){
			cout<<"0"<<endl;
		}
		if(xx>0&&ss!=0&&xx!=1){
			cout<<"+"<<xx<<"i"<<endl;
		}
		if(ss!=0&&xx==1){
			cout<<"+"<<"i"<<endl;
		}
		if(ss==0&&xx==1){
			cout<<"i"<<endl;
		}
		if(xx>0&&ss==0){
			cout<<xx<<"i"<<endl;
		}
	}
	void remainder(fus &r){
		int ss;
		int xx;
		ss=sb-r.sb;
		xx=xb-r.xb;
		cout<<"remainder:";
		if(ss!=0){
			cout<<ss;
		}
		if(ss!=0&&xx==0){
			cout<<endl;
		}
		if(xx<0){
			cout<<xx<<"i"<<endl;		
		}
		if(xx==0&&ss==0){
			cout<<"0"<<endl;
		}
		if(xx>0&&ss!=0&&xx!=1){
			cout<<"+"<<xx<<"i"<<endl;
		}
		if(ss!=0&&xx==1){
			cout<<"+"<<"i"<<endl;
		}
		if(ss==0&&xx==1){
			cout<<"i"<<endl;
		}
		if(xx>0&&ss==0){
			cout<<xx<<"i"<<endl;
		}
	}
protected:
	int sb;
	int xb;	
};
int main()
{
	int t;
	int s,x,s1,x1;
	cin>>t;
	while(t--){
		cin>>s>>x>>s1>>x1;
		fus a(s,x);
		fus b(s1,x1);
		a.sum(b);
		a.remainder(b);
	}
	return 0;
}

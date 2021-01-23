#include<iostream>
using namespace std;
int i;
int n;
class print
{
public:
	print()
	{
	    cout<<"Constructing object "<<i<<endl;
	    if(i<n){
	    	i++;
	    	print c;
		}
	} 
	~print()
	{
	    cout<<"Destructing object "<<i<<endl;
	    i--;
	}
};
int main()
{
    int t;
    cin>>t;
    while(t--){
    	i=1;
    	cin>>n;
    	print b;
	}
    return 0;
}

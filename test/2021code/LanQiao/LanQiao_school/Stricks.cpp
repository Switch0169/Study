#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> possible;
    vector<int> possible_i;
    vector<int> per;
    int n;
    int total = 0;
    cin>>n;
    int count = 0;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        total += t;
        per.push_back(t);
    }
    for(int i=n; i>=1; i--){
        if(total%i==0){
            possible.push_back(total/i);
            possible_i.push_back(i);
            count++;
        }
    }
    int minx = 1000;
    for(int i=0; i=count; i++){
        int check = 0;
        for(int j=0; j<possible_i[i]; j++){
            int temp = 0;
            per.
            while(1){
                
            }
        }
    }
    return 0;
}
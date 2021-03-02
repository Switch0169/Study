#include<iostream>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

struct task{
    string name;
    int time;
};

int main()
{
    int total_time =0;
    queue<task> Q;
    int n;
    int ptime;
    int t;
    cin>>n;
    cin>>ptime;
    string nn;
    task *mytask = new task [n];
    for(int i=0; i<n; i++){
        cin>>nn;
        cin>>t;
        mytask[i].name = nn;
        mytask[i].time = t;
    }
    for(int i=0; i<n; i++){
        Q.push(mytask[i]);
    }
    while(Q.empty()!=true){
        task k = Q.front();
        Q.pop();
        if(k.time - ptime > 0){
            k.time = k.time - ptime;
            Q.push(k);
            total_time += ptime;
        }
        else{
            int temp = k.time;
            k.time = total_time + k.time;
            total_time += temp;
            cout<<k.name<<" "<<k.time<<endl;
        }
    }
    return 0;
}
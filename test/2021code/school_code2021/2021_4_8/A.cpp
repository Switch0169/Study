#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> qA;
    queue<int> qB;
    queue<int> qC;
    queue<char> type;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        char temp;
        cin>>temp;
        type.push(temp);
    }
    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        if(type.front() == 'A'){
            qA.push(num);
        }
        else if(type.front() == 'B'){
            qB.push(num);
        }
        else if(type.front() == 'C'){
            qC.push(num);
        }
        type.pop();
    }
    int tt = 0;
    int count = 0;
    while(!qA.empty()){
        tt += qA.front();
        qA.pop();
        count++;
    }
    cout<<tt/count<<endl;
    tt = 0;
    count = 0;
    while(!qB.empty()){
        tt += qB.front();
        qB.pop();
        count++;
    }
    cout<<tt/count<<endl;
    tt = 0;
    count = 0;
    while(!qC.empty()){
        tt += qC.front();
        qC.pop();
        count++;
    }
    cout<<tt/count<<endl;
    return 0;
}
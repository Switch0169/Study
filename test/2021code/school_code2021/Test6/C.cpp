#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main()
{
    queue<int> myQ[10];
    queue<int> ans;
    queue<int> other;
    queue<int> No;
    queue<int> set[10];
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int tt;
        cin>>tt;
        while(tt--){
            int temp;
            cin >> temp;
            set[i].push(temp);
        }
    }
    while(1){
        string str;
        cin>>str;
        if(str == "STOP"){
            while(!ans.empty()){
                cout<<ans.front()<<" ";
                ans.pop();
            }
            break;
        }
        else if(str == "ENQUEUE"){
            int num;
            cin>>num;
            int nofind_flag = 1;
            for(int i = 0; i < t; i++){
                queue<int> temp_q;
                while(!set[i].empty()){
                    if(set[i].front() == num){
                        nofind_flag *= 0;
                        myQ[i].push(num);
                        queue<int> tempNo;
                        int No_flag = 1;
                        while(!No.empty()){
                            if(No.front() == i){
                                No_flag = 0;
                            }
                            tempNo.push(No.front());
                            No.pop();
                        }
                        while(!tempNo.empty()){
                            No.push(tempNo.front());
                            tempNo.pop();
                        }
                        if(No_flag == 1){
                            No.push(i);
                        }
                    }
                    temp_q.push(set[i].front());
                    set[i].pop();
                }
                while(!temp_q.empty()){
                    set[i].push(temp_q.front());
                    temp_q.pop();
                }
                if(nofind_flag == 0){
                    break;
                }
                else{
                    other.push(num);
                }
            }
        }
        else if(str == "DEQUEUE"){
            if(!No.empty()){
                int p = No.front();
                ans.push(myQ[p].front());
                myQ[p].pop();
                if(myQ[p].empty()){
                    No.pop();
                }
            }
            else{
                if(!other.empty()){
                    ans.push(other.front());
                    other.pop();
                }
            }
        }
    }
    return 0;
}
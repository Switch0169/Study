#include<iostream>
#include<algorithm>
using namespace std;
class Node{
public:
    int s;
    int e;
};
bool cmp(Node a, Node b){
    return a.e < b.e;
}
int main()
{
    int n;
    while(cin >> n){
        Node *Ti = new Node [101];
        if(n == 0){
            break;
        }
        for(int i = 0; i < n; i++){
            cin >> Ti[i].s >> Ti[i].e;
        }
        sort(Ti, Ti + n, cmp);
        int now = Ti[0].e;
        int count = 1;
        for(int i = 1; i < n; i++){
            if(now <= Ti[i].s){
                now = Ti[i].e;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
#include <iostream>
#include <map>
using namespace std;
char ch[1001];
int count[1001];
int main()
{
    map<int, int> m;
    cin>>ch;
    for(int i=0; ch[i]; i++){
        int value = 1;
        m[ch[i] - 'a'] += value;
    }
    int maxn = 0;
    int maxm = 0;
    for(map<int, int>::iterator iter = m.begin(); iter != m.end(); iter ++){
        if(iter -> second > maxn){
            maxn = iter -> second;
            maxm = iter -> first;
        }
    }
    cout<<(char)(maxm + 'a')<<endl;
    cout<<maxn;
    return 0;
}
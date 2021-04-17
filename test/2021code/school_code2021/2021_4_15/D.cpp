#include<iostream>
#include<string>
using namespace std;
int getmax(int maxn, int t){
    if(t > maxn){
        maxn = t;
    }
    return maxn;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int maxn = -1;
        int len = str.size();
        for(int i = 0; i < len / 2; i++){
            for(int j = 1; j <= len/2; j++){
                string sub = str.substr(i, j);
                int p = str.find(sub, i+1);
                if(p != string::npos){
                    maxn = getmax(maxn, j);
                }
            }
        }
        cout << maxn <<endl;
    }
    return 0;
}
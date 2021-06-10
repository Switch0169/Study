#include<iostream>
#include<vector>
using namespace std;
vector<int> q;
int pos = 0;
void buildBlock(int val, vector<int> &v){
    int len = q.size();
    for(int i = pos; i < len; i++){
        if(q[i] <= val){
            v.push_back(q[i]);
        }
        else{
            pos = i;
            break;
        }
    }
    return;
}
int Search(int target, vector<int> &v){
    int len = v.size();
    for(int i = 0; i < len; i++){
        if(target == v[i]){
            return i;
        }
    }
    return -1;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);
    int n;
    while(cin >> n){
        pos = 0;
        q.clear();
        for(int i = 1; i <= n; i++){
            int val;
            cin >> val;
            q.push_back(val);
        }
        int k;
        cin >> k;
        vector<int> v;
        vector<int> block[1000];
        for(int i = 0; i < k; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        for(int i = 0; i < k; i++){
            buildBlock(v[i], block[i]);
        }
        int t;
        cin >> t;
        for(int i = 0; i < t; i++){
            int target;
            cin >> target;
            int final = 0;
            int ans = -1;
            int count = 0;
            for(int j = 0; j < k; j++){
                count++;
                if(target <= v[j]){
                    ans = Search(target, block[j]);
                    count += ans + 1;
                    if(ans != -1){
                        final = j;
                        ans++;
                        for(int l = 0; l < final; l++){
                            ans += block[l].size();
                        }
                        break;
                    }
                }
            }
            if(ans == -1){
                cout << "error" << endl;
            }
            else
                cout << ans << "-" << count << endl;
        }
    }
    return 0;
}
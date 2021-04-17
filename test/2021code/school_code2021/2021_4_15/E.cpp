#include<iostream>
#include<string>
using namespace std;
int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int len = str.size();
        char first = str[0];
        int xlen = -1;
        int p = str.find(first, 1);
        if(p != string::npos){
            xlen = p;
        }
        if(xlen == -1){
            cout << len << endl;
        }
        else{
            int final = str.find_last_of(first);
            while(p < final && p + xlen < len){
                string xstr = str.substr(0, xlen);
                string sub = str.substr(p, xlen);
                if(sub != xstr){
                    int temp = str.find(first, p + 1);
                    if(temp != string::npos){
                        p = str.find(first, p + 1);
                        xlen = p;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(p + xlen < len){
                        p += xlen;
                    }
                    else{
                        break;
                    }
                }
            }
            string s1 = str.substr(p, len - p);
            string s2 = str.substr(0, len - p);
            if(s1 == s2){
                cout << xlen - (len - p) << endl;
            }
            else{
                cout << len << endl;
            }
        }
    }
    return 0;
}
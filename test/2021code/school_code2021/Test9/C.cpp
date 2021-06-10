#include<iostream>
#include<string>
using namespace std;
class HuffmanNode{
public:
    int weight;
    char ch;
    int deep;
};
int Treelen = 0;
string str;
int ind = 0;
int ans = 0;
int t = 0;
int value[1000];
HuffmanNode HuffmanTree[10000];
void init()
{
    ind = 0;
    ans = 0;
    t = 0;
}
void CreateTree(int d){
    if(ind >= str.length() || str[ind] == '0'){
        ind++;
        return ;
    }
    if(str[ind] >= 'A' && str[ind] <= 'Z'){
        ans += d * value[t++];
    }
    ind++;
    CreateTree(d + 1);
    CreateTree(d + 1);
}

int main()
{
    int n;
    cin >> n;
    while(n--){
        init();
        cin >> str;
        int N;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> value[i];
        }
        CreateTree(0);
        cout << ans << endl;
    }
    return 0;
}
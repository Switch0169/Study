#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int ind = 0;
int len;
string str;
int maxn;
int maxid;
int firstid;
char Tree[10000];
bool visited[10000];
void init(){
    maxn = 0;
    maxid = 0;
    firstid = 0;
    ind = 0;
    memset(visited, 0, sizeof(visited));
    memset(Tree, 0, sizeof(Tree));
}
void CreateTree(int i){
    if(ind >= len || str[ind] == '#'){
        Tree[i] = str[ind];
        ++ind;
        return;
    }
    Tree[i] = str[ind];
    ++ind;
    CreateTree(2 * i);
    CreateTree(2 * i + 1);
}
void Search(int i, int d){
    if(Tree[i] == '#' || i == 0 || visited[i] == 1){
        return;
    }
    visited[i] = 1;
    Search(2 * i, d + 1);
    Search(2 * i + 1, d + 1);
    Search(i / 2, d + 1);
    if(Tree[2 * i] == '#' && Tree[2 * i + 1] == '#'){
        if(maxn < d){
            maxn = d;
            maxid = i;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> str;
        len = str.size();
        init();
        CreateTree(1);
        Search(1, 0);
        firstid = maxid;
        maxid = 0;
        maxn = 0;
        memset(visited, 0, sizeof(visited));
        Search(firstid, 0);
        cout << maxn<< ":";
        if(maxid != firstid){
            cout << Tree[firstid] << " " << Tree[maxid];
        }
        cout << endl;
    }
    return 0;
}
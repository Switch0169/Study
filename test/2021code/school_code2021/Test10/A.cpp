#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

char Tree[1000000];
string str;
int p = 0;
queue<int> q;
int tp = 1;
int len;

void init(){
    memset(Tree, 0, sizeof(Tree));
    p = 0;
    while(!q.empty()){
        q.pop();
    }
    tp = 1;    
}
void BuildTree(int n){
    if(str[p] == '0'){
        Tree[n] = str[p++];
        return;
    }
    Tree[n] = str[p++];
    BuildTree(2 * n);
    BuildTree(2 * n + 1);
}
void Search(){
    if(Tree[tp] != '0')
        q.push(tp);
    while(!q.empty()){
        tp = q.front();
        q.pop();
        cout << Tree[tp];
        if(Tree[2 * tp] != '0'){
            q.push(2 * tp);
        }
        if(Tree[2 * tp + 1] != '0'){
            q.push(2 * tp + 1);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    while(n--){
        init();
        cin >> str;
        len = str.size();
        BuildTree(1);
        Search();
        cout << endl;
    }
    return 0;
}
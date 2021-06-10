#include<iostream>
using namespace std;

class Node{
public:
    int num;
    char data;
    Node(){
        num = 0;
        data = '0';
    }
    void init(){
        num = 0;
        data = '0';
    }
};

Node Tree[100000];
char str[100000];
int pos = 1;
int str_len;

void init(){
    for(int i = 0; i < 100000; i++){
        Tree[i].init();
        str[i] = 0;
        pos = 1;
    }
}
int getnum(int p){
    int ret = (Tree[2 * p].num > Tree[2 * p + 1].num) ? Tree[2 * p].num : Tree[2 * p + 1].num;
    if(Tree[p].data != '0'){
        ret++;
    }
    return ret;
}
void BuildTree(){
    for(int i = 1; i <= str_len; i++){
        Tree[i].data = str[i - 1];
    }
    for(int i = str_len; i >= 1; i--){
        Tree[i].num = getnum(i);
    }
}
int getbalance(int p){
    return Tree[2 * p].num - Tree[2 * p + 1].num; 
}
void Search(int p){
    if(Tree[p].data == '0'){
        return ;
    }
    else{
        Search(2 * p);
        Search(2 * p + 1);
        cout << Tree[p].data << " " << getbalance(p) << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        init();
        cin >> str_len;
        cin >> str;
        BuildTree();
        Search(1);
    }
    return 0;
}
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int getnum(char ch){
    return ch - 'a';
}

class Node
{
public:
    char ch;
    Node *child[26];
    int count;
    Node(){
        ch = 0;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        count = 0;
    }
};

Node *root;
string str;
int pos;
int len;
queue<Node*> q;

void init(){
    pos = 0;
    root = new Node();
}
bool isLeaf(Node * r){
    for(int i = 0; i < 26; i++){
        if(r->child[i] != NULL){
            return 0;
        }
    }
    return 1;
}
void buildTree(Node *r){
    if(pos < len){
        Node *n;
        if(r->child[getnum(str[pos])] == NULL){
            n = new Node();
            n->ch = str[pos];
            n->count = 1;
            r->child[getnum(str[pos])] = n;
        }
        else{
            n = r->child[getnum(str[pos])];
            n->count ++;
        }
        pos++;
        buildTree(n);
    }
    return ;
}
void BFS(Node *r){
    if(r == NULL){
        return ;
    }
    for(int i = 0; i < 26; i++){
        if(r->child[i] != NULL){
            q.push(r->child[i]);
        }
    }
    while(!q.empty()){
        Node *p = q.front();
        q.pop();
        for(int i = 0; i < 26; i++){
            if(p->child[i] != NULL){
                q.push(p->child[i]);
            }
        }
        cout << p->ch;
    }
}
void dfs(Node *r){
    if(pos < len){
        Node *n = r->child[getnum(str[pos])];
        pos++;
        dfs(n);
    }
    else{
        if(r != NULL)
            cout << r->count << endl;
        else{
            cout << 0 << endl;
        }
    }
    return;
}
int main()
{
    string line;
    while(getline(cin, line)){
        init();
        int line_len = line.length();
        int start = 0;
        for(int i = 0; i <= line_len; i++){
            if(i == line_len){
                str = line.substr(start, i - start);
                len = str.size();
                pos = 0;
                buildTree(root);
            }
            if(line[i] == ' '){
                str = line.substr(start, i - start);
                len = str.size();
                pos = 0;
                buildTree(root);
                start = i + 1;
            }
        }
        BFS(root);
        cout << endl;
        int t;
        cin >> t;
        for(int i = 0; i < t; i++){
            cin >> str;
            len = str.size();
            pos = 0;
            dfs(root);
        }
    }
    return 0;
}
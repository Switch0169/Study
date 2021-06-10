#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

class Node{
public:
    Node(){
        ch = '0';
        lchild = NULL;
        rchild = NULL;
        value = 0;
    }
    char ch;
    Node *lchild;
    Node *rchild;
    int value;
};

string str;
int v[10000];
int p;
int p1;
int maxn = 0;
Node *root = new Node();

void getmax(int t){
    if(t > maxn){
        maxn = t;
    }
}

void init(){
    p = 0;
    p1 = 0;
    maxn = 0;
    root->ch = '0';
    root->lchild = NULL;
    root->rchild = NULL;
    root->value = 0;
}

void BuildTree(Node *r){
    if(str[p] == '0'){
        r->ch = str[p++];
        return;
    }
    r->ch = str[p++];
    r->value = v[p1++];
    Node *lc = new Node();
    r->lchild = lc;
    BuildTree(lc);
    Node *rc = new Node();
    r->rchild = rc;
    BuildTree(rc);
}

void search1(Node *r, int val){
    if(r->ch == '0')
        return;
    if(r->lchild->ch == '0' && r->rchild->ch == '0'){
        getmax(val + r->value);
    }
    search1(r->lchild, val + r->value);
    search1(r->rchild, val + r->value);
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> str;
        init();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        BuildTree(root);
        search1(root, 0);
        cout << maxn << endl;
    }
    return 0;
}
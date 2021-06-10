#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

class Node{
public:
    Node(){
        ch = '#';
        lchild = NULL;
        rchild = NULL;
    }
    char ch;
    Node *lchild;
    Node *rchild;
};

string str;
int p;
Node *root = new Node();
queue<Node*> q;
queue<Node*> q1;
Node *tp;

void init(){
    p = 0;
    root->ch = '#';
    root->lchild = NULL;
    root->rchild = NULL; 
}

void BuildTree(Node *r){
    if(str[p] == '#'){
        r->ch = str[p++];
        return;
    }
    r->ch = str[p++];
    Node *lc = new Node();
    r->lchild = lc;
    BuildTree(lc);
    Node *rc = new Node();
    r->rchild = rc;
    BuildTree(rc);
}
void turn(Node *r){
    if(r->ch != '#'){
        q.push(r);
    }
    else{
        return;
    }
    while(!q.empty()){
        tp = q.front();
        q.pop();
        Node *l = tp->lchild;
        tp->lchild = tp->rchild;
        tp->rchild = l;
        if(tp->lchild->ch != '#'){
            q.push(tp->lchild);
        }
        if(tp->rchild->ch != '#'){
            q.push(tp->rchild);
        }
    }
}
void search1(Node *r){
    if(r->ch == '#' && r == root){
        cout << "NULL";
        return;
    }
    if(r->ch == '#')
        return;
    cout << r->ch << " ";
    search1(r->lchild);
    search1(r->rchild);
}
void search2(Node *r){
    if(r->ch == '#' && r == root){
        cout << "NULL";
        return;
    }
    if(r->ch == '#')
        return;
    search2(r->lchild);
    cout << r->ch << " ";
    search2(r->rchild);
}
void search3(Node *r){
    if(r->ch == '#' && r == root){
        cout << "NULL";
        return;
    }
    if(r->ch == '#')
        return;
    search3(r->lchild);
    search3(r->rchild);
    cout << r->ch << " ";
}
void search4(Node *r){
    if(r->ch == '#' && r == root){
        cout << "NULL";
        return;
    }
    if(r->ch != '#'){
        q1.push(r);
    }
    else{
        return;
    }
    while(!q1.empty()){
        tp = q1.front();
        q1.pop();
        cout << tp -> ch << " ";
        if(tp->lchild->ch != '#'){
            q1.push(tp->lchild);
        }
        if(tp->rchild->ch != '#'){
            q1.push(tp->rchild);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> str;
        init();
        BuildTree(root);
        turn(root);
        search1(root);
        cout << endl;
        search2(root);
        cout << endl;
        search3(root);
        cout << endl;
        search4(root);
        cout << endl;
    }
    return 0;
}
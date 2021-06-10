#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Node{
public:
    Node(){
        ch = '0';
        lchild = NULL;
        rchild = NULL;
        tag = 1;
    }
    char ch;
    Node *lchild;
    Node *rchild;
    bool tag;
};

string str;
int p;
Node *root = new Node();
stack<Node*> s;

void init(){
    p = 0;
    root->ch = '0';
    root->lchild = NULL;
    root->rchild = NULL;
    root->tag = 1;    
}
void BuildTree(Node *r){
    if(str[p] == '0'){
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
void Search(Node *r){
    if(r->ch == '0'){
        return;
    }
    else{
        Node *tp = r;
        s.push(tp);
        tp->tag = 0;
        tp = tp -> lchild;
        while(!s.empty()){
            if(tp->ch == '0'){
                if(s.top()->tag){
                    tp = s.top();
                    s.pop();
                    cout << tp->ch;
                    tp -> ch = '0';
                }
                else{
                    tp = s.top()->rchild;
                    s.top()->tag = 1;
                }
            }
            else{
                s.push(tp);
                tp->tag = 0;
                tp = tp -> lchild;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        init();
        cin >> str;
        BuildTree(root);
        Search(root);
        cout << endl;
    }
    return 0;
}
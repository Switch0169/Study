#include<iostream>
#include<string>

using namespace std;

int post[10000];
int in[10000];
int minx = 0xffff;

void init(){
    minx = 0xffff;
}
void getmin(int t){
    if(t < minx){
        minx = t;
    }
}
class Node{
public:
    Node(){
        data = 0;
        lchild = NULL;
        rchild = NULL;
    }
    int data;
    Node *lchild;
    Node *rchild;
};

Node* buildTree(int *post, int *in, int n) {
    if (n == 0) {
        return NULL;
    }
    Node* root = new Node();
    root -> data = post[n - 1];
    int rnum = root -> data;
    int index;
    for(int i = 0; i < n; i++){
        if(rnum == in[i]){
            index = i;
            break;
        }
    }
    int left = index;
    int right = n - index - 1;
    root -> lchild = buildTree(post, in, left);
    root -> rchild = buildTree(post + left, in + index + 1, right);
    return root;
}
void search1(Node *r){
    if(r == NULL)
        return;
    if(r->lchild == NULL && r->rchild == NULL){
        getmin(r->data);
    }
    search1(r->lchild);
    search1(r->rchild);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int num;
        cin >> num;
        init();
        for(int i = 0; i < num; i++){
            cin >> in[i];
        }
        for(int i = 0; i < num; i++){
            cin >> post[i];
        }
        Node * root = buildTree(post, in, num);
        search1(root);
        cout << minx << endl;
    }
    return 0;
}
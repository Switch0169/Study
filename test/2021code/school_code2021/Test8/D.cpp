#include<iostream>
#include<string>
#include<vector>
using namespace std;
class BiTreeNode{
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode():LeftChild(NULL), RightChild(NULL){}
    ~BiTreeNode(){
        delete LeftChild;
        delete RightChild;
    }
};
class BiTree{
private:
    BiTreeNode *Root;
    int pos;
    string strTree;
    int num = 0;
    BiTreeNode* CreateBiTree(BiTreeNode *p){
        int len = strTree.size();
        if(pos > len){
            return Root;
        }
        p -> data = strTree[pos];
        if(strTree[++pos]!='0'){
            BiTreeNode *t = new BiTreeNode();
            p -> LeftChild = t;
            CreateBiTree(p->LeftChild);
        }
        if(strTree[++pos]!='0'){
            BiTreeNode *t = new BiTreeNode();
            p -> RightChild = t;
            CreateBiTree(p->RightChild);
        }
        return Root;
    }
    void PreOrder(BiTreeNode* t, BiTreeNode *fa){
        if(t != NULL){
            if(t->LeftChild == NULL && t-> RightChild == NULL){
                cout << t->data << " ";
                v.push_back(fa->data);
            }
            PreOrder(t->LeftChild, t);
            PreOrder(t->RightChild, t);
        }
    }
    void InOrder(BiTreeNode* t){
        if(t != NULL){
            InOrder(t->LeftChild);
            if(t->data != '0')
                cout << t->data;
            InOrder(t->RightChild);
        }
    }
    void PostOrder(BiTreeNode* t){
        if(t != NULL){
            PostOrder(t->LeftChild);
            PostOrder(t->RightChild);
            if(t->data != '0')
                cout << t->data;
        }
    }
public:
    vector<char> v;
    BiTree(){
        Root = new BiTreeNode();
    }
    ~BiTree(){
        delete Root;
    }
    void CreateTree(string TreeArray){
        pos = 0;
        strTree.assign(TreeArray);
        Root = new BiTreeNode();
        Root = CreateBiTree(Root);
    }
    void PreOrder(){
        PreOrder(Root, Root);
    }
    void InOrder(){
        InOrder(Root);
    }
    void PostOrder(){
        PostOrder(Root);
    }
    void print(){
        cout << num << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string str;
        cin >> str;
        BiTree mytree;
        mytree.CreateTree(str);
        mytree.PreOrder();
        cout << endl;
        for(int i = 0; i < mytree.v.size(); i++){
            cout << mytree.v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
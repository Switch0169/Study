#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int first[41];
int mid[41];
struct TNode{
    int data;
    TNode *lchild, *rchild;
};
int getdata(){
    int rd;
    scanf("%d",&rd);
    return rd;
}
void Preorder(TNode *T){
    if(T!=NULL){
        T->data = getdata();
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}
void Inorder(TNode *T){
    if(T!=NULL){
        Inorder(T->lchild);
        T->data = getdata();
        Inorder(T->rchild);
    }
}
void Postorder(TNode *T){
    if(T!=NULL){
        Postorder(T->lchild);
        Postorder(T->rchild);
        T->data = 0;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    return 0;
}
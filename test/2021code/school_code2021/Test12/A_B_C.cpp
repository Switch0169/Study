#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


class Node{
public:
    int key;
    int left;
    int right;
    Node(){
        key = left = right = -1;
    }
    void build(int k){
        key = k;
    }
};
Node Tree[10000];
int pos = 0;
int find_count = 0;
void init(){
    memset(Tree, -1, sizeof(Tree));
    pos = 0;
    find_count = 0;
}
void BuildTree(int &now, int key){
    if(now == -1){
        now = pos;
        Tree[pos++].build(key);
    }
    else if(key < Tree[now].key){
        BuildTree(Tree[now].left, key);
    }
    else if(key > Tree[now].key){
        BuildTree(Tree[now].right, key);
    }
}
void Search(int p){
    if(p == -1){
        return;
    }
    else{
        Search(Tree[p].left);
        cout << Tree[p].key << " ";
        Search(Tree[p].right);
    }
}
int flag = 0;
void find(int p, int key){
    if(p == -1){
        return;
    }
    else{
        find_count++;
        if(key == Tree[p].key){
            flag = 1;
            return;
        }
        else if(key < Tree[p].key) find(Tree[p].left, key);
        else if(key > Tree[p].key) find(Tree[p].right, key);
    }
}
void Delete(int &now, int key){
    if(now == -1){
        return;
    }
    else{
        if(key == Tree[now].key){
            if(Tree[now].left == -1 && Tree[now].right == -1){
                now = -1;
            }
            else if(Tree[now].left == -1 || Tree[now].right == -1){
                if(Tree[now].left == -1){
                    now = Tree[now].right;
                }
                else{
                    now = Tree[now].left;
                }
            }
            else{
                int pre = Tree[now].left;
                while(Tree[pre].right != -1){
                    pre = Tree[pre].right;
                }
                Tree[now].key = Tree[pre].key;
                Delete(Tree[now].left, Tree[pre].key);
            }
            return;
        }
        else if(key < Tree[now].key) Delete(Tree[now].left, key);
        else if(key > Tree[now].key) Delete(Tree[now].right, key);
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        init();
        pos = 0;
        int root = -1;
        for(int i = 0; i < n; i++){
            int key;
            cin >> key;
            BuildTree(root, key);
        }
        Search(root);
        cout << endl;
        cin >> n;
        for(int i = 0; i < n; i++){
            int key;
            cin >> key;
            Delete(root, key);
            Search(root);
            cout << endl;
        }
    }
    return 0;
}
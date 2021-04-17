#include<iostream>
#include<cstdio>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *pre;
    Node(){
        next = NULL;
        pre = NULL;
    }
};

class LinkList{
public:
    int len;
    Node *head = new Node();
    LinkList(){
        head->data = 0;
        len = 0;
    }
    Node* turn_to(int n){
        Node *p = head;
        while(n--){
            p = p->next;
        }
        return p;
    }
    void insert(int d, int w){
        Node *p = turn_to(w);
        Node *x = new Node();
        x->data = d;
        if(w==0){
            x -> pre = NULL;
        }
        else
            x->pre = p;
        p->next = x;
        len++;
    }
    void del(int n){
        Node *p = turn_to(n-1);
        if(n == len)
            p->next = NULL;
        else
            p->next = p->next->next;
        len--;
    }
    int find(int key){
        Node *p = head;
        int find_count = 1;
        while(p){
            p = p->next;
            if(p->data == key){
                return find_count;
            }
            find_count++;
        }
        return -1;
    }
    void print(int key){
        Node *p = turn_to(find(key));
        if(p->pre != NULL){
            cout<<p->pre->data<<" ";
        }
        if(p->next != NULL){
            cout<<p->next->data;
        }
        cout<<endl;
    }
    ~LinkList(){
        delete head;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    LinkList mylist;
    for(int i=0; i<n; i++){
        int key;
        cin>>key;
        mylist.insert(key, i);
    }
    for(int i=0; i<m; i++){
        int key;
        cin>>key;
        mylist.print(key);
    }
    return 0;
}
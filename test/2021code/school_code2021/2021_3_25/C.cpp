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
    void insert(int d, int w, int n){
        Node *p = turn_to(len);
        Node *x = new Node();
        x->data = d;
        x->pre = p;
        p->next = x;
        if(w == n){
            x->next = head;
        }
        len++;
    }
    void del(Node *p){
        p->next->pre = p->pre;
        p->pre->next = p->next;
        len--;
    }
    int find(int K, int S){
        Node *p = turn_to(S);
        int find_count = 1;
        while(p){
            if(p == head){
                p = p->next;
            }
            if(len == 1 && p == head){
                p = p->next;
                print(p);
                break;
            }
            if(len == 1 && p != head){
                print(p);
                break;
            }
            if(find_count == K){
                print(p);
                del(p);
                find_count = 0;
            }
            p = p->next;
            find_count++;
        }
        return -1;
    }
    void print(Node *p){
        cout<<p->data<<" ";
    }
    ~LinkList(){
        delete head;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N, K, S;
        cin>>N>>K>>S;
        LinkList mylist;
        for(int i=1; i<=N; i++){
            mylist.insert(i, i, N);
        }
        mylist.find(K, S);
        cout<<endl;
    }
    return 0;
}
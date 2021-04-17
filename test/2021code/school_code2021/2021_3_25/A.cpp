#include<iostream>
#include<cstdio>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    // Node *pre;
    Node(){
        next = NULL;
        // pre = NULL;
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
        Node *p = turn_to(len);
        Node *x = new Node();
        x->data = d;
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
    void del_find(){
        Node *goal = head;
        for(int i=1; i<=len; i++){
            goal = goal->next;
            Node *p = head;
            int find_count = 0;
            while(p){
                if(find_count == i){
                    find_count++;
                    p = p->next;
                    continue;
                }
                if(p->data == goal->data){
                    del(find_count);
                    find_count--;
                }
                p = p->next;
                find_count++;
            }
        }
    }
    void print(){
        printf("%d:",len);
        Node *p = head->next;
        while(p){
            cout<<" "<<p->data;
            p = p->next;
        }
        cout<<endl;
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
        LinkList *mylist = new LinkList();
        int n;
        cin>>n;
        int data;
        for(int i=1; i<=n; i++){
            cin>>data;
            mylist->insert(data, i);
        }
        mylist->del_find();
        mylist->print();
        delete mylist;
    }
    return 0;
}
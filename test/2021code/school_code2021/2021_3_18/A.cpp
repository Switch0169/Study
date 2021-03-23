#include<iostream>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode()
    {
        next = NULL;
    }
};
class LinkList
{
public:
    ListNode *head;
    int len;
    LinkList(){
        head = new ListNode();
        len = 0;
    }
    ~LinkList(){
        ListNode *p, *q;
        p = head;
        while(p != NULL){
            q = p;
            p = p->next;
            delete q;
        }
        len = 0;
        head = NULL;
    }
    ListNode *LL_index(int i)
    {
        if(i > len || i<0 ){
            return NULL;
        }
        else{
            ListNode *p = head;
            int l = i;
            while(l--){
                p = p->next;
            }
            return p;
        }
    }
    int LL_get(int i){
        if( i>len || i<= 0 ){
            cout<<"error"<<endl;
            return -1;
        }
        ListNode *p = LL_index(i);
        return p->data;
    }
    int LL_insert(int i, int item){
        if(i > len+1 || i <= 0){
            cout<<"error"<<endl;
            return 0;
        }
        ListNode *pre = LL_index(i-1);
        ListNode *now = new ListNode();
        now->data = item;
        now->next = pre->next;
        pre->next = now;
        len++;
        return 1;
    }
    int LL_del(int i){
        if( i <= 0  || i > len ){
            cout<<"error"<<endl;
            return 0;
        }
        ListNode *goal = LL_index(i);
        ListNode *pre = LL_index(i-1);
        pre->next = goal->next;
        len--;
        return 1;
    }
    int LL_display(){
        ListNode *p;
        p = head->next;
        while(p){
            cout<< p->data <<' ';
            p = p->next;
        }
        cout<<endl;
        return 0;
    }
};
int main()
{
    int n;
    cin>>n;
    LinkList mylist;
    for(int i=1; i<=n; i++){
        int item;
        cin>>item;
        mylist.LL_insert(i, item);
    }
    mylist.LL_display();
    int p, data;
    cin>>p>>data;
    if(mylist.LL_insert(p, data)==1){
        mylist.LL_display();
    }
    cin>>p>>data;
    if(mylist.LL_insert(p, data)==1){
        mylist.LL_display();
    }
    cin>>p;
    if(mylist.LL_del(p)==1){
        mylist.LL_display();
    }
    cin>>p;
    if(mylist.LL_del(p)==1){
        mylist.LL_display();
    }
    cin>>p;
    int temp = mylist.LL_get(p);
    if(temp != -1)
        cout<<temp<<endl;
    cin>>p;
    temp = mylist.LL_get(p);
    if(temp != -1)
        cout<<temp<<endl;
    return 0;
}
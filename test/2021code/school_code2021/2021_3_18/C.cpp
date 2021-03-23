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
    void add(ListNode *pa){
        ListNode *p = LL_index(len);
        p->next = pa;
        len++;
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
    int swap(int pa, int pb){
        if( pa <= 0 || pa > len || pa <= 0 || pb >len ){
            cout<<"error"<<endl;
            return 0;
        }
        else{
            ListNode *pre_a = LL_index(pa-1);
            ListNode *pre_b = LL_index(pb-1);
            ListNode *now_a = LL_index(pa);
            ListNode *now_b = LL_index(pb);
            ListNode *temp = now_b->next;
            pre_a->next = now_b;
            pre_b->next = now_a;
            now_b->next = now_a->next;
            now_a->next = temp;
            return 1;
        }
    }
};


LinkList ans;
int n, m;
int LL_merge(ListNode *La, ListNode *Lb){
    int flag = 0;
    while(1){
        if( La -> data < Lb ->data){
            if(La -> next == NULL){
                ans.add(La);
                La = La->next;
                flag = 2;
                break;
            }
            ans.add(La);
            La = La->next;
        }
        else{
            if(Lb -> next == NULL){
                ans.add(Lb);
                Lb = Lb->next;
                flag = 1;
                break;
            }
            ans.add(Lb);
            Lb = Lb->next;
        }
    }
    while(1){
        if(flag == 2){
            if(Lb -> next == NULL){
                ans.add(Lb);
                break;
            }
            ans.add(Lb);
            Lb = Lb->next;
        }
        if(flag == 1){
            if(La -> next == NULL){
                ans.add(La);
                break;
            }
            ans.add(La);
            La = La->next;
        }
    }
    return 0;
}
int main()
{
    LinkList A;
    LinkList B;
    cin>>n;
    for(int i=1; i<=n; i++){
        int item;
        cin>>item;
        A.LL_insert(i, item);
    }
    //A.LL_display();
    cin>>m;
    for(int i=1; i<=m; i++){
        int item;
        cin>>item;
        B.LL_insert(i, item);
    }
    //B.LL_display();
    LL_merge(A.LL_index(1), B.LL_index(1));
    ans.LL_display();
    return 0;
}
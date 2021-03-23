#include<iostream>
#include<string>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    string student_name;
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
    int LL_insert(int i, int item, string str){
        if(i > len+1 || i <= 0){
            cout<<"error"<<endl;
            return 0;
        }
        ListNode *pre = LL_index(i-1);
        ListNode *now = new ListNode();
        now->data = item;
        now->student_name = str;
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
    int LL_findname_del(string str){
        ListNode *p;
        ListNode *pre = head;
        p = head->next;
        while(p){
            if(p->student_name == "str"){
                break;
            }
            pre = pre->next;
            p = p->next;
        }
        pre->next = p->next;
        len--;
        return 1;
    }
    int LL_findnumber_del(int number){
        ListNode *p;
        ListNode *pre = head;
        p = head->next;
        while(p){
            if(p->data == number){
                break;
            }
            pre = pre->next;
            p = p->next;
        }
        pre->next = p->next;
        len--;
        return 1;
    }
    int LL_display_used(){
        ListNode *p;
        p = head->next;
        cout<< p->student_name<<"("<< p->data << ")";
        p = p->next;
        while(p){
            cout<< "-"<< p->student_name <<"("<< p->data << ")";
            p = p->next;
        }
        cout<<endl;
        return 0;
    }
    int LL_display_free(){
        ListNode *p;
        p = head->next;
        cout << p->data ;
        p = p->next;
        while(p){
            cout << "-" << p->data;
            p = p->next;
        }
        cout<<endl;
        return 0;
    } 
    int final_insert(int data, string na){
        LL_insert(len+1, data, na);
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
    int mysort(){
        for(int i=1; i<=len; i++){
            for(int j=i+1; j<=len; j++){
                ListNode *p1 = LL_index(i);
                ListNode *p2 = LL_index(j);
                if(p1->data > p2->data){
                    swap(i, j);
                }  
            }
        }
    }
};
int main()
{
    int n;
    cin>>n;
    LinkList free_room;
    LinkList used_room;
    for(int i=1; i<=20; i++){
        free_room.LL_insert(i, 100+i, "0");
    }
    for(int i=1; i<=n; i++){
        int number;
        string str;
        cin>>str>>number;
        used_room.LL_insert(i, number, str);
        free_room.LL_findnumber_del(number);
    }
    int m;
    cin>>m;
    while(m--){
        string str1, name;
        int nn;
        cin>>str1;
        if(str1 == "assign"){
            cin>>name;
            int number = free_room.LL_get(1);
            free_room.LL_del(1);
            used_room.final_insert(number, name);
        }
        else if(str1 == "return"){
            cin>>nn;
            used_room.LL_findnumber_del(nn);
            free_room.final_insert(nn, "0");
        }
        else if(str1 == "display_used"){
            used_room.mysort();
            used_room.LL_display_used();
        }
        else if(str1 == "display_free"){
            free_room.LL_display_free();
        }
    }
    return 0;
}
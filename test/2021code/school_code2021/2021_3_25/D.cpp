#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node *pre;
    Node()
    {
        next = NULL;
        pre = NULL;
    }
};

class LinkList
{
public:
    int len;
    Node *head = new Node();
    LinkList()
    {
        head->data = 0;
        len = 0;
    }
    Node *turn_to(int n)
    {
        Node *p = head;
        while (n--)
        {
            p = p->next;
        }
        return p;
    }
    void insert(char d)
    {
        Node *p = turn_to(len);
        Node *x = new Node();
        x->data = d;
        x->pre = p;
        p->next = x;
        len++;
    }
    void player_action(int n, char d)
    {
        Node *p = turn_to(n);
        Node *x = new Node();
        x->data = d;
        x->next = p->next;
        x->pre = p;
        if(p->next != NULL)
            p->next->pre = x;
        p->next = x;
        len++;
    }
    void super_del(Node *p, int l)
    {
        while (l--)
        {
            if( p->next != NULL){
                p->next->pre = p->pre;    
            }
            p->pre->next = p->next;
            p = p->next;
            len--;
        }
    }

    int check()
    {
        Node *p = head->next;
        int check_flag = 0;
        int can_del = 0;
        Node *del_start = NULL;
        Node *del_end = NULL;
        char check_yanse;
        int del_time = 0;
        int l = 0;
        while (p)
        {
            if (del_time == 1)
            {
                if (p->data == check_yanse)
                {
                    l++;
                }
                else{
                    break;
                }
                // else{
                //     del_end = p->pre;
                //     del_time = 0;
                //     super_del(del_start, l);
                //     return 1;
                // }
            }
            if (p->next != NULL)
            {
                if (p->data == p->pre->data && p->data == p->next->data && del_time == 0)
                {
                    del_time = 1;
                    check_yanse = p->data;
                    del_start = p->pre;
                    l = 2;
                }
            }
            p = p->next;
        }
        if (l >= 3)
        {
            del_time = 0;
            super_del(del_start, l);
            return 1;
        }
        return 0;
    }
    void print()
    {
        if (len == 0)
        {
            cout << "-" <<endl;
        }
        else
        {
            Node *p = head->next;
            while (p)
            {
                cout << p->data;
                p = p->next;
            }
            cout << endl;
        }
    }
    ~LinkList()
    {
        delete head;
    }
};
int main()
{
    int n;
    cin >> n;
    char str[100];
    cin >> str;
    LinkList mylist;
    for (int i = 0; i < strlen(str); i++)
    {
        mylist.insert(str[i]);
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        char s;
        cin >> num >> s;
        mylist.player_action(num, s);
        while (mylist.check());
        mylist.print();
    }
}

// 13
// AABBCCBCCABCA
// 100
// 4 C
// AABBABCA
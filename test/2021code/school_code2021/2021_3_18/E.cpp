#include <iostream>
#include <cstdio>
using namespace std;

class ListNode
{
public:
    int data;
    int z;
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
    LinkList()
    {
        head = new ListNode();
        len = 0;
    }
    ~LinkList()
    {
        ListNode *p, *q;
        p = head;
        while (p != NULL)
        {
            q = p;
            p = p->next;
            delete q;
        }
        len = 0;
        head = NULL;
    }
    ListNode *LL_index(int i)
    {
        if (i > len || i < 0)
        {
            return NULL;
        }
        else
        {
            ListNode *p = head;
            int l = i;
            while (l--)
            {
                p = p->next;
            }
            return p;
        }
    }
    int LL_getz(int i)
    {
        if (i > len || i <= 0)
        {
            cout << "error" << endl;
            return -1;
        }
        ListNode *p = LL_index(i);
        return p->z;
    }
    int LL_getdata(int i)
    {
        if (i > len || i <= 0)
        {
            cout << "error" << endl;
            return -1;
        }
        ListNode *p = LL_index(i);
        return p->data;
    }
    int LL_insert(int i, int item, int zz)
    {
        if (i > len + 1 || i <= 0)
        {
            cout << "error" << endl;
            return 0;
        }
        ListNode *pre = LL_index(i - 1);
        ListNode *now = new ListNode();
        now->data = item;
        now->z = zz;
        now->next = pre->next;
        pre->next = now;
        len++;
        return 1;
    }
    int LL_del(int i)
    {
        if (i <= 0 || i > len)
        {
            cout << "error" << endl;
            return 0;
        }
        ListNode *goal = LL_index(i);
        ListNode *pre = LL_index(i - 1);
        pre->next = goal->next;
        len--;
        return 1;
    }
    void print_number(int n)
    {
        if (n < 0)
        {
            printf("(%d)", n);
        }
        else
        {
            printf("%d", n);
        }
    }
    void print_z(int z)
    {
        if (z == 0)
        {
        }
        else
        {
            printf("x^");
            print_number(z);
        }
    }
    bool need_print(ListNode *p)
    {
        if (p == NULL)
        {
            return 0;
        }
        if (p->data == 0)
        {
            return 0;
        }
        return 1;
    }
    int LL_display()
    {
        ListNode *p;
        p = head->next;
        int flag = 1;
        while (p)
        {
            if (flag == 1)
            {
                if (need_print(p))
                {
                    print_number(p->data);
                    print_z(p->z);
                    if (need_print(p->next))
                    {
                        printf(" + ");
                    }
                    flag = 0;
                }
                p = p->next;
            }
            else
            {
                if (need_print(p))
                {
                    print_number(p->data);
                    print_z(p->z);
                }
                if (need_print(p->next) && flag == 0)
                {
                    printf(" + ");
                }
                p = p->next;
            }
        }
        cout << endl;
        return 0;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c_count = 1;
        LinkList a;
        LinkList b;
        LinkList c;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int item;
            int zz;
            cin >> item;
            cin >> zz;
            a.LL_insert(i, item, zz);
        }
        a.LL_display();
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            int item;
            int zz;
            cin >> item;
            cin >> zz;
            b.LL_insert(i, item, zz);
        }
        b.LL_display();
        while (a.head->next != NULL && b.head->next != NULL)
        {
            if (a.LL_getz(1) == b.LL_getz(1))
            {
                c.LL_insert(c_count, a.LL_getdata(1) + b.LL_getdata(1), a.LL_getz(1));
                c_count++;
                a.LL_del(1);
                b.LL_del(1);
            }
            else if (a.LL_getz(1) < b.LL_getz(1))
            {
                c.LL_insert(c_count, a.LL_getdata(1), a.LL_getz(1));
                a.LL_del(1);
                c_count++;
            }
            else if (a.LL_getz(1) > b.LL_getz(1))
            {
                c.LL_insert(c_count, b.LL_getdata(1), b.LL_getz(1));
                b.LL_del(1);
                c_count++;
            }
        }
        while (1)
        {
            if (a.head->next == NULL && b.head->next == NULL)
                break;
            else if (a.head->next != NULL)
            {
                c.LL_insert(c_count, a.LL_getdata(1), a.LL_getz(1));
                a.LL_del(1);
                c_count++;
            }
            else if (b.head->next != NULL)
            {
                c.LL_insert(c_count, b.LL_getdata(1), b.LL_getz(1));
                b.LL_del(1);
                c_count++;
            }
        }
        c.LL_display();
    }
    return 0;
}
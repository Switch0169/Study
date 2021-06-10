#include <iostream>
#include <cstring>
using namespace std;
/*
    Mark：为什么最多只搜m次
*/
int Table[100000];
bool visited[100000];
int m, n;
int flag;
int xcount;

int getRealKey(int num)
{
    num = (num + m * 1000000) % m;
    return num;
}
int Hash(int key)
{
    int val;
    if (key >= 0)
    {
        val = key % 11;
    }
    else
    {
        while (key < 0)
        {
            key += 11;
        }
        val = key;
    }
    return val;
}
void init()
{
    memset(visited, 0, sizeof(visited));
}
void insert(int key, int val)
{
    if (visited[key] == 0)
    {
        visited[key] = 1;
        Table[key] = val;
    }
    else
    {
        int i = 1;
        int next;
        while (1)
        {
            next = getRealKey(key + i * i);
            if (visited[next] == 0)
            {
                visited[next] = 1;
                Table[next] = val;
                break;
            }
            next = getRealKey(key - i * i);
            if (visited[next] == 0)
            {
                visited[next] = 1;
                Table[next] = val;
                break;
            }
            i++;
        }
    }
}
void Search(int key, int val, int &pos)
{
    xcount++;
    if (Table[key] == val && visited[key] == 1)
    {
        flag = 1;
        pos = key;
    }
    else if (visited[key] == 0)
    {
        flag = 0;
    }
    else
    {
        int i = 1;
        int next;
        while (1)
        {
            next = getRealKey(key + i * i);
            xcount++;
            if (xcount >= m)
            {
                break;
            }
            if (visited[next] == 0)
            {
                flag = 0;
                break;
            }
            else if (visited[next] == 1 && Table[next] == val)
            {
                flag = 1;
                pos = next;
                break;
            }
            xcount++;
            if (xcount >= m)
            {
                break;
            }
            next = getRealKey(key - i * i);
            if (visited[next] == 0)
            {
                flag = 0;
                break;
            }
            else if (visited[next] == 1 && Table[next] == val)
            {
                flag = 1;
                pos = next;
                break;
            }
            i++;
        }
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("myout.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        init();
        cin >> m >> n;
        for (int i = 1; i <= n; i++)
        {
            int val;
            cin >> val;
            int key;
            key = Hash(val);
            insert(key, val);
        }
        for (int i = 0; i < m; i++)
        {
            if (visited[i] == 1)
                cout << Table[i] << " ";
            else
                cout << "NULL"
                     << " ";
        }
        cout << endl;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int val;
            cin >> val;
            int key;
            int pos;
            key = Hash(val);
            flag = 0;
            xcount = 0;
            Search(key, val, pos);
            if (flag)
            {
                cout << flag << " " << xcount << " " << pos + 1 << endl;
            }
            else
            {
                cout << flag << " " << xcount << endl;
            }
        }
    }
    return 0;
}
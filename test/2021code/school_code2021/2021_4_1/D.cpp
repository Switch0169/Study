#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Point
{
public:
    int xp;
    int yp;
    Point(int x, int y)
    {
        xp = x;
        yp = y;
    }
    void setPoint(int x, int y)
    {
        xp = x;
        yp = y;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int visited[100][100];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> visited[i][j];
            }
        }
        stack<Point> path;
        Point a(0, 0);
        if(visited[0][0] == 0)
            path.push(a);
        visited[0][0] = 1;
        while (!path.empty())
        {
            if (path.top().xp == n - 1 && path.top().yp == n - 1)
            {
                break;
            }
            else
            {
                int tmpx = path.top().xp;
                int tmpy = path.top().yp;
                if (visited[tmpx][tmpy + 1] == 0 && tmpy + 1 < n)
                { //you
                    visited[tmpx][tmpy + 1] = 1;
                    Point tmp(tmpx, tmpy + 1);
                    path.push(tmp);
                }
                else if (visited[tmpx + 1][tmpy] == 0 && tmpx + 1 < n)
                { //xia
                    visited[tmpx + 1][tmpy] = 1;
                    Point tmp(tmpx + 1, tmpy);
                    path.push(tmp);
                }
                else if (visited[tmpx - 1][tmpy] == 0 && tmpx - 1 >= 0)
                { //shang
                    visited[tmpx - 1][tmpy] = 1;
                    Point tmp(tmpx - 1, tmpy);
                    path.push(tmp);
                }
                else if (visited[tmpx][tmpy - 1] == 0 && tmpy - 1 >= 0)
                { //zuo
                    visited[tmpx][tmpy - 1] = 1;
                    Point tmp(tmpx, tmpy - 1);
                    path.push(tmp);
                }
                else
                {
                    path.pop();
                }
            }
        }
        stack<Point> path1;
        if (!path.empty()) //找到路径
        {
            while(!path.empty()){
                path1.push(path.top());
                path.pop();
            }
            int i = 0; 
            while (!path1.empty())
            {
                Point cpos = path1.top();
                if ((++i) % 4 == 0)
                    cout << '[' << cpos.xp << ',' << cpos.yp << ']' << "--" << endl;
                else
                    cout << '[' << cpos.xp << ',' << cpos.yp << ']' << "--";
                path1.pop();
            }
            cout << "END" << endl;
        }
        else
            cout << "no path" << endl; //找不到路径输出no path
    }
    return 0;
}
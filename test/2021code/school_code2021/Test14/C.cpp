#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, K;
bool vis[30001];
class Node{
public:
    int last;
    int action_No; 
    int step;
    Node(int l, int a, int s){
        last = l;
        action_No = a;
        step = s;
    }
};

queue<Node> q;

void init(){
    while(!q.empty()){
        q.pop();
    }
    memset(vis, 0, sizeof(vis));
}
int action(int No, int x){
    if(No == 1)
        return (x - 1);
    else if(No == 2)
        return (x + 1);
    else if(No == 3)
        return (2 * x);
    return 0;
}

int Bfs(){
    int now = N;
    int step = 0;
    int last = N;
    vis[now] = 1;
    q.push(Node(now, 1, 1));
    q.push(Node(now, 2, 1));
    q.push(Node(now, 3, 1));
    Node front(0, 0, 0);
    while(!q.empty()){
        if(now == K){
            return front.step;
        }
        front = q.front();
        q.pop();
        now = action(front.action_No, front.last);
        if(now < 30000 && vis[now] == 0){
            q.push(Node(now, 1, front.step + 1));
            q.push(Node(now, 2, front.step + 1));
            q.push(Node(now, 3, front.step + 1));
        }
        if(now < 30000)
            vis[now] = 1;
    }
    return 0;
}

int main()
{
    while(cin >> N >> K){
        init();
        int step = Bfs();
        cout << step << endl;
    }
    return 0;
}
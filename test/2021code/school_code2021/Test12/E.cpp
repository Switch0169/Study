#include<cstdio>
#include<iostream>
using namespace std;

const int maxn = 1e5 + 10;
struct Node
{
    int key;        // 关键值
    int left;       // 左子树地址（数组下标）
    int right;      // 右子树地址（数组下标）
    int height;     // 当前结点为根的子树高度
    int num;        // 当前节点的子节点个数
    void Init(){
        num = key = left = right = -1;
        height = 0;
    }
    void Init(int k_){Init(); key = k_;}
    Node(){Init();}
    Node(int k_, int d_=0){Init(k_);}
};

Node tr[maxn];
int root, tp;  // root标记根节点位置，tp全局结点分配下标

inline int UpdateNum(int now)
{
    int left = tr[now].left;
    int right = tr[now].right;
    int lefth, righth;
    left == -1 ? lefth = 0 : lefth = tr[left].num + 1;
    right == -1 ? righth = 0 : righth = tr[right].num + 1;
    tr[now].num = lefth + righth;
    return tr[now].num;
} 
inline int UpdateHeight(int now)
{
    // 更新 tr[now] 结点的子树高度，即tr[now].height的值
    UpdateNum(now);
    int left = tr[now].left;
    int right = tr[now].right;
    tr[now].height = max(tr[left].height, tr[right].height) + 1;
    return tr[now].height;
}
inline int HeightDiff(int now)
{
    // 计算 tr[now] 结点的平衡因子
    int left = tr[now].left;
    int right = tr[now].right;
    return tr[left].height - tr[right].height;
}
int LL(int an)
{
    int left = tr[an].left;
    tr[an].left = tr[left].right;
    tr[left].right = an;
    UpdateHeight(an);
    UpdateHeight(left);
    return left;
}
int RR(int an)
{
    int right = tr[an].right;
    tr[an].right = tr[right].left;
    tr[right].left = an;
    UpdateHeight(an);
    UpdateHeight(right);
    return right;
}
int LR(int an)
{
    int left = tr[an].left;
    tr[an].left = RR(left);
    return LL(an);
}
int RL(int an)
{
    int right = tr[an].right;
    tr[an].right = LL(right);
    return RR(an);
}
void Insert(int &now, int key, int data=0)
{
    if(now == -1)
    {
        // 传入指针为空，新建结点保存数据
        now = ++ tp;
        tr[now].Init(key);
    }
    // 判断插入哪个子树，插入数据，判断平衡因子，做正确旋转，更新高度
    else if(key < tr[now].key){
        Insert(tr[now].left, key);
        if(HeightDiff(now) >= 2 || HeightDiff(now) <= -2){
            if(key < tr[tr[now].left].key){
                now = LL(now);
            }
            else{
                now = LR(now);
            }
        }
    }
    else if(key > tr[now].key){
        Insert(tr[now].right, key, data);
        if(HeightDiff(now) >= 2 || HeightDiff(now) <= -2){
            if(key > tr[tr[now].right].key){
                now = RR(now);
            }
            else{
                now = RL(now);
            }
        }
    }
    UpdateHeight(now);
}
int flag = 0;
void Delete(int &now, int key)
{
    if(now == -1) return;
    else if(key < tr[now].key) Delete(tr[now].left, key);
    else if(key > tr[now].key) Delete(tr[now].right, key);
    else
    {
        // 删除当前结点
        if(tr[now].left == -1 && tr[now].right == -1){
            now = -1;
        }
        else if(tr[now].left == -1 || tr[now].right == -1){
            if(tr[now].left == -1){
                now = tr[now].right;
            }
            else{
                now = tr[now].left;
            }
        }
        else{
            int pre = tr[now].left;
            while(tr[pre].right != -1){
                pre = tr[pre].right;
            }
            tr[now].key = tr[pre].key;
            Delete(tr[now].left, tr[pre].key);
        }
    }
    // 处理树平衡
    if(now == -1) return;
    UpdateHeight(now);
    if(HeightDiff(now) >= 2){
        if(HeightDiff(tr[now].left) >= 0){
            now = LL(now);
        }
        else{
            now = LR(now);
        }
    }
    else if(HeightDiff(now) <= -2){
        if(HeightDiff(tr[now].right) <= 0){
            now = RR(now);
        }
        else{
            now = RL(now);
        }
    }
}
void Search(int now, int &k, int &del){
    int left = tr[now].left;
    int right = tr[now].right;
    int lefth = left == -1 ? -1 : tr[left].num;
    int righth = right == -1 ? -1 : tr[right].num; 
    if(now == -1) return;
    else if(k <= lefth + 1) {
        Search(tr[now].left, k, del);
    }
    else if(k == lefth + 2){
        flag = 1;
        cout << tr[now].key << endl;
        del = tr[now].key;
        return ;
    }
    else if(k > lefth + 2){
        k = k - (lefth + 2); 
        Search(tr[now].right, k, del);
    }
}
int main()
{
    // freopen("in1.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, op, key, data;
    while(scanf("%d", &n) != EOF)
    {
        for(root = tp = -1; n --; )  // 初始化根结点和“内存指针”
        {
            scanf("%d", &op);
            if(op == 1)
            {
                cin >> key;
                Insert(root, key);
            }
            else if(op == 2)
            {
                int k;
                int del;
                cin >> k;
                flag = 0;
                Search(root, k, del);
                if(flag){
                    Delete(root, del);
                }
                else{
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}
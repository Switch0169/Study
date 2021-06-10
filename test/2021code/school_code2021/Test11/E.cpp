#include<cstdio>
#include<iostream>
using namespace std;

const int maxn = 1e5 + 10;
struct Node
{
    int key;        // 关键值
    int data;       // 携带的数据
    int left;       // 左子树地址（数组下标）
    int right;      // 右子树地址（数组下标）
    int height;     // 当前结点为根的子树高度
    void Init(){
        data = key = left = right = -1;
        height = 0;
    }
    void Init(int k_, int d_=0){Init(); key = k_; data = d_;}
    Node(){Init();}
    Node(int k_, int d_=0){Init(k_, d_);}
};
 
Node tr[maxn];
int root, tp;  // root标记根节点位置，tp全局结点分配下标
 
inline int UpdateHeight(int now)
{
    // 更新 tr[now] 结点的子树高度，即tr[now].height的值
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
        tr[now].Init(key, data);
    }
    // 判断插入哪个子树，插入数据，判断平衡因子，做正确旋转，更新高度
    else if(key < tr[now].key){
        Insert(tr[now].left, key, data);
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
            tr[now].data = tr[pre].data;
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
void Search(int now, int key){
    if(now == -1) return;
    else if(key < tr[now].key) Search(tr[now].left, key);
    else if(key > tr[now].key) Search(tr[now].right, key);
    else
    {
        flag = 1;
        cout << tr[now].data << endl;
        return ;
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
                cin >> data >> key;
                Insert(root, key, data);
            }
            else if(op == 2)
            {
                if(root != -1){
                    int xp = root;
                    while(tr[xp].right != -1){
                        xp = tr[xp].right;
                    }
                    cout << tr[xp].data << endl;
                    Delete(root, tr[xp].key);
                }
                else{
                    cout << "0" << endl;
                }
            }
            else if(op == 3)
            {
                if(root != -1){
                    int xp = root;
                    while(tr[xp].left != -1){
                        xp = tr[xp].left;
                    }
                    cout << tr[xp].data << endl;
                    Delete(root, tr[xp].key);
                }
                else{
                    cout << "0" << endl;
                }
            }
            else
            {
                int K;
                cin >> K;
                flag = 0;
                Search(root, K);
                if(flag == 0){
                    cout << "0" << endl;
                }
                else{
                    Delete(root, K);
                }
            }
        }
    }
    return 0;
}
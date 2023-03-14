#include <bits/stdc++.h>

using namespace std;
int n, m;
int k, a, b;
const int N = 100010;
int w[N];
struct
{
    int l, r;
    int sum;
} tr[4 * N];
void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r) //为线段树 初始化 l , r sum
{
    if (l == r)
        tr[u] = {l, r, w[l]};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
//取出 区间的 和 区间完全含有区域之间返回
//不然 分裂区域
int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].sum;
    int mid = tr[u].l + tr[u].r >> 1;
    //若 区间包含 左边一部分区域
    int sum = 0;
    if (l <= mid)
        sum = query(u << 1, l, r); //找寻完全包含情况
    if (r > mid)
        sum += query(u << 1 | 1, l, r);
    return sum;
}
//修改函数 分裂区域即进入孩子  找到 x位置
//(这里 完全可以 当个 区域二分 1 -- -n 中 查找 x )
//根节点  位置x  增值v
void modify(int u, int x, int v)
{
    if (tr[u].l == tr[u].r)
        tr[u].sum += v; //找到x点
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)   
            modify(u << 1, x, v);
        if(x>mid) 
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
    //放在外面 最后一层被更新了！！！变成0  but 他没有孩子可以更新！
    //pushup(u);
    // while(tr[u].l + 1 != tr[u].r)
    // {
    //     int mid = tr[u].l + tr[u].r>>1;
    //     if(x<=mid) modify(u<<1,x,v);
    //     else{
    //         modify(u<<1|1,x,v);
    //     }
    // }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    build(1, 1, n);
    while (m--)
    {
        scanf("%d%d%d", &k, &a, &b);
        if (k == 0)
        {
            printf("%d\n", query(1, a, b));
        }
        else
        {
            modify(1, a, b);
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int m,x,y;
int n;
const int N = 10E5+10;
int w[N];
struct Node{
    int l,r;
    int max;
}tr[4 * N];
void pushup(int u)
{
    tr[u].max = max(tr[u<<1].max,tr[u<<1|1].max);
}
void build(int u,int l,int r)//初始化 初始线段树节点 l r 信息max
{
    if(l == r) tr[u] = {l,r,w[l]};
    else{
        tr[u]  = {l,r};
        int mid = l + r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);//初始化左右孩子
        pushup(u);//利用 孩子 更新 自身
    }
}
int query(int u,int l,int r)//得到 l  r 区间内的信息
{
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].max;//如果 区域被区间包含
    int mid = tr[u].l + tr[u].r >>1;
    //如果 区间 包含 一部分区域 把这部分区域 信息返回
    //l <= mid 意思是  区间含有左边区域
    int max0 = INT_MIN;
    if(l<=mid) max0 = query(u<<1,l,r);
    if(r>mid) max0 = max(max0,query(u<<1|1,l,r));//区间含有 右边区域 对应右孩子
    //得到左右区域最大值
    return max0;
}
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>w[i];
    

    build(1,1,n);//初始化
    while(m--)
    {
        cin>>x>>y;
        printf("%d\n",query(1,x,y));
    }

    return 0;
}
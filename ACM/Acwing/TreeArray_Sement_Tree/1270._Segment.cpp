#include<bits/stdc++.h>

using namespace std;
const int N = 10e5+10;
struct Node{
    int l,r;
    int max;//信息为最大值
}tree[ 4 * N];
int n,m;
int x,y;
int w[N];//保存数组
void pushup(int u)//求区域最大值
{
    tree[u].max = max(tree[u<<1].max,tree[u<<1|1].max);
}
//分别对 线段树从父亲 到 儿子 的每一部分 更新 l r   信息是儿子回溯 
void build(int u,int l,int r)
{
    if(l == r) tree[u] = {l,r,w[l]};
    else{
        tree[u] = {l,r};
        int mid = l + r>>1;

        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
//query 整合信息 区域最大值
int query(int u,int l,int r)
{
    if(tree[u].l>=l&& tree[u].r<=r) return tree[u].max;//区域只有一个值 返回
    int mid = tree[u].l + tree[u].r>>1;
    int max0 = INT_MIN;
    if(l<=mid) max0 = query(u<<1,l,r);
    if(r>mid) max0 = max(max0,query(u<<1|1,l,r));
    return max0;
    
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++) scanf("%d",&w[i]);
    build(1,1,n); 
    int l, r;
    while (m -- )
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(1, l, r));
    }

    return 0;
}
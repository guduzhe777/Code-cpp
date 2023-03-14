#include <bits/stdc++.h>

using namespace std;
//前缀和 = 区间求和
//修改值 更新值
int a, b, k;
const int N = 100010;
int f[N],tree[N];
int n;
using ll = long long;
int m;//几次
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int v)
{
    for(int i = x;i<=n;i += lowbit(i))
    {
        tree[i] += v;
    }
}
ll query(int x)
{
    ll res = 0;
    for(int i = x;i>0;i -= lowbit(i))
    {
        res += tree[i];
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    scanf("%d",&m);
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &f[i]);
        add(i,f[i]);//更新 节点
    }
    while(m--)
    {
        scanf("%d %d %d",&k,&a,&b);
        if(!k)//求和
        {
            cout<<query(b) - query(a-1)<<endl;
        }else{
            add(a,b);
        }   
    }
    return 0;
}
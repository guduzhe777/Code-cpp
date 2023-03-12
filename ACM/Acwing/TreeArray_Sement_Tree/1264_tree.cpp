#include<bits/stdc++.h>

using namespace std;
//全局变量  静态变量 放在堆 及 静态区
int n,m;
int k,a,b;
const int N = 100010;
int f[N],tree[N];
int lowbit(int x)//末尾几个0  寻找父子节点作用 末尾没0 返回1
{
    return x&-x;
}
//从下标x 开始 向后更新父节点
void add(int x,int v)
{
    for(int i = x;i<=n;i += lowbit(i)) tree[i] += v; //从子到父更新 树状数组
}
int query(int x) //依靠树状数组 从后向前 求 前缀和
{
    int res = 0;
    for(int i = x;i>0;i -= lowbit(i)) res += tree[i];
    return res;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i =1;i<=n;i++)
    {
        scanf("%d",&f[i]);
        add(i,f[i]);
    }
    while(m--)
    {
        scanf("%d%d%d",&k,&a,&b);
        if(!k)
        {
            cout<<query(b) - query(a-1)<<endl;
        }
        else{
            add(a,b);
        }
    }
    return 0;
}
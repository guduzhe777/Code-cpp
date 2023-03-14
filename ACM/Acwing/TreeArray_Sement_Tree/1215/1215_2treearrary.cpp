#include<bits/stdc++.h>
using namespace std;




int n;
const int N = 10e5+10;
int h[N];
int tr[N];//树状数组
int sum[N];//对于i 编号 移动 k1 + k2 次
int lowbit(int x)
{
    return x&-x;
}
int query(int x)//求和
{
    int sum = 0;
    for(int i = x;i>0;i -= lowbit(i))
    {
        sum += tr[i];
    }
    return sum;
}

void add(int x,int v)
{
    for(int i = x;i<N;i += lowbit(i))
    {
        tr[i] += v;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        h[i]++;
    }
    //防止 为0情况
    for(int i = 1;i<=n;i++)
    {
        add(h[i],1);//等于 h[i] 数量加1
        sum[i] += query(N-1) - query(h[i]);//小于等于N - 1数量
        
    }
    memset(tr,0,sizeof(tr));
    for(int i = n;i>0;i--)
    {
        add(h[i],1);//等于 h[i] 数量加一     
        sum[i] += query(h[i]-1);//小于等于 hi 的数量
           
    }
    long long res = 0;
    for(int i = 1;i<=n;i++)
    {
        res += (long long )sum[i] *(sum[i] + 1)/2;
    }
    cout<<res<<endl;
    return 0;
}
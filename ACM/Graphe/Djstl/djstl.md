Djstl

核心：每一次在未在家庭中的点中找到 最短距离 用这个点去接近他的周围点

n-1次  dis wor找最小  标记  接近

dis worth pre 辅助数组：里起点最近的距离  最小的花费  i点的上一个点，这些依靠于权值，所以有几个权来比较 我们设置几个 辅助数组保存。

famliy[]: 在家庭中的点  将n - 1 个点放进去

~~~
不同于之前

1.我们这里用vector<struct> G[x]存储 多权
	G[x] 代表x  他的元素 含有三个值  所以struct

2.求x的邻接点：
	for(aotu &[v,len,wor] :G[u]) 即可
	
3.用dfs输出pre
	pre[u] = -1;//起点标记
~~~

~~~
#include<bits/stdc++.h>

using namespace std;
struct node{
    int v,len,wor;
};
const int N = 510;
vector<node> G[N];
int pre[N];//pre[i] = j  i的上一个点为j
int dis[N];//dis[i] = K  i点到起点的最近距离为K 
bool famliy[N];//判断是否加入家庭
int worth[N];
int n,m,s,d;
void Djstl(int u)
{
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(worth,0x3f3f3f3f,sizeof(worth));
    for(int i = 0;i<n;i++)      //初始化dis worth
    {
        for(auto & [v,len,wor]:G[u])
        {
            dis[v] = len;
            worth[v] = wor;
            pre[v] = u;
        }
    }
    famliy[u] = 1;

    for(int i = 1;i<n;i++)
    {
        int min0 = 0x3f3f3f3f;
        int best;
        for(int j = 0;j<n;j++)
        {
            if(!famliy[j]&&min0>dis[j])
            {
                min0 = dis[j];
                best = j;
            }
        }
        famliy[best] = 1;
        for(auto &[v,len,wor] : G[best])
        {
            if(!famliy[v])
            {
                int newdis = dis[best] + len;
                int newwor = worth[best] + wor;
                if(newdis<dis[v])
                {
                    dis[v] = newdis;
                    worth[v] = newwor;
                    pre[v] = best;
                }else if(newdis == dis[v])
                {
                    if(newwor<worth[v])
                    {
                        worth[v] = newwor;
                        pre[v] = best;
                    }
                }
            }
        }
    }
}
void dfs(int v)
{
    if(v == -1)
    {
        return;
    }
    printf(" %d",v);
    dfs(pre[v]);
}
int main()
{
    cin>>n>>m>>s>>d;
    for(int i = 0;i<m;i++)
    {
        int x,y,len,wor;
        cin>>x>>y>>len>>wor;
        G[x].push_back({y,len,wor});
        G[y].push_back({x,len,wor});
    }
    pre[s] = -1;
    Djstl(s);    
    //dfs(d);
    printf("%d %d\n",dis[d],worth[d]);
    return 0;
}
~~~


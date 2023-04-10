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
    dfs(d);
    printf("\n%d %d",dis[d],worth[d]);
    return 0;
}
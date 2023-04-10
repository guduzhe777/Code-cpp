#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10,INF = 0x3f3f3f3f;
vector<int> st[N];
int dis[N];//dis[i] i点的深度
int n;
//bfs 求深度 即  dis[v] = dis[father] + 1;
int bfs(int u) //bfs 人家只看有边的/只看集合/只看树 图
{
    memset(dis,INF,sizeof(dis));
    queue<int> q;
    q.push(u);
    dis[u] = 1;
    int maxdist = 1;    //只有祖宗自己情况
    while(!q.empty())
    {
        int father = q.front();
        q.pop();
        for(auto v:st[father])
        {
            if(dis[v] == INF)
            {
                dis[v] = dis[father] + 1;
                q.push(v);
                if(dis[v]>maxdist)
                {
                    maxdist = dis[v];
                }
            }
        }
    }
    return maxdist;
}
int maxdis = 1;
vector<int> pson;
void dfs(int u,int deep)
{
    if(!st[u].size())
    {
        if(deep>maxdis)
       {
            maxdis = deep;
            pson.clear();
            pson.push_back(u);
       }else if(deep == maxdis)
       {
            pson.push_back(u);
       }
    }

    for(auto v:st[u])
    {
        dfs(v,deep+1);
    }
}
int main()
{
    int t;//祖宗
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x != -1)
        {
            st[x].push_back(i);
        }else {
            t = i;
        }
    }
    //bfs
    //int ret = bfs(t);//从祖宗开始
    //printf("%d\n",ret);
    // bool si = true;//第一个
    // for(int i = 1;i<=n;i++)
    // {
    //     if(dis[i] == ret)
    //     {
    //         if(si)
    //         {
    //             printf("%d",i);
    //             si = false;
    //         } 
    //         else{
    //             printf(" %d",i);
    //         }
    //     }
    // }
   
   //dfs
    dfs(t,1);
    printf("%d\n",maxdis);
    bool ok  = 1;
    for(auto v:pson)
    {
        if(ok)
        {
            ok = 0;
            printf("%d",v);
        }else{
            printf(" %d",v);
        }
    }
    return 0;
}
//考的BFS
//特性：bfs会 首先访问 层数小 距离 某个点实际最短距离的点
//用层数向上的点
//所以图也可以有层概念：起点 连接方式 来决定层
//起点到某个点的距离 实际上看 在第几层！


#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;
const int INF = 0x3f3f3f3f;
vector<int> G[N];

int dis[N];//某个点到其他的最远距离


int n,m,k;
int bfs(int u)
{
    memset(dis,INF,sizeof(dis));
    //默认不知道层数 即距离
    dis[u] = 0;
    int maxdist = 0,id = 0;//距离u点 最深的层数
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int nu = q.front();
        q.pop();
        for(auto v:G[nu])
        {
            
            if(dis[v] == INF)   ///这里的 探索和处理放一起了 未探索  aotu v:G[u] 自动是有边 只探索 未处理即可
            {
                dis[v] = dis[nu] + 1;
                q.push(v);//未处理 放入队列
                if(maxdist<dis[v])
                {
                    maxdist = dis[v];
                    id = v;
                }else if(maxdist == dis[v])
                {
                    id = min(id,v);//若二者层数相同 选取编号低的
                }
            }
        }

    }
    return id;
}
int main()
{
    cin>>n>>m>>k;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    while(k--)
    {
        int t;//查询
        cin>>t;
        int id = bfs(t);
        cout<<id<<"\n";
    }
    return 0;
}

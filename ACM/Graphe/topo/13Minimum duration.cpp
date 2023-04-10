////该点要完成 则 其他所有点都需要完成 
//则该点完成最短时间为 所有其他的入点全部完成才行 
//根本不在意顺序，只要保证 这个时间让其他入点都完成即可

#include<bits/stdc++.h>

using namespace std;
//简单的拓扑判断 即 dfs 看是否有环-----在遍历 正在进行遍历的点 
//到了bfs中 是 以最后的入度为0点的个数 
const int N= 110;

typedef pair<int,int> PII;
vector<PII> G[N];
int n,m;
vector<int> zerodu;
int rdu[N];
int dis[N];//dis[i] i点完成的最短时间 根本不在意顺序 只要保证 这个时间让其他入点都完成即可
bool toposort()//bfs 拓扑入度
{
    queue<int> q;
    for(int i = 0;i<n;i++)
        if(!rdu[i]) q.push(i);

    while(!q.empty())
    {
        int father = q.front();
        q.pop();
        zerodu.push_back(father);
        for(auto & [v,w] : G[father])
        {
            rdu[v]--;
            if(!rdu[v]) q.push(v);
            dis[v] = max(dis[v],dis[father]+w);
        }
    } 
    return zerodu.size() == n;//全部0度
}
int main()
{

    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        G[x].push_back({y,w});
        rdu[y]++;
    }
    if(toposort())
    {
        int max0 = 0;
        for(int i = 0;i<n;i++) max0 = max(max0,dis[i]);
        printf("%d\n",max0);
    }else{
        printf("Impossible\n");
    }

    return 0;
}
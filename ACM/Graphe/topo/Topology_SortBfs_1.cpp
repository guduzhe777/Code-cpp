#include<bits/stdc++.h>


using namespace std;


int dis[110];
int du[110];
int n,m;

typedef pair<int,int> PII;
vector<PII> G[110];
bool topo()
{
    queue<int> q;
    queue<int> zerodu;
    for(int i = 0;i<n;i++)
    {
        if(!du[i])
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        zerodu.push(u);
        for(auto &[v,w] :G[u])
        {
            du[v]--;
            if(!du[v])
            {
                q.push(v);
            }
            dis[v] = max(dis[v],w+dis[u]);
        }

    }
    return zerodu.size() == n;
}
int main()
{
    cin>>n>>m;

    for(int i = 0;i<m;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        G[u].push_back({v,cost});
        du[v]++;
    }
    if(topo())
    {
        int max_dis = 0;
        for(int i = 0;i<n;i++)
        {
            max_dis = max(max_dis,dis[i]);
        }
        printf("%d\n",max_dis);
    }else{
        printf("Impossible\n");
    }
    return 0;
}
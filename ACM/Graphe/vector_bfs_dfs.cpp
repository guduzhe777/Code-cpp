#include <bits/stdc++.h>

using namespace std;
const int N = 11;
vector<int> G[N];

bool dis[N]; //是否被探索
int n, m;
void dfs(int x)
{
    if (dis[x])
        return;
    dis[x] = true;
    printf(" %d", x);
    // for (int i = 0; i < G[x].size(); i++)
    // {
    //     if (!dis[G[x][i]])
    //     {
    //         dfs(G[x][i]);
    //     }
    // }
    for(auto v:G[x]) //直接访问 vector中值
    {
        if(!dis[v])
        {
            dfs(v);
        }
    }
}
void bfs(int x)
{
    //bfs
    queue<int> qu;
    dis[x] = true;//探索 即push
    qu.push(x);
    
    while(!qu.empty())
    {
        int nu = qu.front();
        
        qu.pop();
        printf(" %d",nu);
        for(int v:G[nu])
        {
            if(!dis[v])
            {
                dis[v] = true;
                qu.push(v);
                
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        sort(G[i].begin(), G[i].end());///以顺序遍历所有点
    }
    for (int i = 0; i < n; i++)
    {
        if (!dis[i])
        {
            printf("{");
            dfs(i);
            printf(" }\n");
        }
    }
    memset(dis,false,sizeof dis);
    for (int i = 0; i < n; i++)
    {
        if (!dis[i])
        {
            printf("{");
            bfs(i);
            printf(" }\n");
        }
    }
    return 0;
}
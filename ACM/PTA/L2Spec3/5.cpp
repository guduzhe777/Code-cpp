#include<bits/stdc++.h>


using namespace std;

int id,maxdeep;//节点 深度 与 编号

int n;
int k;
const int N = 1e5+10;
vector<int> G[N];
bool si[N];

int deep[N];
void dfs(int u)
{
    for(int v : G[u])
    {
        deep[v] = deep[u] + 1;
        // maxdeep = max(deep[v],maxdeep);
        if(deep[v]>maxdeep)
        {
            id = v,maxdeep = deep[v];
        }
        dfs(v);
    }
}
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>k;
        while(k--)
        {
            int y;
            cin>>y;
            G[i].push_back(y);
            si[y] = true;
        }
    }
    int u;
    for(int i = 1;i<=n;i++)
    {
        if(!si[i])
        {
            u = i;
        }
    }
    deep[u] = 1;
    dfs(u);
    // for(int i = 1;i<=n;i++)
    // {
    //     if(maxdeep == deep[i])
    //     {
    //         id = i;
    //     }
    // }
    printf("%d\n",id);
    return 0;
}
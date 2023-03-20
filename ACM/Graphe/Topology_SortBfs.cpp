#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100, INF = 0x3f3f3f3f;
int V, E;
vector<int> adjs[MAX_V];

vector<int> ans;
queue<int> q;
int indeg[MAX_V];

void tsort()
{
    fill(indeg, indeg + V, 0);
    for (int u = 0; u < V; u++)
        for (int v : adjs[u])
            indeg[v]++;
    for (int u = 0; u < V; u++)
        if (indeg[u] == 0)
            q.push(u);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : adjs[u])
            if (--indeg[v] == 0)
                q.push(v);
    }
}
int main()
{
    cin >> V >> E; //点 边数量
    for (int i = 0, u, v; i < E; i++) //输入边
    {
        cin >> u >> v;
        adjs[u].push_back(v);
    }
    tsort();
    for (int i : ans)
        cout << i << endl;
    return 0;
}
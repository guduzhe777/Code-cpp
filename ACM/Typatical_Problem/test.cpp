#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << (char[2][2]){" ", "\n"}[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int n, m;
vvi G;
vi dp;
vi p;

int dfs(int v)//求到某点的最短距离
{
    if (dp[v] != INF) //未被开发过   开发过之间返回到这个点的最短距离即可 
        return dp[v];
    for (int u = 0; u < n; u++)
        if (G[u][v])
            if (dp[v] > dfs(u) + G[u][v])
            {
                dp[v] = dfs(u) + G[u][v];
                p[v] = u;
            }
    return dp[v];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    G = vvi(n, vi(n));
    dp = vi(n, INF);
    p = vi(n);
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        G[u][v] = w;
    }
    int bg, ed;
    cin >> bg >> ed;
    dp[bg] = 0;
    p[bg] = -1;

    cout << dfs(ed) << endl;
    for (int i = ed; i != -1; i = p[i])
        cout << i << (char[2][5]){" -> ", "\n"}[i == bg];
    return 0;
}
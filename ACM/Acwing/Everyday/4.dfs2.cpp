// 用 拿出来当作 已经处理过点比较好，不容易忽略 起始点

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;

bool si[N]; // si[i] = 1 i点已经被标记  //

int engry[N]; // 某个点电容

int t;

int maxCnt;

vector<int> g[N];

int dp[N]; // dp[i] = j i 周围 j个点小于i
// 有 资格才能继续下去/才能 进栈，在 出来的时候 当作已经处理，容易计算起始点

// cnt dfs求周围最大数量

int dfs(int u0)
{
    if(dp[u0]) return dp[u0]; 
    int cnt  = 1;
    for(auto &v:g[u0])
    {
        if(engry[v]<engry[u0])
        {
            cnt += dfs(v);

        }
    }
    return dp[u0] = cnt;//求出某个点最大点亮数
}

int main()
{
    

    scanf("%d", &t);

    int tem = t;
    while (tem--)
    {
        
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {

            scanf("%d", &engry[i]);
            g[i].clear(); //对用到的点初始化.
        }

        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        for (int i = 1; i <= n; i++)
        {
            
            //memset(si, 0, sizeof(si));
            maxCnt = max(maxCnt, dfs(i));
            
        }
        
        printf("Case #%d: %d\n", t - tem, maxCnt);
        maxCnt = 0; //每一个图.
        memset(dp, 0, sizeof(dp));// 每一个图的 点周围最大点亮数
    }

    return 0;
}
// dfs

#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int f[N];
int n;
int dp[N];//存储某个的最大上升子序列
//寻找以x开始最长上升子序列长度

int dfs(int x)//求以x开始的最大上升子序列 
{

    // for (int j = 1; x + j <= n; j++)
    // {
    //     if (f[x + j] > f[x])
    //     {
    //         ans0 = dfs(x + 1) + 1;
    //     }
    // }
    int ans0 = 1;//存储 暂时的 以x 为开始最大上升子序列
    if(dp[x]>0)
    {
        return dp[x];
    }
    if(x == n) return 1;
    //以x为开始的最长... 以最后一个  当然是 1

    for(int j = x + 1;j<=n;j++)//计算出以x开头的最长子序列长度
    {
        if(f[j]>f[x]) ans0 = max(ans0,dfs(j) + 1);
    }

    return dp[x] = ans0;  //凡是求出来的最长子序列长度都记录下来 如果用到直接返回

}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &f[i]);
    }
    int ans = 0;
    int res;
    for (int i = 1; i <= n; i++)
    {
        res = dfs(i);
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}
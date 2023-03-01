#include<bits/stdc++.h>

using namespace std;
const int N = 50;
int dp[N];
bool b[N] = {false};//存储i值是否存在
int n;
int dfs(int x)
{
    //如果有值之间返回  这便是记忆化作用 
    if(dp[x]) return dp[x];
    if(x == 0) return dp[x] = 0;
    if(x == 1||x == 2) return dp[x] = 1;
    return dp[x] = dfs(x-1) + dfs(x-2); 
}
int main()
{
    
    cin>>n;
    
    for(int i = 0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }

    return 0;
}
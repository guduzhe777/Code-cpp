#include<bits/stdc++.h>

using namespace std;
int n;
const int  N = 100010;
int f[N];
int ans;
int dp[N];//以i为结尾的最长上升子序列长度
int main()
{

    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&f[i]);
    }
    //输入
    for(int i = 1;i<=n;i++)
    {
        dp[i] = 1;
        for(int j = 1;j<i;j++)
        {
            if(f[j]<f[i]) dp[i] = max(dp[i],dp[j] + 1);
            //
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        ans = max(ans,dp[i]);//比较 每一项的最大长度
    }
    cout<<ans<<endl;
    return 0;
}
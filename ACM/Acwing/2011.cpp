#include<bits/stdc++.h>

using namespace std;


int main()
{
    int N,V;
    int weight[202],value[202];
    int dp[202][202] = {0};
    cin>>N>>V;
    for(int i = 0;i<N;i++)
    {
        cin>>weight[i]>>value[i];
    }
    for(int j = 0;j<=V;j++)
    {
        if(j>=weight[0]) dp[0][j] = value[0];
        
    }
    for(int i = 1;i<N;i++)
    {
        for(int j = 0;j<=V;j++)
        {
            if(j<weight[i]) 
            {
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],value[i] + dp[i-1][j - weight[i]]);
            }
        }
    }
    cout<<dp[N-1][V];
    return 0;
}
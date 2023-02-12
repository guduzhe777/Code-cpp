#include<bits/stdc++.h>


using namespace std;

int main()
{
    int T,M;//时间  数量
    int dp[110][1010] = {0};
    cin>>T>>M;
    int time[101];
    int value[101];
    for(int i = 0;i<M;i++)
    {
        scanf("%d",&time[i]);
        scanf("%d",&value[i]);
    }
    for(int j = time[0];j<=T;j++)
    {
        dp[0][j] = value[0];
    }
    for(int i = 1;i<M;i++)
    {
        for(int j = 0;j<=T;j++)
        {
            if(j<time[i])
            {
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j],value[i] + dp[i-1][j-time[i]]);
            }
        }
    }
    printf("%d",dp[M-1][T]);
    return 0;
}








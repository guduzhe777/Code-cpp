#include<bits/stdc++.h>

using namespace std;



int main()
{
    int T,M;
    int dp[1010] = {0};
    int time[110];
    int value[110];
    cin>>T>>M;
    for(int i = 1;i<=M;i++)
    {
        scanf("%d",&time[i]);
        scanf("%d",&value[i]);
    }
    for(int i = 1;i<=M;i++)
    {
        for(int j = T;j>0;j--)
        {
            if(j>=time[i])
            {
                dp[j] = max(dp[j],value[i] + dp[j - time[i]]);
            }
        }
    }
    
    printf("%d",dp[T]);
    return 0;
}
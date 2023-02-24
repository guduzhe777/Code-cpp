#include<bits/stdc++.h>
//闫式DP分析法
using namespace std;
int T,R,C;
const int N = 110;
int dp[N][N],f[N][N];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>R>>C;
        for(int i = 1;i<=R;i++)
        {
            for(int j = 1;j<=C;j++)
            {
                cin>>dp[i][j];
            }
        }
        for(int i = 1;i<=R;i++)
        {
            for(int j = 1;j<=C;j++)
            {
                f[i][j] = max(f[i - 1][j] + dp[i][j],f[i][j-1] + dp[i][j]);
                
            }
        }
        cout<<f[R][C]<<endl;
    }
    
    
    return 0;
}
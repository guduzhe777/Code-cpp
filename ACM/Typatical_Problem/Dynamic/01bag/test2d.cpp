#include<iostream>
using namespace std;

//背包变化  dp含义从最大价值变为最多方案 
//两个组成  不要第i个元素方案数dp[i - 1][j]  + 要第i个元素方案数 （这里的方案数为dp[i-1][j - num[i]]
//从此可以看来  对于 多少个东西 满足 一个条件  这种特征 我们可以用背包来解决 但是dp不一定是所谓最大值
//还有可能是 方案数 不过 具体dp代表含义 需要我们自己 初始化 + 寻找特征方程！    
//多少个数字 加起来 到某个数字 方案 
const int n = 110,m =4000;  //如果 容量大于4000 直接段错误....但是 acwing 不管多少都可以提交！
int main()
{
    int N,M;
    int num[1010];
    int dp[n][m] = {0};
    cin>>N>>M;
    for(int i = 1;i<=N;i++)
    {
        scanf("%d",&num[i]);
    }
    dp[0][0] = 1;   
    for(int i = 1;i<=N;i++)
    {
        for(int j = 0;j<=M;j++)
        {
             dp[i][j] = dp[i-1][j];
            if(j>=num[i])
            {
                dp[i][j] += dp[i-1][j-num[i]];
            }
        }
    }
    printf("%d",dp[N][M]);
    return 0;
}


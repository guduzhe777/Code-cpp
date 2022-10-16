#include<iostream>

using namespace std;

//一维dp[j]数组 
//含义：在j容量下面 放的最大价值
//初始化：dp[0] = 0,dp[j] = 0:因为max比较的时候需要被覆盖 且没有放东西价值就是0！
//递推：dp[j] = dp[j - weight[i]] + value[i],dp[j]
//:我们以物品为外循环 容量为循环
//让每一个物品看放不放进去 不放进去 那么就是原本的值  放进去为第二个  让他们比较
int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    int dp[101] = {0};
    int n,weight[101],value[101];//物品个数 重量 价值
    int bag_capa;//容量
    int j = 0;//代表不同容量
    int i = 0;//代表不同物品
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",weight+i);
        scanf("%d",value+i);
    }
    scanf("%d",&bag_capa);
    //初始化：
   for(j = 0;j<=bag_capa;j++)
    {
        dp[j] = 0;//默认价值为0
    }
    //物品更新价值
    for(i = 0;i<n;i++)
    {
        for(j = bag_capa;j>0;j--)
        {
            // if(j<weight[i])dp[j] = dp[j];///放不进去我放你妹
            if(j>=weight[i]){
            dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);//不放最大价值 和放进去后价值+ 新容量下的最大价值
            }
        }
    }
    cout << dp[bag_capa]<<endl;
    return 0;
}
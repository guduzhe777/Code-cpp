#include <iostream>

using namespace std;

// class OT_Bag
// {

//     void OT_Bag_Easy()
//     {
//     }
// };
int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    // dp  物品数量 物品质量 物品价值
    int dp[101][101] = {0};
    int n, bag_Capa,answer;
    scanf("%d", &n); //物品数量
    
    int value[n] = {0};
    int weight[n] = {0};
    scanf("%d", &bag_Capa);     //容量
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]); //物品质量
        scanf("%d", &value[i]);  //物品价值
    }
    //初始化
    //dp数组中每个元素都代表 i个物品  j容量下 装取最大价值为多少。
    //通过前面情况最大价值 推 后续情况 最大价值：
    //dp[i][j] = max(dp[i-1][j],value[i]+dp[i-1][j-weight[i]]);
    //恰好配合 该物品要不要拿
    //最后输出  n个物品 bag 容量下 能取的最大价值
    for (int j = weight[0]; j <= bag_Capa; j++) {
         dp[0][j] = value[0];
    }
    for (int i = 1; i < n; i++) //物品优先 初始化 一行
    {
        for (int j = 0; j <= bag_Capa; j++) //变化容量
        {
            //初始化最上边 最右边
            // if (i == 0 || j == 0)
            // {
            //     if (j < weight[i]) //放不进去
            //     {
            //         dp[i][j] = 0;
            //     }
            //     else
            //     {
            //         dp[i][j] = value[i];
            //     }
            // }
            //初始化开始写在里面会影响后续判断 
            //dp[i][j] 看第i个值不值得放进去
            //将不放进去最大价值 与放进去 价值 + 剩余容量且在0-i-1任取 情况下的最大价值比较
            //根本放不进去
            if(j<weight[i]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],value[i]+dp[i-1][j-weight[i]]);
            }
            //放进去了然后比较

        }
    }
    cout << dp[n-1][bag_Capa]<<endl;//n-1 代表第n个物体  bag下标正好对应bag容量
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

//一维数组优化 ：  dp含义 还是 i元素 在j容量下 方案数量  
//开始 dp[0] = 1  其他： 没有数字  无法组成j  那么 为方案数为0
// 自己 尝试例子 4 4 1 1 2 2 发现 
///对于  没有进行 输入 i  j 情况下
//f(i,j) = f(i-1,j) （为什么 我只能说 数字 在那里自然呈现的 ） 我这里求出来f(i-1,j)的数值 就是 为了下一次用 
//i j 前 是i-1 j情况！  不同物品共用容量！ 
//i-1 用j容量  i也用 j容量  所以 对于  没有进行 输入 i  j 情况下  数值为 i - 1
//所以 直接 对于 另一部分  直接加即可！
//
int main()
{
    int N,M;
    int num[110];
    int dp[M] = {0};
    
    for(int i = 1;i<=N;i++)
    {
        scanf("%d",&num[i]);
    }
    dp[0] = 1;
    for(int i = 1;i<=N;i++)
    {
        for(int j = M;j>=num[i];j--)
        {
            dp[j] += dp[j - num[i]];
        }
    }
    return 0;
}
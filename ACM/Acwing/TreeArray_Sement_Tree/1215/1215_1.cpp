#include<bits/stdc++.h>

using namespace std;
// const int N = 100010;
const int N = 1000010;
int w[N],tr[N];
//前缀和复杂度 ？  o(1) but  修改复杂度 o(n)
//前缀和  查询 修改 都是o(logn) 懂不懂 含金量
// 暴力 存储 大于等于 ai 个数 == 求大于等于 ai 个数 == 小于等于最大 个数 - 小于等于ai个数  
//就是 大于等于 ai 个数 --》》》求小于ai个数
//对 1 --- i序列  小于ai个数 小于 最大 个数 - 小于 ai个数
//--》》》<hi 数字 出现 次数 的前缀和  便为 序列 小于 hi 的个数
//小于最大的 个数  就是  <max0 数字 出现次数之和
//随着序列更新  数字次数更新 前缀和更新  那么自然用到 树状数组
//树状数组：
//  1. add(x,1) //为x位置 加 1 
//  2.query(x)//返回 (0,x]  前缀和
//应用到题中：
//  tr存储 出现次数的前缀和 即 小于wi的数值 个数
//对于每增加一个数字  小于等于wi的数目增加1 add(wi,1)
//求小于 等于 wi数量 query(wi);
//用 到i时候 某个数字 出现次数   得到 
//log(n)的查询 修改
int n;
int sum[N];//保存 位置i元素需要移动多少次
using ll = long long;
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int v)
{
    for(int i = x;i<N;i += lowbit(i))
    {
        tr[i] += v;;
    }
}
int query(int x)
{
    int sum0 = 0;
    for(int i = x;i>0;i -= lowbit(i))
    {
        sum0 += tr[i];//小于等于i的数量
    }
    return sum0;
}
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        w[i]++;
    }
    //求前面大于 ai数量 
    //先求 小于ai 数量 小于最大值的数量
    //对于每个1 -- i序列 更新 小于ai数量 的tr数组
    for(int i = 1;i<=n;i++)
    {
        add(w[i],1);
        sum[i] += query(N-1) - query(w[i]); //前序的 某个数字出现次数  前缀和  小于等于hi 的数量 最后 大于w[i]数目
    }//得到前面小于等于Hi 的数量
    //倒序  看 小于等于  hi个数 恰好我们需要的
    memset(tr,0,sizeof(tr));
    for(int i = n;i>0;i--)
    {
        add(w[i],1);//多了一个数字  小于等于ai 及之后的数目 更新
        sum[i] += query(w[i]-1); //后序的 小于等于w[i]-1数目才是 w[i]所需要的

    }
    //得到i位置  前序  大于w[i]  后序 小于w[i]数目
    //被移动sum[i] 次 每一个人怒气值为：
    long long res = 0;
    for(int i = 1;i<=n;i++)
    {
        res += (long long )sum[i] *(sum[i] + 1)/2;
    }
    cout<<res<<endl;
    return 0;
}
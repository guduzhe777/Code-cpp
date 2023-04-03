//二维度前缀和
//4个自由度 也意味着 四重循环
//用 两个自由度+双指针 区间单调（r固定 l向左 区间和增加）双指针将 2个自由度化为一个

// #include<bits/stdc++.h>

// using namespace std;
// int n,m,K;
// const int N = 510;
// int f[N][N];
// typedef long long ll;
//4个自由度写法

// int main()
// {
//     cin>>n>>m>>K;
//     for(int i = 1;i<=n;i++)
//     {
//         for(int j = 1;j<=m;j++)
//         {
//             int nu;
//             cin>>nu;
//             f[i][j] = nu + f[i-1][j] + f[i][j-1] -f[i-1][j-1];
//         }
//     }
//     //4个自由度
//     ll res = 0;
//     for(int x1 = 1;x1<=n;x1++)
//     {
//         for(int y1 = 1;y1<=m;y1++)
//         {
//             for(int x2 = x1;x2<=n;x2++)
//             {
//                 for(int y2 = y1;y2<=m;y2++)
//                 {
//                     int sum = f[x2][y2] - f[x1-1][y2]-f[x2][y1-1] + f[x1 - 1][y1-1];
//                     if(sum<=K)
//                     {
//                         res++;
//                     }
//                 }
//             }
//         }
//     }
//     ///得到res
//     printf("%d\n",res);
//     return 0;
// }

//两个自由度 决定上下界 双指针 区间单调

#include<bits/stdc++.h>

using namespace std;
const int N = 510;
int f[N][N];
int n,m,k;
typedef long long ll;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)
        {
            int nu;
            scanf("%d",&nu);
            //上下界决定 + 列一维前缀和
            f[i][j] = nu + f[i-1][j];
        }
    }
    ll res = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j = i;j<=n;j++)
        {
            for(int l = 1,r = 1;l<=r,r<=m;r++)
            {
                int nu = 0;
                //求 
                nu += f[j][r] - f[i-1][r];
                while(nu >k)    //若一段区间 大于k 缩小l
                {
                    nu -=  f[j][l] - f[i-1][l]; //f[j][l]: 1 到 j行 l列元素总和 f[j][l] - f[i-1][j] : l列 i到j总和
                    ///去掉一列
                    l++;//区间改变
                } 
                //这时候符合条件 子矩阵数
                res += r - l + 1;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}

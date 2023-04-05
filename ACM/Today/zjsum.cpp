// #include<bits/stdc++.h>
//双指针 与 前缀和 区间i j 求法 i-1 j
// using namespace std;
// const int N = 110;
// int f[N];
// int n,m;
// typedef long long ll;
// int main()
// {
//     cin>>n>>m;
//     for(int i = 1;i<=n;i++)
//     {
//         cin>>f[i];
//         f[i] += f[i-1];
//     }
//     ll sum = 0;
//     for(int i = 1;i<=n;i++) //i j 区间和 s[j] - s[i-1]
//     {
//         for(int j = i;j<=n;j++)//双指针可以遍历所有的子集
//         {
//             sum += f[j] - f[i-1];
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 110;
int s[N][N];
typedef long long ll;
int main()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            s[i][j] = s[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    ll res = 0;
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int y1 = 1; y1 <= m; y1++)
        {
            for (int x2 = 1; x2 <= n; x2++)
            {
                for (int y2 = 1; y2 <= m; y2++)
                {
                    res += s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
                }
            }
        }
    }
    printf("%lld\n",res);
    return 0;
}
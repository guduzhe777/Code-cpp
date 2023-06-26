#include <bits/stdc++.h>

using namespace std;
//单查询 - 前缀和
// 树状数组  线段树
//前缀和 +  双指针子集
// https://www.acwing.com/video/4756/ 等差数列前缀和！！
const int N = 21;
int t;

int n;

int pre[N];

int main()
{
    scanf("%d", &t);
    int tem = t;
    while (tem--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            pre[i] = pre[i - 1] + x;
        }
        long long ans = 0; //对于该数组的 结果
        int i, j, k;
        for (i = 1; i <= n; i++)
        {
            for (j = i; j <= n; j++)
            {
                for (k = i; k <= j; k++)
                {
                    if (pre[k] - pre[i - 1] < 0)
                    {
                        break;
                    }
                }
                //看子集是否满足
                if (k == j + 1)
                {
                    ans += pre[j] - pre[i - 1];
                }
                else
                {
                    //不可加入
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", t - tem, ans);
    }

    return 0;
}
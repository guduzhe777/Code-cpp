//二维前缀和
//4个自由度
//上下界 + 一维前缀和 区间单调 一段得到整体
#include<bits/stdc++.h>

using namespace std;

int n,m,k;
const int N = 510;
int f[N][N];
typedef long long ll;
int main()
{
    cin>>n>>m>>k;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            cin>>f[i][j];
            //f[i][j] = f[i][j] + f[i-1][j]+f[i][j-1] - f[i-1][j-1];
            f[i][j] += f[i-1][j];
        }
    }
    ll res = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j = i;j<=n;j++)
        {
            for(int l = 1,r = 1,sum = 0;r<=n;r++)
            {
                sum += f[j][r] - f[i-1][r];
                while(sum > k)
                {
                    sum -= f[j][l] - f[i-1][l];
                    l++;
                }
                res += r - l + 1;
            }
        }
    }
    return 0;
}
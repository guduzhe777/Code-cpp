#include<bits/stdc++.h>

using namespace std;

int n,m,k;
const int mod = 1e9 + 7;
const int sz = 61;
int a[sz][sz];
int f[sz][sz][sz][sz];
int main()
{
    cin>>n>>m>>k;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            cin>>a[i][j];
            a[i][j]++;
        }
    }
    f[1][1][0][0] = 1;
    f[1][1][1][a[1][1]]= 1;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            for(int cnt = 0;cnt<=k;cnt++)
                for(int s = 0;s<=14;s++)
                {
                    //不拿！ 到i j cnt个 s 状态
                    f[i][j][cnt][s] =  (f[i][j][cnt][s] + f[i-1][j][cnt][s])%mod;
                    f[i][j][cnt][s] =  (f[i][j][cnt][s] + f[i][j-1][cnt][s])%mod;
                    //如果拿：拿之后到f[i][j][cnt][k] 那么之前应该是 cnt - 1 [0...k-1]
                    if(cnt>0&&s == a[i][j])
                    {
                        //拿了之后我价值要从 [0....k-1] 添加一个 价值为k的即可
                        for(int x = 0;x<a[i][j];x++)
                        {
                            f[i][j][cnt][s] = (f[i][j][cnt][s] + f[i-1][j][cnt-1][x])%mod;
                            f[i][j][cnt][s] = (f[i][j][cnt][s] + f[i][j-1][cnt-1][x])%mod;
                        }
                    }
                }

    //求出来每个方案数之后 把 f[n][m][k][价值不定]方案数加起来
    int res = 0;
    for(int i = 1;i<=13;i++)
    {
        res =(res + f[n][m][k][i])%mod;
    }
    res = res%mod;
    cout<<res<<endl;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
const int N = 5010;
int n,R;
int f[N][N];
int x,y,w;
int max0 = INT_MIN;//最大价值
int main()
{
    cin>>n>>R;
    R = min(5001,R);
    int u = R,v = R;
    while(n--)
    {
        cin>>x>>y;
        x++,y++;
        int tem;
        cin>>tem;
        f[x][y] += tem;
        u = max(u,x),v = max(v,y);
    }
    for(int i = 1;i<=u;i++)
    {
        for(int j = 1;j<=v;j++)
        {
            f[i][j]  = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + f[i][j];
        }
    }//得到矩阵前缀和
    if(R>=5001) printf("%d\n",f[u][v]);
    else{
        //求 子矩阵前缀和
        for(int i = R ;i<=u;i++)//坐标从1开始  那么第R个 坐标为 R+1
        {
            for(int j = R ;j<=v;j++)
            {
                int x1 = i - R;
                int y1 = j - R;
                int tem = f[i][j] - f[i][y1] - f[x1][j] + f[x1][y1];
                max0 = max(max0,tem);
            }
        }
        printf("%d\n",max0);
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int N = 1010;
int n,m,q;
int f[N][N];
int x,y,x2,y2;
int main()
{
    cin>>n>>m>>q;
    int p;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            scanf("%d",&f[i][j]);
            f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        }
    }
    
    while(q--)
    {
        cin>>x>>y>>x2>>y2;
        int ans = f[x2][y2] - f[x2][y-1] - f[x-1][y2] + f[x-1][y-1];
        cout<<ans<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
//对于任意阵  不仅仅是方阵来说

using namespace std;
const int N = 1010;
int m,n;
int f[N][N];
int main()
{
    cin>>m>>n;
    for(int i = 0;i<m;i++)
        for(int j = 0;j<n;j++)
            cin>>f[i][j];

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            printf("%4d",f[j][i]);
        }
        printf("\n");
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n,m;
const int N = 7;
int f[N][N];
int main()
{

    cin>>m>>n;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>f[i][(j + m ) % n];
        }
    }
    
    for(int i = 0;i<n;i++)
    {
        
        for(int j = 0;j<n;j++)
        {
            printf("%d ",f[i][j]);
        }
        cout<<endl;
    }
    return 0;
}
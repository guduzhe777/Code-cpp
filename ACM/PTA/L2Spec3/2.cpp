#include<bits/stdc++.h>

using namespace std;

int f[110][110];
int p[110];
int n,m,k;
int find(int x)
{
    if(p[x] == x) return x;
    p[x] = find(p[x]);
    return p[x];//返回祖宗  
}

void union1(int x,int y)
{
    p[find(x)] = find(y);
}

int main()
{
    cin>>n>>m>>k;
    for(int i = 1;i<=n;i++)
    {
        p[i] = i;
    }
    for(int i = 0;i<m;i++)
    {
        int x,y,si;
        cin>>x>>y>>si;
        f[x][y] = f[y][x] = si;
        if(si == 1)
        {
            union1(x,y);
        }
    }
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        if(find(x) == find(y)&&f[x][y] != -1)
            printf("No problem\n");
        else if(find(x) == find(y)&&f[x][y] == -1)
            printf("OK but...\n");
        else if(find(x) != find(y)&&f[x][y] == -1)
            printf("No way\n");
        else if(find(x) != find(y)&&f[x][y] != -1)
            printf("OK\n");
    }
    return 0;
}
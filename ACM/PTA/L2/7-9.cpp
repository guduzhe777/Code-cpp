#include<bits/stdc++.h>

using namespace std;
const int N = 110;
int f[N][N];
int n,m,k;//宾客总人数  已知两两宾客之间的关系数  查询的条数

//其中关系为0表示是朋友，1表示是不是朋友，但也不敌对，。
//2有敌对，然而也有共同的朋友
//3:只有敌对关系，则输出No way。
int w[N][N];
int main()
{
    
    cin>>n>>m>>k;
    for(int i = 0;i<m;i++)
    {
        int x,y;
        cin>>x>>y>>f[x][y];
        f[y][x] = f[x][y];
    }
    memcpy(w,f,sizeof(f));
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            
            if(f[i][j] == -1)//如果两个人是敌人 //看是否有公共朋友
            {
                for(int k = 1;k<=n;k++)
                {
                    if(f[i][k] == 1 &&f[j][k] == 1)
                    {
                        
                        w[i][j] = 2;
                        w[j][i] = 2;
                    }
                }
                
            }
            
        }
    }
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        int tem =  w[x][y];
        if(w[x][y] == 0)
        {
            printf("OK\n");
        }
        if(w[x][y] == -1)
        {
            printf("No way\n");
        }
        if(w[x][y] == 1)
        {
            printf("No problem\n");
        }
        if(w[x][y] == 2)
        {
            printf("OK but...\n");
        }
    }
    return 0;
}
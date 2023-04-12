#include<bits/stdc++.h>

using namespace std;



int f[7][7];
int n;
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>f[i][j];
        }
    }
    for(int i = 0;i<n;i++)
    {
        //i行 寻找最大
        int maxpos = 0;
        for(int j = 1;j<n;j++)
        {
            if(f[i][maxpos]<=f[i][j])
            {
                maxpos = j;
            }
        }
        //默认是列最小
        bool si = true;
        for(int k = 0;k<n;k++)
        {
            if(f[i][maxpos]>f[k][maxpos])
            {
                si = false;
                break;
            }
        }
        if(si)
        {
            printf("%d %d",i,maxpos);
            return 0;
        }
    }
    printf("NONE\n");
    return 0;
}
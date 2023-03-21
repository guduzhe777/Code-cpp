#include<bits/stdc++.h>

using namespace std;
int N,K;
const int Asize = 100010;
int f[Asize];
int x;
int main()
{
    scanf("%d %d",&N,&K);
    int cnt = 0;
    for(int i = 1;i<=N;i++)
    {
        scanf("%d",&x);
        
        f[i] = f[i-1] + x;
    }
    for(int i = 0;i<=N;i++)
    {
        for(int j = i+1;j<=N;j++)
        {
            if((f[j] - f[i] )% K == 0) cnt++;
        }
    }
    //所以遍历完
    printf("%d",cnt);
    return 0;
}
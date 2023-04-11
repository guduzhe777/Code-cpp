#include<bits/stdc++.h>


using namespace std;

int n,m;
bool prime[510];

void cacl()
{
    memset(prime,1,sizeof(prime));
    prime[0] = 0;//我的评价是不如合数
    prime[1] = 0;
    for(int i =2;i<=510;i++)
    {
        if(prime[i])
        {
            for(int j = 2 * i;j<=510;j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
int cnt,sum;
int main()
{
    cin>>n>>m; 
    cacl();
    for(int i = n;i<=m;i++)
    {
        if(prime[i])
        {
            cnt++;
            sum += i;
        }
    }
    printf("%d %d",cnt,sum);
    return 0;
}
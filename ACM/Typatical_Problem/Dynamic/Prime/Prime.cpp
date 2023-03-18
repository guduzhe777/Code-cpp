#include<bits/stdc++.h>

using namespace std;
const int N = 10010;
bool prime[N];
//prime[i] i是否为质数  true为质数
//欧拉晒 i * i 到 n  but  递增 j += i i的倍数  就是 j 不断加i
int n;
int main()
{

    for(int i=0;i<=N;i++)
		prime[i]=true;       // 所有数先标记为true
    prime[0] = false;
    prime[1] = false;
    for(int i = 2;i<=N;i++)
    {
        if(prime[i])//质数 += i筛完
        {
            for(int j = i * i;j<=N;j += i)
            {
                prime[j] = false;
            }
        }
    }
    cin>>n;
    int sum = 0;
    int cnt = 0;
    for(int i = n;i>=2;i--)
    {
        if(prime[i])
        {
            sum += i;
            // if(!cnt)
            // {
            //     printf("%d",i);
            // }
            // else{
            //     printf("%d ",i);
            // }
            printf("%d ",i);
            cnt++;
            if(cnt == 10)
            {
                break;//第十个
            }
        }
    }
    printf("\nsum = %d\n",sum);
    return 0;
}
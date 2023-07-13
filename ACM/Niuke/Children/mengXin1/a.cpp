#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e2 ,M = 1e2;
ll ans;
ll k;
ll phi[N],pri[M]; //分别对应素数表和欧拉函数值

ll mod = 1000000007;
void getphi(ll n)    
{    
   ll vis[M],tot = 0;   
   for(int i=2;i<=n;i++)   
   {    
     	if(!vis[i])//先判断i是不是素数    
    	{    
            pri[++tot]=i; 
            phi[i]=i-1;//当 i 是素数时小于i的所有大于零的数都和i互素    
        }    
       	for(int k=1;k<=tot;k++)    
       	{    
          	if(i*pri[k]>M)  break;    
          	vis[i*pri[k]]=1;//按照筛素数，筛掉i的倍数 
          	if(i%pri[k]==0)//如果有一个质数是i的因子，那么phi(i*pri[k])=phi(i)*pri[k]  
          	{    
             	phi[i*pri[k]]=phi[i]*pri[k];break;    
          	}    
          	else  phi[i*pri[k]]=phi[i]*(phi[pri[k]]);
			  //利用了欧拉函数的积性,两个数互质，那么phi(i*k)=phi(i)*phi(pri[k])   
       	}    
   }    
}    
int main()
{
    cin >> k;
    getphi(k);
    for (int n = 1; n <= k; n++)
    {
        for (int i = 1; i <= n; i++)
        {
            ans += (phi[i]*(n / i)) % mod;
        }
    }
    cout << ans;
    return 0;
}
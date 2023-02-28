#include<bits/stdc++.h>
using namespace std;
int n,K;
const int N = 100010;
using ll = long long;
ll f[N];//加法 可能会爆
ll cnt[N];//存储 同余出现几次 全k 同余0 出现10^10
int main()
{
    scanf("%d %d",&n,&K);
    ll res = 0;//全都是 k时候  c 100000^2 个  10^10
    cnt[0] = 1;//对于同余为0的  
    for(int i = 1;i<=n;i++)
    {
        scanf("%lld",&f[i]);
        f[i] += f[i-1];
    }
    for(int i = 1;i<=n;i++)
    {
        res += cnt[f[i] % K]; //有cnt[f[i]%K] 可以与其配对 所以同余个数 为cnt[f[i] % K]
        cnt[f[i]%K]++;          //自身也是同余一种 那么会增加一个 把自身包括下去等待下一次使用
    }
    printf("%lld",res);
    return 0;
}
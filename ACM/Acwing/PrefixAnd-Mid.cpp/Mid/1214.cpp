//必须强迫自己写暴力才能明白过程是怎么样的

#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
using ll = long long;
ll n,s,a,b;
ll max1 = 1e9;
ll f[N];
ll ans = 0;
ll sum = 0;
void def(int x)//寻路放元素
{
    if(x>n)
    {
        if(sum == s)    ans++;
        
        sum = 0;
    }
    
    for(ll i = -max1;i<=max1;i++)
    {
        def(i);

    }
}
int main()
{
    scanf("%ld %ld %ld %ld",&n,&s,&a,&b);
    def(1);
    return 0;
}
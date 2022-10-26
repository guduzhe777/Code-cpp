#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
ll fastpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b&1)
        {
            res *= a;
        }
        b = b >> 1;
        a *= a;//总归是a^b来乘以  b的权重从1 2 4  a对应从a 1 a 2
    }
    return res;
}
int main()
{
    ll a, b;
    while(cin>>a>>b)
    {
        cout<< fastpow(a, b)<<endl;
    }

    return 0;
}

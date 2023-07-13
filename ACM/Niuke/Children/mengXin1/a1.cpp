#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll ans;
ll k;
ll Euler(ll N)
{
    ll ret = N;
    for (ll i = 2; i * i <= N; i++)
        if (N % i == 0)
        {
            ret = ret * (i - 1) / i;
            while (N % i == 0)
                N /= i;
        }
    if (N > 1)
        ret = ret * (N - 1) / N;
    return ret;
}

ll mod = 1000000007;
int main()
{
    // cin >> k;

    // for (int n = 1; n <= k; n++)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         ll ret = Euler(i);
    //         ans += (ret * (n / i)) % mod;
    //     }
    // }
    cout<<Euler(1) <<" "<<Euler(2) <<" "<<Euler(3) <<" ";
    return 0;
}
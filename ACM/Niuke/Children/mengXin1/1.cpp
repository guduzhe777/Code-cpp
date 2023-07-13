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

int main()
{
    cin >> k;

    for (int n = 1; n <= k; n++)
    {
        for (int i = 1; i <= n; i++)
        {
            ans += Euler(i) * (n / i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
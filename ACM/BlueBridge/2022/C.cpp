#include<bits/stdc++.h>


using namespace std;

using ll = long long;
int main()
{
    ll a,b,n,k,tem;
    cin>>a>>b>>n;
    int cnt = 0;
    ll amt_days = 5 * a,amt_end = 2 * b;
    tem = n % (amt_days + amt_end);
    cnt = n / (amt_days + amt_end);
    cnt *= 7;
    if(tem<=amt_days)
    {
        cnt += tem / a +(tem % a != 0);
    }
    else{
        cnt += 6 + ((tem - amt_days)> b );
    }
    cout<<cnt<<endl;
    return 0;
}
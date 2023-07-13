//https://codeforces.com/problemset/problem/1843/C

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t;
ll  n;
ll ans;

int main()
{

    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>n;
        ans = n;
        while(n)
        {
            if(n % 2)
            {
                n = (n - 1) / 2;
                ans += n;
            }else{
                n = n / 2;
                ans += n;
            }

        }
        cout<<ans<<endl;
    }



    return 0;
}
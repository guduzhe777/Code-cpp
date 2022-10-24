#include<iostream>

using namespace std;
typedef long long ll;
long long t,k;
class solution{

public:
    ll sovlex_y(ll a,ll b)
    {
        if(b == 0)
        {
            t = 1;
            k = 0;
            return a;
        }
        ll r = sovlex_y(b,a%b);
        ll temp = k;
        k = t - (a/b) * k;
        t = temp;
        return r;
    }
    ll gcd(ll a,ll b)
    {
        return b == 0?a:gcd(b,a%b);
    }
};
ll obs(ll b)
{
    return b>0?b:-b;
}

int main()
{
    solution s;
    ll x,y,m,n,L,a,b;
    cin>>x>>y>>m>>n>>L;
    // ll c = y -x;
    // a = m - n;
    // b = -L;
    ll c = x - y;
    a = n - m;
    b = L;

    // if(b<0)
    // {
    //     b=-b;
    //     a=-a;
    // }//处理负数 
    ll ret = s.gcd(a,b);
    if(c % ret == 0)
    {
        ll r = s.sovlex_y(a,b);
        t *= c/ret;
        while(t<0)
        {
            t += obs(b);
        }
        t = t%b;
        
        cout<<t;
        
        // cout<<((t*(c/r))%(b/r)+(b/r))%(b/r);
    }
    else{
        cout << "Impossible"<<endl;
    }

}


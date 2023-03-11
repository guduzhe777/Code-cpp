#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int a,b,n;//b个a  n是超算个数
//b个a 相乘  得到的数字  当作a 继续 超算
ll obs(ll a,ll b,int n)//b个a相乘
{
    a = pow(a,b);
    if(n == 3)
    {
        return a;
    }
    obs(a,b,n-1);
}
int main()
{
    cin>>a>>b>>n;
    cout<<obs(a,b,n)<<endl;
    
    return 0;
}
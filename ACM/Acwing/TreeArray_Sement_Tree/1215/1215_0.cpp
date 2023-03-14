#include<bits/stdc++.h>

using namespace std;
const int N = 100010;
int w[N];//序列储存
int k1[N];//对于i位置  大于等于 ai的 个数 
int k2[N];//
int sum[N];
int n;
using ll = long long;
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)    
    {
        scanf("%d",&w[i]); 
        for(int j = 1;j<i;j++)
        {
            if(w[j]>w[i])
            {
                k1[i]++;
            }
        }
    }
    for(int i = n;i>0;i--)
    {
        for(int j = n;j>i;j--)
        {
            if(w[j]<w[i])
            {
                k2[i]++; //对于i位置  后面小于ai的数量
            }
        }
    }
    for(int i = 1;i<=n;i++)
    {
        sum[i] = k1[i] + k2[i];
    }
    ll res = 0;
    for(int i = 1;i<=n;i++)
    {
        res += (ll) sum[i] * (sum[i] + 1)/2;
    }
    cout<<res<<endl;
    return 0;
}
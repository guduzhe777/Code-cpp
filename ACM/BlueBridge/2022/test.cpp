#include<bits/stdc++.h>

using namespace std;

using ll = long long;
ll mod = 1000000007;
int aarr[100001] = {0},barr[100001] = {0},basearr[100001];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int N;//最高进制
    ll a,ma,b,mb; //数字 a  ma位  分别为多少  数字 b  mb位  分别为多少  
    cin>>N;
    cin>>ma;
    
    for(int i = 0;i<ma;i++) cin>>aarr[i];
    cin>>mb;
    for(int i = 0;i<mb;i++) cin>>barr[i];
    for(int i = 0;i<max(ma,mb);i++)
    {
        basearr[i] = max(max(aarr[i],barr[i]) + 1,2);
    }
    for(int i = 0;i<max(ma,mb);i++)
    {
        printf("%d ",basearr[i]);
    }
    ll data_A = 0,data_B = 0;
    for(int i = 0;i<ma;i++)
    {
        data_A = (data_A * basearr[i] + aarr[i])%mod;
    }
    for(int i = 0;i<mb;i++)
    {
        data_B = (data_B * basearr[i] + barr[i])%mod;
    }
    printf("\n%d ",data_A);
    printf("\n%d ",data_B);
    printf("\n%lld",(data_A-data_B+mod)%mod);
    return 0;
}
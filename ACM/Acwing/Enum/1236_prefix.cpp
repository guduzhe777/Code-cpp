#include<bits/stdc++.h>
using namespace std;


//思路 ：
//cnt 存储 某个数字在 a  c  中存储几次
//前缀和得到  小于等于 i数字出现几次
//数组存储  as[] 存储小于 等于i  的值  然后 对标 b[j](值) 
//cs[] 存储大于等于 i的值  对标 b[j] 
//因为数据 10^5 所以 必须 n* log(n)   
//因为   经过 计数后  数字值的作用消失  只看 他 小于等于  某个  值的个数
//比较的两端同加1即可
//cnt[0]情况 0出现多少次
//s[0]  = s[-1]  + cnt[0] 所以 严格从1 开始  自加1 即可
const int N  = 10e5+10;
int a[N],b[N],c[N];
int cnt[N];//数字最大 10^5
int s[N]; //小于等于i出现几次
ll as[N],cs[N];//存储  a中几个 数小于  b[j] c中几个 数大于b[j]
int n;
using ll  =  long long;
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]) ,a[i]++; 
    for(int i = 0;i<n;i++)
        scanf("%d",&b[i]),b[i]++;
    for(int i = 0;i<n;i++)
        scanf("%d",&c[i]),c[i]++;  
        //求 a中   小于b[j] 的数量
    for(int i = 0;i<n;i++)
    {
        cnt[a[i]]++;
    }  
    for(int i =  1;i<=N;i++)//数字 严格从1开始  应该是 1 出现的次数 到i最大 确定所有数字出现个数 
    {
        s[i] = cnt[i] + s[i-1];
    }
    for(int i = 0;i<n;i++)
    {
        as[i]   =   s[b[i]-1];
    }
    //求c中  大于b[j]数量
    memset(cnt,0,sizeof(cnt));
    memset(s,0,sizeof(s));
    for(int i = 0;i<n;i++)
    {
        cnt[c[i]]++;
    }
    for(int i = 1;i<=N;i++)
    {
        s[i] = cnt[i] +  s[i-1];
    }
    for(int i = 0;i<n;i++) 
    {
        cs[i] = s[N-1] - s[b[i]];
    }
    ll res = 0;
    for(int i = 0;i<n;i++)
    {
        
        res += (ll)(as[i] * cs[i]);
    }
    cout<<res;
    return 0;
}
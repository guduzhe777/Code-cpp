#include<bits/stdc++.h>

using namespace std;
//核心寻找 a中  几个  小于b[i]  c中 几个大于b[i] 的
//对 a  c  排序 
//二分寻找 a中  比  b[i]小的
//n * log(n) * 2  
using ll = long long;
const int N = 10e5+10;
int a[N],b[N],c[N];
int n;
ll min_num;
ll max_num;//c中 比 b[i]大的 数量
using ll = long long;
bool checkmin(int mid,int target)
{
    if(a[mid]<target) return true;
    else return  false;
}
int Searmin(int target)
{
    int l = -1,r = n;
    int mid;
    while(l + 1 != r)
    {
        mid = (r-l)/2 + l;
        if(checkmin(mid,target)) l =  mid;
        else r =  mid;
    }
    return l + 1;
}
bool checkmax(int mid,int target)
{
    if(c[mid]>target) return true;
    else return  false;
}
int Searmax(int target)
{
    int l = -1,r = n;
    int mid;
    while(l + 1 != r)
    {
        mid = ( r - l )/2  +  l;
        if(checkmax(mid,target)) r = mid;
        else l = mid;
    }
    return n  -  r;
}
int main()
{
    scanf("%d",&n);
    for(int i =0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i =0;i<n;i++)
        scanf("%d",&b[i]);
    for(int i =0;i<n;i++)
        scanf("%d",&c[i]);
    sort(a,a+n);
    sort(c,c+n);
    ll res = 0;//存储 一共多少个
    for(int i = 0;i<n;i++)
    {
        min_num = Searmin(b[i]);
        max_num = Searmax(b[i]);
        res += max_num * min_num;
    }
    cout<<res;
    return 0;
}
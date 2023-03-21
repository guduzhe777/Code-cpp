#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
int n,k;
int w[N],h[N];
bool check(int mid)//mid过大 返回false r = mid    mid 小一点
{
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum += (w[i] / mid) * (h[i] / mid);//i块巧克力分了这些块
        if(sum>=k) return true;//mid 较小
    }
    return false;
}
int main()
{
    cin>>n>>k;//k个朋友 n块巧克力
    for(int i = 0;i<n;i++)
        cin>>h[i]>>w[i];//保存 巧克力
    int l = 0,r = 1e5+1;//范围搞错了 
    while(l + 1 != r)
    {
        int mid = (r - l)/2+l;
        if(check(mid)) l = mid;         //true mid太小   二者有联系，check true地方 属于l
        else{                           //所以l 最后指向的 check true的边界
            r = mid;//不可以分 减小分的数量     
        }
        
    }
    cout<<l<<endl;
    return 0;
}
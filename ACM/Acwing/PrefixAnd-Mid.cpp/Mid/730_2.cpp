// 从i翻到 i + 1 剩余能量 总归都是 2E - H(i+1)
//出现<0情况就g
//查找 最小的开始值  遍历E 找到 第一个 不小于0的 
//当你准备 顺序遍历某个数值 的时候  不妨在其范围内  二分查找 

#include<bits/stdc++.h>

using namespace std;
const int N = 10e5+10;
int H[N];
int n;
using ll = long long;
bool check(ll mid)
{
    for(int i = 1;i<=n;i++)
    {
        mid = 2 * mid - H[i];//得到每一次跳跃的值
        if(mid>1e5)
        {
            return true;//防止爆int ，且 1e5 为最大 h[i](max) 保证了一定 能通过
        }
        if(mid<0)
        {
            return false;//这个mid太小了
        }
    }
    return true;//这个数字可以
}
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&H[i]);
    }
    int l = -1,r = 1e5 +  1;//二分查找数字
    while(l + 1 != r)
    {
        ll mid = (r - l)/2+l;
        if(check(mid)) r = mid;
        else{
            l = mid;
        }
    }
    cout<<r<<endl;
    return 0;
}
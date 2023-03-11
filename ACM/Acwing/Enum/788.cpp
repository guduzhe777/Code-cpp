#include<bits/stdc++.h>

using namespace std;
int n;
const int N = 1e5+10;
int f[N];
using ll = long long;
int tem[N];
ll merge(int l,int r)//计算逆序对数量 最多 5 * 10^ 9 （n n -1 n- 2 ..全都是逆序对 ）
{
    if(l>=r) return 0;
    int mid = (r - l)/2 + l;
    
    ll res = merge(l,mid) + merge(mid+1,r);
    int i = l,j = mid + 1,k = 0;//k 指向临时数组 暂时保存数值 等会还给别人即可  k=从第一个开始就行
    while(i<=mid&&j<=r)
    {
        if(f[i]<=f[j]) tem[k++] = f[i++];
        else{
            tem[k++] = f[j++];
            res += mid - i + 1;
        }
    }
    //对 两边序列 比较后 
    //扫尾
    while(i<=mid) tem[k++] = f[i++];
    while(j<=r) tem[k++] = f[j++];
    //物归原主
    for(int i = l,j = 0;i<=r;i++,j++)
    {
        f[i] = tem[j];
    }
    return res;
}
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)
        cin>>f[i];

    ll ret = merge(0,n-1);
    cout<<ret<<endl;
    return 0;
}
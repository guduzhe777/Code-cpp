
//抽离这个动作 有这样性质：只能奇数/偶数索引子集选择性 结合
//：证明 一般抽离 会减少三个元素 增加一个元素 = 减少两个元素 
// 所以起决定性作用为 第一个元素 若为奇数/偶数索引 那么 抽离后 该元素也是奇数/偶数索引
//当然也可以 不使某个元素加入子集 即 不抽离二者之间的元素（两个元素不结合）
//对于求最大 即奇数索引 偶数索引子集 各自求最大 比较
//为了最大保证每一个元素都为整数！ 负数则不合如子集
//全是负数时候 不能全不放子集  所以找出一个最大的。
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int t;
int n;
ll ans;
const int N = 2 * (1e5) + 10;
int a[N];

void solve()
{
    cin>>n;
    bool si = true;//全是负数
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>0) si = false;//含有整数
    } 
    int max0 = -1e9;
    ll ans1 = 0,ans2 = 0;
    if(si)
    {
        for(int i = 0;i<n;i++)
            max0 = max(max0,a[i]);
        cout<<max0<<endl;
    }else{
        for(int i = 0;i<n;i++)
        {
            if(i & 1)
            {
                if(a[i]>0) ans1 += a[i];
            }else{
                if(a[i]>0) ans2 += a[i];
            }
        }   
        ans = max(ans1,ans2);
        cout<<ans<<endl;
    }
    
}
int main()
{
    cin>>t;

    while(t--)
        solve();
    


    return 0;
}
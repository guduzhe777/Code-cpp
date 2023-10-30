
//这里是我没有看到 分开操作 会发生什么影响
//他会导致 分开处 两人的怀疑值消失
//为了让怀疑最小  所以 让 最大怀疑值消失即可
//边界：一个人的怀疑没用 不用管所以不算入威胁 第一个人 无法与前一个联合
// 所以不放入怀疑数组va中 
//在组成怀疑的时候 都没有考虑过 第一个 依靠 1才有0 
#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 110;
int t;
int n,k;
int a[N];

void sovle()
{
    cin>>n>>k;
    for(int i = 0;i<n;i++) cin>>a[i];
    vector<int> va;
    int sum = 0;
    for(int i = 1;i<n;i++)
    {
        va.push_back(abs(a[i] - a[i-1]));
        sum += va.back();
    }
    sort(all(va));
    for(int cnt = 1;cnt<k;cnt++) //将最大破除
    {
        sum -= va.back();
        va.pop_back();
    }
    cout<<sum<<endl;
}
int main()
{

    cin>>t;
    while(t--)
        sovle();



    return 0;
}
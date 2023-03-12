#include <iostream>
using namespace std;

const int N = 32010;
//空间换时间做法
//两个数组保存  二维信息
//二维可以保存三个维度值
//三个一维数组保存三个维度值
//but 访问信息 需要 n^2 复杂度
//三个一维 o(n)即可
int cnt[N],b[N],tr[N];//b保存 输入后当前  横坐标 i 含有 的  星星个数
//tr 保存  i 前缀和 星星个数 
//cnt 保存 星星i级 出现次数
int n;
int x,y;
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int v)//修改 所有的树状前缀和 
{
    for(int i = x; i<=N;i += lowbit(i)) tr[i] += v;
}
int query(int x)
{
    long long res = 0;
    for(int i = x;i>0;i -= lowbit(i)) res += tr[i];
    return res;
}
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>x>>y;
        x++;//坐标 从1开始
        cnt[query(x)]++;//x前面的星星数 代表星级
        b[x]++;//x坐标下的星星 多一个
        add(x,1);

    }
    for(int i = 0;i<n;i++) cout<<cnt[i]<<endl;
    return 0;
}
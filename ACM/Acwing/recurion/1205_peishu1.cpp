#include<bits/stdc++.h>

using namespace std;
//a b 如果有公约数m 凡是 不是m的倍数的 一定无法组成
//所以必须是 a b互质
//无法组成的最大数？
//a x  + b y = ?  递归看 k 是否能被 a b组成
int n,m;
bool dfs(int i,int n,int m)
{
    if(!i) return true;
    if(i>=n&&dfs(i-n,n,m))
    {
        return true;// 意思是 暂时可以用
    }
    if(i>=m&&dfs(i-m,n,m))
    {
        return true;
    }
    return false;//如果都不能减法 i不为0
}
int main()
{
    cin>>n>>m;
    int ans = 0;
    for(int i = 2;i<=10000;i++)
    {
        if(!dfs(i,n,m))
        {
            ans = i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
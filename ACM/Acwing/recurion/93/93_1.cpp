#include <bits/stdc++.h>
using namespace std;
int m, n;
const int N = 100010;
int f[N];
bool sign[N] = {false};
void dfs(int x,int k)//安放位置
{
    if(x>m)
    {
        for(int i = 1;i<=m;i++)
        {
            cout<<f[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for (int i = k; i <= n; i++)
    {
        if (!sign[i])//未被选
        {
            f[x] = i;
            sign[i] = true; //选择
            dfs(x+1,i+1);//从i + 1开始！
            sign[i] = false;//如果从上一步回退出来 说明 这个已经用完了 自然变成不被用
        }
        else{//被选了
            continue;
        }
        
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    dfs(1,1);
    return 0;
}
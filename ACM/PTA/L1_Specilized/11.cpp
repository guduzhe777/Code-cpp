#include<bits/stdc++.h>

using namespace std;

int a = 1;//最后一天
int n;
int dfs(int x)
{
    if( x == 1)
    {
        return  a;
    }
    a = (a + 1) * 2;
    dfs(x - 1);//上一天
}
int main()
{
    while(cin>>n)
    {
        a = 1;
        dfs(n);
        printf("%d\n",a);
    }
    return 0;
}
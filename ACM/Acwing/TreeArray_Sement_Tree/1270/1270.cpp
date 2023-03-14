#include<bits/stdc++.h>

using namespace std;
//四大核心函数 
//build modify  pushup query 
//初始化线段树
//修改线段树
//子孩子 更新 父亲的值
//整合需要的信息
int m,x,y;
int n;
const int N = 10010;
int w[N];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++) scanf("%d",&w[i]);
    while(m--)
    {
        int max0 = INT_MIN;
        scanf("%d %d",&x,&y);
        for(int i= x;i<=y;i++) 
        {
            max0 = max(max0,w[i]);
        }
        cout<<max0<<endl;
    }
    return 0;
}
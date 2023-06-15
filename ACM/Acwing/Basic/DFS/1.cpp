#include<bits/stdc++.h>

using namespace std;
#define  N 11
int n;

//AcWing 842. 排列数字
// https://www.acwing.com/activity/content/problem/content/905/
//
// 输入n 
// 排序：给n个位置放值
//前面放过 那么 不再放
//标记数组：

bool a[N];
int b[N];   //b[i] = j i位置 值 j
void dfs(int x) //x位置
{
    
    if(x == n + 1)
    {
        for(int i = 1;i<=n;i++)
        {
            printf("%d ",b[i]);
        }
        printf("\n");
        
        return;
    }
    for(int i = 1;i<=n;i++)
    {
        
        if(!a[i])
        {
            b[x] = i;
            a[i] = 1;
            dfs(x+1);//下一个位置
            //回溯：到这一步了 那么 后面都用完了（这里是输出完了） 那么该值不再被使用且可以被其他位置 使用
            a[i] = 0;

        }
    }
}
int main()
{
    
    scanf("%d",&n);
    
    dfs(1);
    
    
    return 0;
}
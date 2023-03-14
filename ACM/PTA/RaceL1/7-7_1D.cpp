#include<bits/stdc++.h>

using namespace std;
const int N = 100010;
int n,m,q;
int t,c;
bool state[N];//一维储存二维状态
//幸好 对于n * m <=10^5
//不然用状态压缩了
int main()
{
    cin>>n>>m>>q;
    while(q--)
    {
        cin>>t>>c;
        if(!t)// 0 行改变
        {
            //如何在一维中访问 二维存储的数据呢
            //行 i 行 (i - 1) * m   (i - 1) 行
            for(int i = (c-1)*m + 1,j = 1;j<=m;i++,j++) //一行m个元素 访问 m 个元素即可
            {
                //c行进行修改
                state[i] = true;//可以被放技能
                
            }

        }else{
            //访问列  c列  c += m  对于 c列 向下 都 迭代加 m
            for(int i = c,j = 1;j<n;i += m,j++) //2行 最多加 1 次  n行加n - 1次  j起记录次数作用
            {
                state[i] = true;//
            }
        }
    }
    int res = 0;
    for(int i = 1;i<=n * m ;i++)
    {
        if(state[i]) res++;
    }
    cout<<n * m - res;
    return 0;
}
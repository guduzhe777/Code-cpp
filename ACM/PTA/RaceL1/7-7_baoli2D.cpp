//三个整数 N,M,格子   Q个 技能位置
//暴力统计  //行列状态改变  最后统计 flase 不会被打到
//一维存储二维数据
//位置对应关系：
//行：i 行  对应  1 + (i-1) * m  (i-1) * m  认为是前i-1 行元素
//列：j列   对应 j + (0 ... n-1 ) * m;
#include<bits/stdc++.h>

using namespace std;
int n,m,q;
int c,t;
const int N = 100010;
bool state[N][N];
int main()
{
    cin>>n>>m>>q;
    while(q--) 
    {
        cin>>t>>c;
        if(!t) //行
        {
            for(int i = 1;i<=m;i++)
            {
                state[c][i] = true;
            }
        }else{
            for(int i = 1;i<=n;i++)//对这一列进行变化
            {
                state[i][c] = true;
            }
        }
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++)
            for(int j = 1;j<=m;j++)
            {
                if(!state[i][j]) cnt++;//不会收到攻击的
            }
    cout<<cnt;
    return 0;
}
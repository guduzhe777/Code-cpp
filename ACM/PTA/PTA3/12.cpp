//模拟---vector


#include<bits/stdc++.h>
using namespace std;


//用 数组嵌套 动态数据好处是 内部可以扩充
// typedef vector<int> vi;
// typedef vector<vi> vii;
// const int N  = 1e5+10;
// vii state[N];//state[i][j]  = k : i据点  j位置 到 k据点
typedef vector<int> vi;
const int N = 1e5+10;
vi st[N];
int dw[N];//dw[i] = 5  i挡位 存储 第5个位置
int n,m;
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j = 0;j<k;j++)
        {
            int nu;
            cin>>nu;
            st[i].push_back(nu);
        }
    }
    int pos = 1;//标记在哪里
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(x == 0)
        {
            pos = st[pos][y-1];//到 据点 的 第y个位置
        }else if(x == 1)
        {
            printf("%d\n",pos);
            dw[y] = pos;
        }else if(x == 2){
            pos = dw[y];///读档
        }
    }
    printf("%d\n",pos);//最后
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
//暴力
//以时刻 穷举  利于 到T暂停
//二元组 保存时间  及 某家店保存
//
typedef pair <int,int> PII;
const int N = 1e4 + 10;
int order[N][N]; //存储 某时刻 某店铺点了多少单
int sorce[N];
int n,m,T;
int ts,id;//某时刻  某店铺
bool st[N];
int main()
{
    cin>>n>>m>>T;
    for(int i = 0;i<m;i++)
    {
        scanf("%d %d",&ts,&id);
        order[ts][id]++;
    }
    

    //穷举 每一个时刻 每一个 店铺
    for(int t = 1;t<=T;t++)
    {
        for(int i = 1;i<=n;i++)
        {
            if(order[t][i]) sorce[i] += 2 * order[t][i];//时刻  店铺 
            else sorce[i]--;
            if(sorce[i]<0) sorce[i] = 0;
            if(sorce[i]>5) st[i] = true;
            if(sorce[i]<=3) st[i] = false;
        }
    }
    //穷举 每一个时刻 每一个店铺 得到 某时刻 某店铺 有多少订单  对订单进行计算
    //判断是否在范围内
    //得到 所有优先级的
    int res = 0;
    for(int i = 1;i<=n;i++)
    {
        res += st[i];
    }
    cout<<res<<endl;
    return 0;
}
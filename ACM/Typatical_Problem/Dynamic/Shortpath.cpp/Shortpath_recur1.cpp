#include <iostream>
#include <vector>
const int INF = 0x3f3f3f3f;
using namespace std;
using v1 = vector<int>;
using vv1 = vector<v1>;
v1 cost; //最短距离
vv1 G;   //是否有边
v1 path; //该点的上一个
int vex, edge;
int dfs(int v)
{
    if(cost[v] != INF)
    {
        return cost[v];
    }
    for (int u = 0; u < vex; u++)
    {
        if (G[u][v])
        {
            if (cost[v] > dfs(u) + G[u][v])
            {
                cost[v] = dfs(u) + G[u][v];
            }
        }
    }
    return cost[v]; //到这个点的最短距离
}

int main()
{
    //输入点  边  权重
    //基于点个数  输入 到某个点的最短距离

    cin >> vex >> edge;
    cost = v1(vex, INF); //默认最短距离为无穷大
    path = v1(vex,-1);
    G = vv1(vex,v1(vex,0));//输入边 模板赋值 v1(vex,0)  模板默认就是这样
    for(int i = 0;i<edge;i++)   //输入权重也就是边
    {
        int m,n,w;
        cin>>m>>n>>w;
        G[m][n] = w;    //输入哪两个点 之前的权重
    }
    int bg,ed;//输入起点 终点
    cin>>bg>>ed;//输入起点 终点
    cost[bg] = 0;
    cout<< dfs(ed)<<endl;
    return 0;
}

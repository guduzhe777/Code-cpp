
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vv1 = vector<vi>;

const int INF = 0x3f3f3f3f;
//输入图的点 边数量
//输入某两个边 点的长度
// dfs 获取终点 v 到起点最短距离
//思路 到 v点最短  1.判断j
vv1 G;
vi cost;       //最短距离
vi path;       //该点的最短的上一个顶点为：
int vex, edge; //点  边
int dfs(int v) //得到到这个点的最短距离
{
    // if(cost[v] == 0)
    // {
    //     return cost[v];
    // }
    if (cost[v] != INF) // I
    {
        return cost[v];
    }
    for (int i = 0; i < vex; i++)
    {
        if (G[i][v])
        {
            int ret = dfs(i) + G[i][v];
            if (cost[v] > ret)
            {
                cost[v] = ret;
                path[v] = i;
            }
        }
    }
    return cost[v]; //最后返回 终点到前面的最短距离
}
void test0()
{

    cin >> vex >> edge;
    cost = v1(vex, INF); //默认起始点到终点距离无穷大
    path = v1(vex, -1);  //存储该顶点的上一个
    G = vv1(vex, v1(vex));
    cout << "请分别输入 两个顶点之间的权重" << endl;
    for (int i = 0, m, n, w; i < edge; i++)
    {
        cin >> m >> n >> w;
        G[m][n] = w;
    }
    int bg, ed;
    cout << "输入 开始 终点：" << endl;
    cin >> bg >> ed;
    cost[bg] = 0;

    cout << dfs(ed) << endl; //

    for (int i = ed; i != -1; i = path[i])
    {
        if(i == ed|| path[i] == -1)
        {
            cout << i;
        }else{
            cout <<"<-"<< i<<"<-";
        }
       
    }
}
int main()
{
    test0();

    return 0;
}

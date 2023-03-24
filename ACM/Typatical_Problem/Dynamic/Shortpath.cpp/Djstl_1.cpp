#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
int d[N][N];    // d[i][j]  i j两点之间权重
int dis[N];     // dis[i] u 到i之间的距离
bool si[N];     // si[i] i是否加入家庭
int pre[N];     // pre[i] i前面的节点为pre[i]
int Node, Edge; //节点，边
char ch[] = {'u', 'a', 'b', 'c', 'd', 'v'};
int maxdist = 9999;

void Dijkstra(int n, int v)
{
    //用边 初始化pre，dist
    for (int i = 0; i < n; i++)
    {
        dis[i] = d[v][i];     // v与i距离
        if (dis[i] < maxdist) //有边 设置前置
        {
            pre[i] = v;
        }else{
            pre[i] = -1;//v i无边  前置为-1
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int temp = maxdist;         //默认最大
        int best;                   //保存前置
        for (int j = 0; j < n; j++) //对表找出非家庭的 最小 保存 最小距离与该点 放入家庭
        {
            if(!si[j]&&dis[j]<temp) //
            {
                temp = dis[j];
                best = j;
            }
        }
        si[best] = true;//保存 最小点 放入家庭
        for(int j = 0;j<n;j++)
        {
            int newmaxdist = dis[best] + d[best][j];//接近每一个 不是家庭中的点
            if(!si[j]&&newmaxdist<dis[j])
            {
                pre[j] = best;
                dis[j] = newmaxdist;//v到j距离 更新最短
            }
        }
    }
}
void print_Path(int v,int x)//pre[x] 保存x 前置点
{
    vector<int> temp;
    temp.push_back(x);
    while(x != v)
    {
        x = pre[x];
        temp.push_back(x);
    }
    
    for(vector<int>::iterator it = temp.end()-1;it != temp.begin()-1;it--)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
int main()
{
    cin >> Node >> Edge;           //输入点 边 个数
    //fill(d, d+N, maxdist); //默认全部无边
    for (int i = 0; i < Node;i++)//只对于用到的节点 全部无边即可
    {
        for (int j = 0; j < Node; j++)
            d[i][j] = maxdist;
    }
    for (int i = 0; i < Edge; i++)
    {
        int x, y;
        cin >> x >> y;
        cin >> d[x][y]; //有向边
    }
    Dijkstra(Node, 0); //查找 以 0为起点 最短距离
    cout<<dis[Node-1]<<endl;//输出v 到 n-1 最短距离
    print_Path(0,Node - 1);//打印 Node - 1 到 起点v的过程。
    return 0;
}
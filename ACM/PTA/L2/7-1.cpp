//多权的的迪杰斯特拉
//权重不仅仅是路径权重还有收费情况
#include <bits/stdc++.h>

using namespace std;
const int N = 510;
int d[N][N], m[N][N]; //距离 金钱
int dis[N], mm[N];    // dis[i] ,u 到 i暂时 最短距离 u i 暂时最少花费
int pre[N];           // pre[i] i的前一个点()
bool si[N];           //这个点是否融入大家庭
int n0, m0, s0, d0;     //
int maxdist = 9999;
void Djstl(int n, int v) //点个数 起点
{
    for (int i = 0; i < n; i++) //初始化 dis
    {
        dis[i] = d[v][i];//dis初始化
        if (d[v][i] < maxdist)
        {
            pre[i] = v;
            mm[i] = m[v][i]; //最小花费
        }
        else
        {
            pre[i] = -1; //无边
        }
    }
    si[v] = 1; //进入家庭
    //寻找最小
    for (int k = 2; k <= n; k++)//k-1次迭代接近
    {
        int best, temp = maxdist;
        for (int j = 0; j < n; j++)
        {
            if (!si[j]&&dis[j] < temp)
            {
                best = j;
                temp = dis[j]; //最小
            }
        }
        si[best] = 1; //最小进入家庭 等待接近
        for (int j = 0; j < n; j++)
        {
            if (!si[j] && d[best][j] < maxdist) //有边
            {
                int newdis = dis[best] + d[best][j];
                if (newdis < dis[j])
                {
                     pre[j] = best;
                    dis[j] = newdis;               //接近后 更新最小值
                    mm[j] = mm[best] + m[best][j]; //
                }
                else if (newdis == dis[j]) //距离相等情况
                {
                    int newcost = mm[best] + m[best][j];
                    if (newcost < mm[j])
                    {
                                        //如果二者距离相同 然后 我新来的 花费小
                                        //距离更新为新来的， 花费更新为新来的
                        pre[j] = best;// 凡是小于或者等于 那么我这个点上一个改成best即可
                        mm[j] = newcost;
                    }
                }
            }
        }
    }
}
//dis[i] u 到i最短距离
//mm[i]  u 到j最少花费
void print_Path(int u,int v)
{
    vector<int> temp;
    
    while(v != u)
    {
        temp.push_back(v);
        v = pre[v];
    }
    temp.push_back(v);
    for(vector<int>::iterator it = temp.end()-1; it != temp.begin()-1;it--)
    {
        cout<<(*it)<<" ";
    } 
}
int main()
{
    //初始化 无边的 max，
    //寻找初始化的最短路径
    //放入家庭
    //用最短点 去 接近 其他点 ， 与原本的u最短路径比较
    cin >> n0 >> m0 >> s0 >> d0;  //点，边，出发 终点
    for (int i = 0; i < n0; i++) //初始化图
    {
        for (int j = 0; j < n0; j++)
        {
            d[i][j] = maxdist;
            m[i][j] = maxdist;
        }
    }
    for (int i = 0; i < m0; i++) //边初始化
    {
        int x, y;
        cin >> x >> y >> d[x][y] >> m[x][y];
        d[y][x] = d[x][y];
        m[y][x] = m[x][y];//双向
    }

    Djstl(n0, s0);
    cout<<dis[d0]<<" "<<mm[d0]<<endl;
    print_Path(s0,d0);
    return 0;
}
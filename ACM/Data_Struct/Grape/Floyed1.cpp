#include <bits/stdc++.h>

using namespace std;

int dist[50][50];
int pass[50][50]; // b[i][j] = k : i j通过k连接
int n, v;
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pass[i][j] = k;
                }
}
void print(int i, int j)
{
    if (i == j)
        return;
        if( pass[i][j] == 0) return;
        print(i, pass[i][j]);//输出中间点  直到  二者之间相连 
        cout<<pass[i][j]<<" ";
        
        return;
}

int main()
{
    //一顿初始化，输入数据
    
    cin >> n >> v;
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    for (int i = 0; i < v; i++)
    {
        int x, y, len;
        cin >> x >> y >> len;
        dist[x][y] = dist[y][x] = len;
    }
    floyd();
    print(1, n); //输出从1到n的最短路径中的所有点（边）

    return 0;
}

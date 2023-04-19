#include <bits/stdc++.h>

using namespace std;

int f[50][50];
int b[50][50]; // b[i][j] = k : i j通过k连接

void print(int i, int j)
{
    if(i == j) return;
    if (b[i][j] == 0)   //直接相连
        cout << i << " " << j;
    else
    {
        print(i, b[i][j]);
        print(b[i][j], j);
    }
}
int main()
{
    int n, v;
    cin >> n >> v;
    memset(f, 0x3f3f3f3f, sizeof(f));
    for (int i = 0; i < v; i++)
    {
        int x, y, len;
        cin >> x >> y >> len;
        f[x][y] = f[y][x] = len;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (f[i][j] > f[i][k] + f[k][j])
                {
                    f[i][j] = f[i][k] + f[k][j];
                    b[i][j] = k;
                }
            }
        }
    }
    //求连接过程
    // b[i][j] = k i j经过k  b[i,k]  =  k1 经过 k1  b[k,j] = m1经过m1
    print(1,n);
    return 0;
}
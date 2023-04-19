#include <bits/stdc++.h>

using namespace std;

const int N = 510;
int f[N][N];

int v, e, k;

int color[N];  //记录点颜色
bool si[N][N]; //遍历标记
bool bfs()
{
    memset(si, 0, sizeof(si));
    for (int i = 1; i <= v; i++)
    {
        for (int j = i; j <= v; j++)
        {
            if (!si[i][j] && (f[i][j] || f[j][i]))
            {
                if ((color[i] == color[j]))
                {
                    return false;
                }
                else
                {
                    si[i][j] = si[j][i] = 1;
                }
            }
        }
    }
    return true;
}
int main()
{
    cin >> v >> e >> k;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        f[x][y] = 1;
    }
    int n;
    cin >> n;
    set<int> colors;
    while (n--)
    {
        colors.clear();
        for (int i = 1; i <= v; i++)
        {
            int a;
            cin >> a;
            color[i] = a;
            colors.insert(a);
        }
        if (colors.size() != k)
        {
            printf("No\n");
            continue;
        }
        else
        {
            bool si0 = true; //默认不同
            if (!bfs())
            {
                si0 = false;
                printf("No\n");
                break;
            }

            if (si0)
            {
                printf("Yes\n");
            }
        }
    }

    return 0;
}
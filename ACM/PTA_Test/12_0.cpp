#include <bits/stdc++.h>

using namespace std;

int n; //总人数
const int N = 510;
int f[N][N];    //记录距离感
bool gender[N]; // =  1 为男性
int main()
{
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                f[i][j] = 0;
            }
            else
            {
                f[i][j] = 1e9;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'F')
        {
            //女性
            gender[i] = 0;
        }
        else
        {
            gender[i] = 1;
        }
        int k;
        cin >> k;
        while (k--)
        {
            int y, dis;
            scanf("%d:%d", &y, &dis);
            f[i][y] = dis; // i对y距离感
        }
    }
    //更新 距离
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (f[i][j] > f[i][k] + f[k][j]) //自以为的距离感
                {
                    f[i][j] = f[i][k] + f[k][j];
                }
            }
    //得到距离感
    // f[i][j] = s  男 女 中的 最大距离
    int max_m[N] = {0}, max_f[N] = {0}; //每个男/女人最大距离
    int m_min = 0x3f3f3f3f, f_min = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) // j对i的距离
        {
            if (gender[i] && gender[j] != gender[i])
            {
                max_m[i] = max(max_m[i], f[j][i]);
            }
            else if (!gender[i] && gender[j] != gender[i])
            {
                max_f[i] = max(max_f[i], f[j][i]);
            }
        }
    }
    //得到
    for (int i = 1; i <= n; i++)
    {
        if (gender[i])
        {
            m_min = min(m_min, max_m[i]);
        }
        else
        {
            f_min = min(f_min, max_f[i]);
        }
    }
    bool first = true;
    for (int i = 1; i <= n; i++)
    {
        if (!gender[i])
        {
            if (f_min == max_f[i])
            {
                if (first)
                {
                    first = false;
                    printf("%d", i);
                }
                else
                {
                    printf(" %d", i);
                }
            }
        }
    }

    printf("\n");
    first = true;
    for (int i = 1; i <= n; i++)
    {
        if (gender[i])
        {
            if (m_min == max_m[i])
            {
                if (first)
                {
                    first = false;
                    printf("%d", i);
                }
                else
                {
                    printf(" %d", i);
                }
            }
        }
    }
    return 0;
}
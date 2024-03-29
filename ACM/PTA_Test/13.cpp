#include <bits/stdc++.h>

using namespace std;
const int N = 510, INF = 0x3f3f3f3f;

int f[N][N];

bool gender[N]; //记录男女
///全体变量 初始化：为0，切记 若是 局部变量 不一定是0
// i对j 的关系 为 通过k计算

// floyed 更新 每个人之间最小距离感

// 但是

// 求的是i的吸引力：为 j 对 i的好感 而不是 i 对j的好感

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                f[i][j] = 0;
            else
                f[i][j] = 1e9;

    for (int i = 1; i <= n; i++)
    {
        char ch;
        int k;
        cin >> ch >> k;
        if (ch == 'F')
        {
            gender[i] = 0; //女
        }
        else
        {
            gender[i] = 1;
        }
        for (int j = 0; j < k; j++)
        {
            int x, len;
            scanf("%d:%d", &x, &len);
            f[i][x] = len;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
            }
        }
    }

    int max_m[N] = {0};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (gender[i] != gender[j])
            {
                max_m[i] = max(f[j][i], max_m[i]);
            }
        }
    }
    int min_m = INF, min_f = INF;
    for (int i = 1; i <= n; i++)
    {
        if (gender[i])
        {
            min_m = min(min_m, max_m[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!gender[i])
        {
            min_f = min(min_f, max_m[i]);
        }
    }
    bool fir = true;
    
    for (int i = 1; i <= n; i++)
    {
        if (!gender[i] && max_m[i] == min_f)
        {
            if (fir)
            {
                fir = false;
                printf("%d", i);
            }
            else
            {
                printf(" %d", i);
            }

            
        }
    }
    
    fir = true;
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        if (gender[i] && max_m[i] == min_m)
        {
            if (fir)
            {
                fir = false;
                printf("%d", i);
            }
            else
            {
                printf(" %d", i);
            }
        }
    }
    return 0;
}
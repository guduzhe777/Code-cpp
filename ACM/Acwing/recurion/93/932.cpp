#include <bits/stdc++.h>

using namespace std;

int n, m;
const int N = 100010;
int f[N];            //等待被放
bool b[N] = {false}; //标记数字是否被放进去
void dfs(int x, int k)
{
    if (x > m)
    {
        for (int i = 1; i <= m; i++)
        {
            cout << f[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = k; i <= n; i++)
    {
        if (!b[i])
        {
            f[x] = i;
            b[i] = true;
            dfs(x + 1, i + 1);
            b[i] = false; //不放i了
        }
        else
        {
            continue;
        }
    }
}
int main()
{
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}
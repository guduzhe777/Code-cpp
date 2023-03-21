#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int f[N];
int q, k;
int n;
bool checksl(int mid)
{
    if (f[mid] >= k)
        return true;
    else
        return false;
}
bool checksr(int mid)
{
    if (f[mid] <= k)
        return true;
    else
        return false;
}
int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &f[i]);
    while (q--)
    {
        scanf("%d", &k);
        int l = -1, r = n;
        while (l + 1 != r)
        {
            int mid = (r - l) / 2 + l;
            if (checksl(mid))
                r = mid;
            else
                l = mid;
        }
        if (f[r] != k)
        {
            printf("-1 -1\n");
            continue;
        }
        else
            printf("%d ", r);
        l = -1;
        r = n; //需要更新
        while (l + 1 != r)
        {
            int mid = (r - l) / 2 + l;
            if (checksr(mid))
                l = mid;
            else
                r = mid;
        }
            printf("%d\n", l);
    }

    return 0;
}
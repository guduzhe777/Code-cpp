#include <bits/stdc++.h>

using namespace std;

int x, y, z;
int sum;
int main()
{
    cin >> sum;
    int cnt = 0;
    for (x = 1; 5 * x <= sum; x++)
    {
        for (y = 1; 5 * x + 2 * y <= sum; y++)
        {
            z = sum - 5 * x - 2 * y;
            if (z)
            {
                int total = x + y + z;
                printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", x, y, z, total);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
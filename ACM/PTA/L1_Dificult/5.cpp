#include <bits/stdc++.h>

using namespace std;
int x[4], y[4];
int main()
{
    int x0, y0;

    while (cin >> x0 >> y0)
    {
        bool sign = false;//默认不可以
        for (int i = 1; i < 4; i++)
        {
            cin >> x[i] >> y[i];
            x[i] += x[i - 1];
            y[i] += y[i - 1];
        }
        for(int i = 0;i<4;i++)
        {
            for(int j = i + 1;j<4;j++)
            {
                int sum_x = x[j] - x[i];
                int sum_y = y[j] - y[i];
                if(sum_x == x0&&sum_y == y0)
                {
                    printf("YES\n");
                    sign = true;
                    
                }
            }
        }
        if(!sign)
        {
            printf("NO\n");
        }
    }
    return 0;
}
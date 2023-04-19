#include <bits/stdc++.h>

using namespace std;
bool si[7][7];
int main()
{
    for (int i = 1; i <= 6; i++)
    {
        int x;
        cin >> x;
        si[i][x] = 1;
    }
    int n;
    cin >> n;
    while (n--)
    {
        bool fir = true;
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 6; j > 0; j--)
            {
                if (!si[i][j])
                {
                    si[i][j] = true;
                    if (!n)
                    {
                        if (fir)
                        {
                            fir = false;
                            printf("%d", j);
                        }
                        else
                        {
                            printf(" %d", j);
                        }
                        
                    }
                    break;
                }
            }
        }
    }

    return 0;
}
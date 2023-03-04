#include <bits/stdc++.h>

using namespace std;
//不要那么复杂 全部遍历一遍不就好了
const int N = 21;
int n;
bool sign = false;
int cnt;
int k;
char f[N][N];
int main()
{
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> f[i][j];
            
        }
        getchar();//输入完一行

    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j + 4 < N) //横着
            {
                for (k = 0; k <= 4; k++)
                {
                    if (f[i][j + k] != '*')
                    {

                        break;
                    }
                }
                if (k == 5) //最后一个也是
                {
                    cout << "Win " << i << " " << j;
                    return 0;
                }
            }
            if (i + 4 < N) //横着
            {
                for (k = 0; k <= 4; k++)
                {
                    if (f[i + k][j] != '*')
                    {

                        break;
                    }
                }
                if (k == 5) //最后一个也是
                {
                    cout << "Win " << i << " " << j;
                    return 0;
                }
            }

            if ((j + 4 < N) && (i + 4 < N)) // i+ j+ 斜着
            {
                for (k = 0; k <= 4; k++)
                {
                    if (f[i + k][j + k] != '*')
                    {

                        break;
                    }
                }
                if (k == 5) //最后一个也是
                {
                    cout << "Win " << i << " " << j;
                    return 0;
                }
            }
            if ((j + 4 < N) && (i - 4 >= 0)) // i- j+
            {
                for (k = 0; k <= 4; k++)
                {
                    if (f[i - k][j + k] != '*')
                    {

                        break;
                    }
                }
                if (k == 5) //最后一个也是
                {
                    cout << "Win " << j << " " << i;//先横坐标 就是 j
                    return 0;
                }
            }
        }
    }
        cout << "Not yet" << endl;
        return 0;
    }
#include <iostream>

using namespace std;

void test0()
{
    int m, n, i, j, k;    //有价格  数量 求每一个的数量 5 * i + 3 * j + 1/3 * k = m;
    while (cin >> m >> n) // 15 * i + 9 * j + 1 * k = 3 * m;
    {
        // max 公鸡m/5 母鸡m/3 小鸡1元三只？ 1  基于关系式 暴力 然后 验证另一个条件
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n - i; j++)
            {
                k = n - j - i;
                if (15 * i + 9 * j + 1 * k == 3 * m)
                {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
}
int main()
{

    test0(); //鸡兔同笼

    return 0;
}

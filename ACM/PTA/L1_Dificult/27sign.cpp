#include <bits/stdc++.h>

using namespace std;
long long n;
bool prime(long long n) //偶数因子  奇数因子 判断一个数字
{
    if (n == 1 || n % 2 == 0 && n != 2)
        return 0;
    else
    {
        for (int i = 3; i <= (int)sqrt(n); i += 2)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
const int N = 1e8;
bool si[N];
void prime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!si[i])
        {
            for (int j = 2 * i; j <= n; j += i) //区间筛
            {
                si[j] = true;
            }
        }
    }
}
int main()
{
    cin >> n;

    for (long long i = 2; i <= n / 2; i++)
    {
        if (prime(i) && prime(n - i))
        {
            printf("%ld = %ld + %ld\n", n, i, n - i);
            return 0;
        }
    }

    return 0;
}
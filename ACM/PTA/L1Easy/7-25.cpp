#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n;
int ans, sum;
bool sign[N]; //默认全是素数  更新合数

int main()
{
    cin >> n;
    memset(sign, 1, n * sizeof(bool));
    sign[1] = false;
    sign[0] = false;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            sign[j] = false; //合数赋值false
        }
    }
    for (int i = n; i >= 2; i--)
    {
        if (sign[i])
        {
            ans++;
            sum += i;
            cout << i<<" ";
        }
        if (ans == 10)
        {
            break;
        }
    }
    printf("\nsum = %d", sum);
    return 0;
}
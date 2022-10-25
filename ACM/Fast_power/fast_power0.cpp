#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
class solution
{
public:
    ll fast_power(ll a, ll b)
    {
        int mul = 1;
        while (b)
        {
            if (b & 1)
            {
                mul *= a;
            }
            b = b >> 1;
            a = a * a;
        }
        return mul;
    }
    ll fast_mul(ll a, ll b, ll m)
    {
        int res = 0;
        while (b)
        {
            if (b & 1)
            {
                res = res % m + a % m;
            }
            b = b >> 1;
            a = a % m + a % m;
        }
        return res;
    }
};

int main()
{
    int n, k;
    solution s;
    cin >> n;
    int arr[n][n], tem[n][n],rest[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            tem[i][j] = arr[i][j];
        }
    }

    //计算 矩阵乘法
    //取模？保存再取模？ 错了
    //根本保存不了 所以 取模每次计算后取模 输出
    //计算 矩阵乘法 快速乘法
    //每次计算进行取模输出操作
    //快速幂计算 10 9 快速乘法计算 Aij
    //计算a ^ k 保存在arr之中
    int i = 0,j = 0;
    ll ret_matix = 0,ret_pow;
    ret_pow = s.fast_power(10,9) + 7;
    while(i<n)
    {
        while(j<n)
        {
            for(int t = 0;t<n;t++)
            {
                // ret_matix = s.fast_mul(arr[i][t],tem[t][j],ret_pow);
                ret_matix += arr[i][t] * tem[t][j];
            }
            rest[i][j] =ret_matix;
            ret_matix = 0;    
            ++j;
        }
        j = 0;
        ++i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<rest[i][j]<<" ";
        }
    }
    return 0;
}

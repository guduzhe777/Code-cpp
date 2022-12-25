#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll res[3][3]; //接受A^n
const ll mod = 114514;
using vi = vector<ll>;
using matrix = vector<vi>;
matrix operator*(matrix &A, matrix &B) //重载运算符
{
    matrix C(3, vi(3, 0));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            for (int k = 0; k < A.size(); k++)
            {
                C[i][j] += (A[i][k]* B[k][j]);  //乘法前没有溢出 每次乘法后 可能会溢出
                
            }
            C[i][j] = C[i][j] % mod;
        }
    }
    return C;
}
//先模与后模 对于加减乘除都是不变的
matrix qucik_pow(matrix &A, ll n) //次数 和 矩阵
{
    matrix B(3, vi(3, 0));
    for (ll i = 0; i < B.size(); i++)
    {
        B[i][i] = 1;
    }
    while (n)
    {

        if (n & 1)
        {
            B = A * B;  //矩阵乘法不会出现 溢出现象  
            // B[0][0] = B[0][0] %  mod;//每一次都对 求出来的fn取模 but每次乘法的时候矩阵中的值我都会用到 
        }
        n = n >> 1;
        A = A * A;
    }
    return B;
}
int main()
{
    // ll n;
    // cin >> n;

    // ll arr[1001];
    // arr[0] = 0;
    // arr[1] = 1;
    // arr[2] = 2;
    // arr[3] = 4;
    // for (ll i = 4; i <= n; i++)
    // {
    //     arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    // }

    // prllf("%d",arr[n]);

    //矩阵解方程 ：
    //
    
    ll n;
    cin >> n;

    matrix fn(3, vi(1, 0));
    matrix A(3, vi(3, 0));
    matrix fn0;
    A = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    fn = {{4}, {2}, {1}};
    if (n == 0)
    {
        return cout << 0, 0;
    }
    if (n < 4)
        return cout << fn[3 - n][0], 0;
    matrix ret = qucik_pow(A, n - 3);

    matrix answer = ret * fn;
    cout << answer[0][0];

    return 0;
}

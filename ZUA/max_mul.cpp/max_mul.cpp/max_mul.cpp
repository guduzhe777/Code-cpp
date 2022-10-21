#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int max(int x, int y, int z)
{
    if ((x >= y) && (x >= z))
    {
        return x > 0 ? x : 0;
    }
    if ((y >= x) && (y >= z))
    {
        return y > 0 ? y : 0;
    }

    return z > 0 ? z : 0;
}
void test0()
{
    int arr[18];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n); //加n排序 n-1 个 第n个为开区间
    cout << max(arr[0] * arr[1] * arr[2], arr[0] * arr[1] * arr[n - 1], arr[n - 1] * arr[n - 2] * arr[n - 3]);
}

//找出一个乘积最大的连续子序列
void test1()
{
    //双指针求连续最大值
    int arr[18];
    int n,mul = 1,max_mul = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0;i<n;i++)
    {
        mul = 1;//每次新序列开始 换一个头部
        for(int j = i;j<n;j++)
        {
            mul *= arr[j];
            max_mul = max(max_mul,mul);
        }

    }
    cout <<max_mul;
}
int main()
{   
    test1();

    return 0;
}

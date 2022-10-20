#include <iostream>
#include <cmath>

using namespace std;
void test0()
{
    int n, tem, arr[10], j, sign, me = 0, tem1; // me:始终没有一个
    while (cin >> n)
    {
        for (int i = 12345; i <= 98765; i++) //!如果循环之中改变i i会永远被改变 所以你产生的i不能被改变需要循环使用必须用个替代的
        {
            int x = i;
            tem = x / n; //求的另一个值   可能为分数
            //放进同一个数组之中
            tem1 = tem;
            sign = 1;         //假设这组数字没毛病啊
            if (x % tem == 0) ///可能为分数 那么我不能让她过去
            {
                for (j = 0; j <= 4; j++) //保存到数组中
                {
                    arr[j] = tem % 10;
                    tem /= 10;
                }
            }
            else
            {
                continue;
            }
            for (j = 9; j >= 5; j--)
            {
                arr[j] = x % 10;
                x /= 10;
            }
            //判断每一个元素不相等  那么就输出
            for (int k = 0; k < 10; k++)
            {
                for (int t = k + 1; t < 10; t++)
                {
                    if (arr[t] == arr[k])
                    {
                        sign = 0; //说明存在相等  那么这一组不行 开新的
                        break;
                    }
                }
            }
            if (sign) //全不相等那么输出  不然不输出
            {
                me = 1;
                for (int s = 5; s < 10; s++)
                {
                    cout << arr[s];
                }
                cout << " / ";
                for (int m = 4; m >= 0; m--)
                {
                    cout << arr[m];
                }
                cout << " = " << n << endl;
            }
        }
        if (!me)
        {
            cout << "no answer";
        }
    }
}
int dis(long long arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] == arr[j]) //凡是有相等
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    long long arr[9];
    long long i;
    for (i = 123456789; i <= 130000000; i++)
    {
        long long x = i;
        int j = 0;
        while (x / 10)
        {
            arr[j] = x % 10;
            x /= 10;
            j++;
        }
        arr[j] = x;

        //产生数字放进数组
        if (dis(arr, 9)) //如果每一个都不相等
        {
            for (int k = 8; k >= 0; k--)
            {
                printf("%d", arr[k]);
            }
            printf("\n");
        }
    }
    return 0;
}

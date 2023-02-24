#include <bits/stdc++.h>

using namespace std;

//不同于指数枚举 放/不放
//排列型 可以放许多数字 所以必定需要存储
//
int n;
const int N = 11;
int f[N];            //保存序列
bool w[N] = {false}; //保存数字被用状态
void obs(int x)
{
    if (x > n) //位置全部放完
    {
        for (int j = 1; j <= n; j++)
        {

            cout << f[j] << " ";
        }
        cout << endl;
        return;
    }
    //输出 输出完 返回到上一层
    for (int i = 1; i <= n; i++)
    {
        if (w[i]) // i被使用
        {
            continue;//换个新i
        }
        f[x] = i;
        w[i] = true;
        obs(x + 1);
        w[i] = false; //用完了 不再使用
    }
}
int main()
{
    cin >> n;
    obs(1);

    return 0;
}
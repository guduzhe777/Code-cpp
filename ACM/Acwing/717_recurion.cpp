#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 51;
using ll = long long;
ll f[N] = {0}; //记录求得
// dp 记录 从前到后求
//  void obs(int x)//计算下标x  数值
//  {

//     if(x>n)
//     {
//         for(int i = 0;i<n;i++)
//         {
//             cout<<f[i]<<" ";
//         }
//         return;
//     }
//     f[x] = f[x-1] + f[x-2];
//     obs(x+1);

// }
void obs(int x)
{
}
ll a = 0, b = 1, c;
int main()
{
    // f[1] = 1;
    // f[2] = 1;

    // cin>>n;

    //不开数组
    //分为保存前两个  计算后一个  然后向后挪！
    cin>>n;

    while (n--) 
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}
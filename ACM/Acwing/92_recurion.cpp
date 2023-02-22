//递归才是真正的基础
//模拟所有 不符合条件的给我拒绝
//拒绝形式有许多种比如方案题  方案数返回0
//等等
#include <bits/stdc++.h>

using namespace std;
int n;
// void obs(int a)
// {

//     if (a == 0) return;
     

//     obs(a - 1);
// //     if(a == n)
// //     {
// //         cout<<a;
// //     }
// //     else{
// //         cout<<a<<" ";
// //     }
// // if(a == 1)
// // {
// //     cout<<a;
// // }
// // else{
// //     cout<<" "<<a;
// // }
// }
bool b_arr[16];


void abss(int x)
{
    // if(x>=n)     //如果等于 是输入第二层进入 第三层选不选你还没有决定！
    if(x>n)
    {
        for(int i = 1;i<=n;i++)
        {
            if(b_arr[i])
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
        return;
    }

    b_arr[x] = true;
    abss(x+1);

    b_arr[x] = false;
    abss(x+1);
}
int main()
{
    cin >> n;

    //obs(n);
    abss(1);
    return 0;
}
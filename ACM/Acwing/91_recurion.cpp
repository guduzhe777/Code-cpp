#include <bits/stdc++.h>

using namespace std;
int m, n;
const int N = 100010;
using ll = long long;

ll w[N];    //存储被选择的数字
bool f[N] = {false};  //记录第i个是否选择
// void obs(int x)//确定此位置  进入下一个位置
// {
//     if (x > m) 
//     {
//         for (int i = 1; i <= m; i++)
//         {
//             cout<<w[i]<<" ";
//         }
//         cout<<endl;
//         return;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if(f[i]) continue; //第i个被选了  换下一个数字

//         w[x] = i;
//         f[i] = true;
//         obs(x + 1);
//         f[i] = false;//没被选  而是选择  i + 1了
        
//     }
// }
//升序：
//进入第几个位置  上一层在哪里开始
void obs(int x,int y)//确定此位置  进入下一个位置
{
    if (x > m) 
    {
        for (int i = 1; i <= m; i++)
        {
            cout<<w[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for (int i = y; i <= n; i++)
    {
        if(f[i]) continue; //第i个被选了  换下一个数字

        w[x] = i;
        f[i] = true;
        obs(x + 1,i);
        f[i] = false;//没被选  而是选择  i + 1了
        
    }
}
int main()
{
    cin >> n >> m;
    obs(1,1); //前进型
    
    return 0;
}
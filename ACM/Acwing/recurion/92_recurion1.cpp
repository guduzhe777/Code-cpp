#include<bits/stdc++.h>

using namespace std;

int n;
const int N = 17;
bool f[17] = {false};

// void obs(int x)
// {
//     if(x>n)
//     {
//         for(int i = 0;i<=n;i++)
//         {
//             if(f[i])//输出被选的数字
//             {
//                 cout<<i<<" ";
//             }
//         }
//         cout<<endl;
//         return;//输出完了 返回  返回等待 下一次全部选完
//     }
//     f[x] = true;//决定不选
//     if(f[x])
//     {
//         obs(x+1);//下一个 
//     }
    
    
//     //返回来
//     f[x] = false;//决定不选
//     if(!f[x])
//     {
//         obs(x+1);
//     }
// }
void obs(int x)
{
    if(x>n)
    {
        for(int i = 0;i<=n;i++)
        {
            if(f[i])
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
        return;
    }
    f[x] = false;
    obs(x+1);

    f[x] = true;
    obs(x+1);
}
int main()
{
    cin>>n;
    obs(1);//数字选与不选 
    return 0;
}
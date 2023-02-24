#include<bits/stdc++.h>

using namespace std;

int n;
bool b_arr[11] = {false};
int  f[11];
//可以 1 1 1  互不约束类型
//
// void abss(int i) //前进前进 向前进 
// {
//     if(i>n)  //当前进到最后一步  全部放完 输出 
//     {
//         for(int k = 1;k<=n;k++)
//         {
//             cout<<f[k]<<" ";
            
//         }
//         cout<<endl;
//         return;
//     }
//     for(int j = 1;j<=n;j++) //产生数字 放进去
//     {
//         f[i] = j;
//         abss(i + 1);

//     }
// }
//约束类型
void abss(int i)
{

    if(i>n)
    {
        for(int k = 1;k<=n;k++)
        {
            cout<<f[k]<<" ";
        }
        //全部填满输出出来即可
        cout<<endl;
        return;
    }
    for(int j = 1;j<=n;j++)
    {
        if(b_arr[j] == true)
        {
            continue;
        }
        f[i] = j;
        b_arr[j] = true; //这个数值被选了
        abss(i + 1);
        b_arr[j] = false;//返回到这一层  应该选下一个数据j + 1 所以 j未被选
    }

}
int main()
{   
    cin>>n;
    abss(1);

    return 0;
}
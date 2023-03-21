#include<bits/stdc++.h>

using namespace std;
int n,q;//长度询问
const int N = 100010;
int arr[N];
int k;//被询问的数字
int main()
{
    cin>>n>>q;
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    // bool sign1 = false;
    // bool sign2 = false;//记录是否找到前置后置位 的k
    // while(q--)
    // {
    //     sign1 = false;
    //     sign2 = false;//记录是否找到前置后置位 的k 默认未找到
    //     scanf("%d",&k);
    //     for(int i = 0;i<n;i++)
    //     {
    //         if(arr[i] == k)
    //         {
    //             cout<<i<<" ";
    //             sign1 = true;
    //             for(int j = n-1;j>=i;j--)
    //             {
    //                 if(arr[j] == k)
    //                 {
    //                     cout<<j<<endl;
    //                     sign2 = true;
    //                     break;
    //                 }
    //             }
    //         }
    //         if(sign2)
    //         {
    //             break;
    //         }
    //     }
    //     if(!sign1) cout<<-1<<" "<<-1<<endl; 
    // }
    while(q--)
    {
        
    }
    return 0;
}
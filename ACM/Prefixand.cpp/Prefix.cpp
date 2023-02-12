#include <bits/stdc++.h>

using namespace std;

// int main()           //sb 输入然后计算  。。。。。。
// {
//     int arr[100010] = {0},m,l,r,n,num = 0;
//     cin>>n>>m;
//     for(int i = 1;i<=n;i++)
//     {
//         cin>>arr[i];
//     }

//     while(m--)
//     {
//         cin>>l>>r;
//         for(int j = l;j<=r;j++)
//         {
//             num +=  arr[j];
//         }
//         cout<<num<<endl;
//         num = 0;

//     }
//     return 0;
// }
int main()
{
    int arr[100010] = {0}, m, l, r, n, num = 0, x;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        arr[i] = x + arr[i - 1]; 
    }
    while (m--)
    {
        cin >> l >> r;
        cout << arr[r] - arr[l - 1] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
const int N = 101;
int f[N];
int n, target;
// int Seach(int l, int r, int target) //寻找这个目标
// {
//     //左开右闭
//     while (l < r)
//     {
//         int mid = (l + r) >> 1; //除以2
//         if (f[mid] == target)
//             return mid;
//         if (f[mid] > target)
//             r = mid;
//         if (f[mid] < target)
//             l = mid + 1;
//     }
//     return -1; //未找到
// }
int SL(int l,int r,int x)
{
    while(l + 1!= r)
    {
        int mid = l + r>>1;
        if(f[mid]>=x) r = mid;
        else{
            l = mid;
        }
    }
    return r;
}
int SR(int l,int r,int x)
{
    while(l + 1!= r)
    {
        int mid = l + r>>1;
        if(f[mid]<=x) l = mid;
        else{
            r = mid;
        }
    }
    return l;
}

int main()
{
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
            scanf("%d", &f[i]);
    while (q--)
    {
        int target;
        cin>>target;
        
        int l = SL(-1, n, target);
        int r = SR(-1,n,target);
        if(f[l] != target) cout<<"-1 "<<"-1"<<endl;
        else{
            cout<<l<<" "<<r<<endl;
        }

    }
    return 0;
}
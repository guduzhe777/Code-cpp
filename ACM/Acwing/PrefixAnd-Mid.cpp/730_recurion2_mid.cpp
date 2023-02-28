#include<bits/stdc++.h>

using namespace std;
const int N = 100010;
int l,r;
int n;
int f[N];
bool check(int mid)//检测 大于等于 带入恒大于0 true
{
   for(int i = 1;i<=n;i++)
   {
        mid = 2 * mid  - f[i];
        if(mid >1e5)
        {
            return true;
        }
        // if(mid<0||(mid == 0&&n != 1)) //对于 1 4 E = 2 可以越过去
        // {
        //     return false;
        // }
        if(mid<0)
        {
            return false;//他只处理 这一蹭小于0 如果等于0情况等待下一次来处理！ 防止1 4 2这类情况  也保证了 当时情况当时处理
        }
        
   } 
   return true;//若一直不小于0  那么可以成立
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&f[i]);
    }
    r = 1e5+1;
    l = -1;
    int mid = (r - l)/2 + l;
    while(l + 1!= r)//二分查找 中间值
    {
        mid = (r - l)/2 + l;
        if(check(mid)) r = mid;
        else l = mid;

    }
    printf("%d",r);
    return 0;
}
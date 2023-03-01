#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 10;
int arr[N];
int back[N];
int ans = 0;
int n;
int *arrptr[N];
bool cmp_Ptr(const int *a, const int *b)
{
    return (*a) < (*b);
}
// int**
bool obs(int a, int b)
{
    return ((a) + 1 == (b));
}
bool cmp_int(int a,int b)
{
    return a<b;
}
bool sign = true;//记录 是否一直是连续
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        
    }
    memcpy(back,arr,(n +1)* sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            
            sort(back + i, back + j+1,cmp_int);
            //对R-L序列进行判断
            if (i == j)
            {
                ans++;
                continue;//若i == j  j++
            }
            for (int k = i; k < j; k++)
            {

                if (!obs(back[k], back[k+1])) //若不是
                {
                    sign = false;//不连续
                    break;
                }
            }
            if(sign) ans++;//连续
            memcpy(back,arr,(n +1)* sizeof(int));//新数组赋值
            sign = true;//默认新序列连续
        }
    }
    printf("%d",ans);
    return 0;
}
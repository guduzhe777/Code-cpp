#include<bits/stdc++.h>


using namespace std;

const int N = 4e5+10;

//单调栈
typedef long long ll;
int stk[N];  // stk[i] = j a[i] 右边 第一个小于a[i] 的下标j

int t;
int n;

ll a[N];   //a[i] = j 前i项前缀和为j
ll b[N]; // b[i] = j 前i项等差前缀和为j

int INF = 1e9;
int main()
{
    scanf("%d",&t);
    for(int cnt = 1;cnt<=t;cnt++)
    {
        scanf("%d",&n);
        for(int i = 1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a[i] = a[i - 1] + x;
            b[i] = b[i - 1] + x * (-i);
        }
        int top = 0;
        ll ans = 0;
        
        a[n + 1] = -INF;


        stk[++top] = n + 1;// 存下标 开始 哨兵下标
        //若这个栈 找不到比ai 小的 那么到了 n + 1即哨兵这里 会把从i到n集合子集全部加起来

        for(int i = n;i>=0;i--)
        {
            while(a[i] <= a[stk[top]]) top--;
            //找到了a[i] > a[j] 找了j
            int j = stk[top];
            stk[++top] = i; //把[i] 加入 为以后 做准备

            ans += b[j - 1] - b[i] + j* (a[j-1] - a[i]);

        }
        printf("Case #%d: %d\n",cnt,ans);
    }


    return 0;
}
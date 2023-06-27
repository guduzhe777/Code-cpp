#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t;
int n;
const int N = 4e5+10;
ll a[N];
ll b[N];
ll stk[N];
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
            a[i] = a[i-1] + x;
            b[i] = b[i-1] + x * (-i);
        }
        int top = 0;
        ll ans = 0;

        a[n + 1] = -INF;//根据比较方式 这里是 a[i] a[stk[top]] 值比较 边界为 向右 最后一个即：n + 1
                        //且右边小于a[i] 所以 -INF才满足条件 即 哨兵最后一个
        
        stk[top] = n + 1; //默认栈中 栈存元素的下标  默认 最后一个元素已经存入 对应下标n + 1
        //sj -  si 是 i + 1 - j 是否为快乐数组 判断 1 开始的快乐数组 则 i 为 0 
        for(int i  = n;i>=0;i--)
        {
            // stk[top] 紧贴ai的元素对应的下标
            //我们比较的是元素 下标直接填进去就行
            //目的：a[i] > a[j] 放入栈思想：a[i] <= [stk[top]]
            while(a[i] <= a[stk[top]]) top--;
            //哨兵一定满足目的/已经找到a[i] > a[j] 
            int j = stk[top];
            ans += b[j - 1] - b[i] + j * (a[j - 1] - a[i]);
            stk[++top] = i;//保证紧贴
        }
        printf("Case #%d: %d\n",cnt,ans);

    }


    return 0;
}
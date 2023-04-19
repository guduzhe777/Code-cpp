#include <bits/stdc++.h>
using namespace std;

int n, m, k;
// n为推送器松针片数量 m小盒子存放松针片最大数量 k一个松枝干上最多插多少松针片
int q[1001], front = 1, rear = 0;
//队列:推送器  fornt:队首 rear:队尾
int s[21], top = 0;
//栈：盒子 top：栈顶
int ans[21], cnt = 0;
// ans：栈，当前松枝干上的松针片

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> q[i];
    //队列队尾设为 n
    rear = n;
    //当盒子或推送器有松针片时继续执行
    while (front <= rear || top)//栈顶 
    {
        //栈：盒子 top：栈顶
        
        //队列:推送器  fornt:队首 rear:队尾
        // cnt 代表当前松枝干（ans）栈顶元素下标
        
        if (!cnt)
        {
            if (top) // 盒子有松针片放到松枝干（ans）栈顶
                ans[++cnt] = s[top--];
            else // 推送器有松针片放到松枝干（ans）栈顶
                ans[++cnt] = q[front++];
        }
        else
        {
            //首先检查当前松枝干（ans）是否插满
            if (cnt == k)
            { // 如果松枝干已满，表示松枝干不能插入了，输出ans，并将cnt（栈顶）置0
                int ok = 0;
                for (int i = 1; i <= cnt; i++)
                {
                    if (ok)
                        printf(" ");
                    ok = 1;
                    printf("%d", ans[i]);
                }
                printf("\n");
                cnt = 0;
                continue;
            }
            if (top && s[top] <= ans[cnt]) // 检查盒子是否不空和顶部松针片是否可以插入
                ans[++cnt] = s[top--];
            else if (front <= rear && q[front] <= ans[cnt]) // 检查推送器是否不空和队首松针片是否可以插入
                ans[++cnt] = q[front++];
            else if (top < m && front <= rear) // 检查盒子是否不满 并且 推送器有松针片
                s[++top] = q[front++];
            else
            { // 如果都不满足，表示松枝干不能插入了，输出ans，并将cnt（栈顶）置0
                //机器为空  || 盒子满了
                int ok = 0;
                for (int i = 1; i <= cnt; i++)
                {
                    if (ok)
                        printf(" ");
                    ok = 1;
                    printf("%d", ans[i]);
                }
                printf("\n");
                cnt = 0;
            }
        }
    }
    // 最后检查松枝干是否不为空
    if (cnt)
    {
        int ok = 0;
        for (int i = 1; i <= cnt; i++)
        {
            if (ok)
                printf(" ");
            ok = 1;
            printf("%d", ans[i]);
        }
        printf("\n");
        cnt = 0;
    }
    return 0;
} // 1
/*
8 3 4
20 25 15 18 20 18 8 5
*/
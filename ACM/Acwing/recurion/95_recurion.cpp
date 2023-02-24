#include <bits/stdc++.h>

using namespace std;

const int N = 6;
char w[N][N];
char back[N][N];
//第一行决定第二行如何  保证 上面一行一定亮
//枚举出所有情况 保证找到最小
//为什么我们 对第一行 指数型枚举 得到所有情况
//因为某一行的情况 影响到了下一行的情况
//我们从第一行出发
//覆盖到了所有情况
int n;
//偏移量 指向 上下左右用于修改
int dp_x[5] = {0,0,0,-1,1};
int dp_y[5] = {1,-1,0,0,0};
void turn(int x,int y)//上下左右 全部改变
{
    for(int i = 0;i<5;i++)
    {
        if(x+dp_x[i]<0||x+dp_x[i]>4||y+dp_y[i]<0||y+dp_y[i]>4) continue;

        w[x+dp_x[i]][y+dp_y[i]] ^= 1;
    }
}
int main()
{
    cin>>n;
   
    int ans = 10; //默认很大等待更新 如果>1输出-1
    int step = 0; //记录操作几次
    //少了原本了 我们是对 修改后的进行判断了！
    while (n--)
    {

        for (int i = 0; i < 5; i++)
            scanf("%s", w[i]);
        //第一行
        //等待修改  保存一下
        memcpy(back,w,sizeof(w));
        for (int i = 0; i < 32; i++) //对第一行的所有操作
        {
            // 1为操作
            step = 0;
            for (int k = 0; k < 5; k++)
            {
                if (i >> k & 1)
                {
                    step++;
                    turn(0, k);
                }
            }

            //第二行乃至以后都被第一行约束
            for (int k = 0; k < 4; k++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (w[k][j] == '0')
                    {
                        step++;
                        turn(k + 1, j);
                    }
                }
            }
            bool dark = false;//最后一行不黑
            for (int i = 0; i < 5; i++) //最后一行 行不行
            {
                if (w[4][i] == '0')
                {
                    dark = true;
                }
            }
            if(!dark) ans = min(step, ans); //最后一行不黑 那么 可以计入次数
            memcpy(w,back,sizeof(w));
        }
         //全部情况列举完
        if(ans > 6) ans = -1;   
        cout<<ans<<endl;
        ans = 10;
        step = 0; //记录操作几次
    }

    return 0;
}
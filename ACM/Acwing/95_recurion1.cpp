#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 6;
char f[N][N];
char back[N][N];
int dp_x[5] = {0, 0, 0, -1, 1};
int dp_y[5] = {1, -1, 0, 0, 0};
void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        if (x + dp_x[i] < 0 || x + dp_x[i] > 4) //越界进行下一个修改
        {
            continue;
        }
        if (y + dp_y[i] < 0 || y + dp_y[i] > 4)
        {
            continue;
        }
        f[x + dp_x[i]][y + dp_y[i]] ^= 1; //上下左右正中间修改
    }
}
int main()
{
    int step = 0;//存储 一一个字符串多个状态下 每个状态需要多少步骤
    int ans = 10;//存储 一个字符串最少需要多少次 所以 在一个字符串中不用改变
    bool dark = false; //默认不黑//存储 每个状态下最后一行是否有黑色 默认没有
    cin>>n;
    
    
    while (n--)
    {

        for (int i = 0; i < 5; i++)
    {
        scanf("%s", &f[i]);
    }
    memcpy(back, f, sizeof(f));
    //记下来初始状态需要来回用
        for (int i = 0; i < 32; i++)
        {
            step = 0;//存储每一个状态需要多少次所以需要改变
            dark = false;
            for (int j = 0; j < 5; j++)
            {
                if (i >> j & 1)
                {
                    step++;
                    turn(0, j); //改变0行 第k个
                }
            }
            for (int k = 0; k < 4; k++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (f[k][j] == '0') //如果一行为 下一行去改变
                    {
                        step++;
                        turn(k+1, j);
                    }
                }
            } //改变完呢？
            
            for (int j = 0; j < 5; j++)
            {
                if (f[4][j] == '0')
                {
                    dark = true; //黑的
                    break;
                }
            }
            if (!dark)
                ans = min(ans, step); //不黑记录需要几步
            //回到初始状态 等待 对第一行新操作
            
            
            memcpy(f, back, sizeof(f));
        }
        if (ans > 6)    ans = -1;
            
        cout << ans << endl;
        step = 0;//搞完之后恢复次数
        ans = 10;
    }
    return 0;
}
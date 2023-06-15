


/*
    AcWing 843. n-皇后问题
    https://www.acwing.com/activity/content/problem/content/906/
*/\

// #include<bits/stdc++.h>

// #define N 21
// using namespace std;

// 行列 对角线 : 建立了一种映射 y - x + n  = b   y x唯一导致b唯一，那么 可以代表该 对角线
//


//dfs：
// int n;


// bool col[N],dg[N],udg[N];
// char g[N][N];//八皇后存储
// void dfs(int y)
// {

//     if(y == n)
//     {
//         for(int i = 0;i<n;i++)
//             puts(g[i]);
//         printf("\n");
//     }
//     for(int i = 0;i<n;i++)
//     {
//         if(!col[i] && !udg[y - i + n] && !dg[y + i])
//         {
//             col[i] = udg[y - i + n] = dg[y + i] = 1;
//             g[y][i] = 'Q';
//             dfs(y+1);
//             //出来了 说明用完了 恢复原本状态
//             g[y][i] = '.';
//             col[i] = udg[y - i + n] = dg[y + i] = 0;
//         }
//     }

// }
// int main()
// {
//     scanf("%d",&n);
//     for(int i = 0;i<n;i++)
//         for(int j = 0 ;j<n;j++)
//             g[i][j] = '.';
//     dfs(0);

//     return 0;
// }


// 指数型判断

//每一个位置 都判断 放与不放
//位置：x：行  y：列  s：皇后位置
//多维 dfs 可以 多个参数表示
//
//
// 


#include<bits/stdc++.h>

#define N 21

using namespace std;


char g[N][N];
bool row[N],col[N],dg[N],udg[N];// row[i] = 1 该行已经放置


int n;

void dfs(int y,int x ,int cnt)
{

    if(x == n) y++,x  = 0;
    if(y == n) 
    {
        if(cnt == n)
        {
            for(int i = 0;i<n;i++)
                puts(g[i]);
            puts("");
        }
        
        return;
    }

    dfs(y,x + 1,cnt);

    if(!row[y] && !col[x] && !dg[y - x + n] && !udg[y + x])
    {
        g[y][x] = 'Q';
        row[y] = col[x] = dg[y-x+n] = udg[y+x] = 1;
        dfs(y,x+1,cnt+1); //出来了 那么 该状态用完了。 恢复 
        g[y][x] = '.';
        row[y] = col[x] = dg[y - x + n] = udg[y+x] = 0;

    }

}
int main()
{
    scanf("%d",&n);
    
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            g[i][j] = '.';
    
    dfs(0,0,0); // 二维度 行 列 皇后个数 : 
                //  为什么这三个参数 因为 我们向 行列放皇后 要确定 行列对角线能不能放 自然 要选择 某 行列 而皇后个数 是作为判断条件
                 // 我们 已经是按照要求放了 如果 满足 n个 那么 输出



    return 0;
}
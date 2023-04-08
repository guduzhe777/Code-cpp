#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 11;
bool dis[11]; // dis[i] = true i点被探索了
int f[N][N];

//递归dfs
// void dfs(int x)
// {
//     printf(" %d",x);
//     for(int i = 0;i<n;i++)
//     {
//         if(f[x][i]&&!dis[i])
//         {
//             dis[i] = true;
//             dfs(i);
//         }
//     }
// }

//栈 dfs
// void dfs(int x)
// {
//     stack<int> st;
//     if (!dis[x])
//     {
//         st.push(x);
//     }
//     while(!st.empty())
//     {
//         int nu = st.top();
//         st.pop();
//         printf(" %d",nu);//处理
//         for(int i = nu + 1;i<n;i++)//探索:未被探索 有 边 为条件
//         {
//             if(f[nu][i]&&!dis[i])
//             {
//                 dis[i] = true;
//                 st.push(i);
//             }
//         }
//     }
// }

//邻接矩阵 队列bfs
// void bfs(int x)
// {
//     //向周围辐射
//     queue<int> qu;
//     if (!dis[x])    //未被探索
//     {
//         qu.push(x); 
//         dis[x] = true;//被探索了
//     }
//     while (!qu.empty())
//     {
//         int nu = qu.front();
//         qu.pop();
//         printf(" %d", nu); //处理
//         for (int i = 0; i < n; i++)
//         {
//             if (f[nu][i] && !dis[i])
//             {
//                 qu.push(i);
//                 dis[i] = true; //被探索
//             }
//         }
//     }
// }

//递归dfs
void dfs(int x)
{

    //同栈 探索处理
    //少了 探索 
    printf(" %d",x);
      for(int i = 0;i<n;i++)
    {
        if(!dis[i]&&f[x][i])
        {
            dis[i] = true;//被探索
            dfs(i);
            
        }
    }
}
//栈版dfs
// void dfs(int x)
// {
//     stack<int> st;
//     st.push(x);
//     dis[x] = true; 
//     while(!st.empty())
//     {
//         int nu = st.top();
//         st.pop();
//         printf(" %d",nu);
//         for(int i = 0;i<n;i++)
//         {
//             if(!dis[i]&&f[nu][i])
//             {
//                 st.push(i);
//                 dis[i] = true;
//             }
//         }
//     }
// } 
//bfs 队列 探索  与 处理
void bfs(int x)
{
    //bfs 
    dis[x] = true;
    queue<int> qu;
    qu.push(x);
    while(!qu.empty())
    {
        int nu = qu.front();
        qu.pop();
        printf(" %d",nu);

        for(int i = 0;i<n;i++)
        {
            if(!dis[i]&&f[i][nu])
            {
                qu.push(i);
                dis[i] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        f[x][y] = 1;
        f[y][x] = 1; //无向边
    }

    for (int i = 0; i < n; i++)
    {
        if (!dis[i])
        {
            printf("{");
            dis[i] = true;
            dfs(i);
            printf(" }\n");
        }
    }
    memset(dis, false, sizeof(dis));
    for (int i = 0; i < n; i++)
    {
        if (!dis[i])
        {
            printf("{");
            bfs(i);
            printf(" }\n");
        }
    }
    return 0;
}
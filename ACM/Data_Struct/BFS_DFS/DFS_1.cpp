#include <bits/stdc++.h>

using namespace std;

//邻接表存储
struct Edge
{
    int u, v;
    Edge *next;
} epool[1010];
struct node
{
    int mark;
    Edge *first;
} npool[1010];
int pos;
// n个点 m个边

// void dfs(int x)
// {
//     if(npool[x].mark == 0)
//     {
//         printf("%d ",x);//未被处理
//         npool[x].mark = 1;
//         Edge* e = npool[x].first;
//         while(e != NULL)
//         {
//             dfs(e->v);
//             e = e->next;
//         }
//     }
// }

void add(int u, int v) //添加边
{
    epool[pos].u = u;
    epool[pos].v = v;

    epool[pos].next = npool[u].first;
    npool[u].first = &epool[pos];
    pos++;
}
stack<int> st;
//queue<int> st;
void DFS(int x) //以栈模拟
{
    
    st.push(x);
    while (!st.empty()) //不空
    {
        int nu = st.top();
       // int nu = st.front();
        st.pop();
        printf("%d ", nu);
        
        Edge *e = npool[nu].first;
        while (e != NULL )
        {
            if(npool[e->v].mark == 0)//如果点未被处理
            {
                npool[e->v].mark = 1; //被处理了
                st.push(e->v);//放入 f中
            }
            e = e->next;//找寻所有点 but 不一定所有点都放进去
        }
    }
}

int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    // dfs(1);       递归写法
    DFS(1);
    return 0;
}
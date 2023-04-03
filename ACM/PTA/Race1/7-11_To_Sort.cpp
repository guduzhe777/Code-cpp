#include <bits/stdc++.h>
#include <stack>
using namespace std;

// Dfs(int u) 从某个点开始 依据 出边  对 终点 dfs  看
//这个点情况 三种可能：
// 1.遍历过了  那么 不用遍历了 到这个点的dfs 再对他的出边们 遍历
// 2.正在遍历  我来的路上有这个点
// 3.未遍历到  我来的路上没有这个点 可以 用这个点继续遍历下去
//邻接表存储图:
struct Edge
{
    int u, v;
    Edge *next;
};
Edge epoor[10010];
struct Node
{
    Edge *first; //第一条出边
    int mark;    // 0未遍历  1正在遍历  2遍历完
};
Node Nodes[10010];
int n, m;  // n个点 m个边
int e_pos; //指向 边内存池 等待放bian
void addEdge(int u, int v)
{
    epoor[e_pos].u = u;
    epoor[e_pos].v = v;
    epoor[e_pos].next = Nodes[u].first; //边的下一个 为u当前第一条出边
    Nodes[u].first = &epoor[e_pos];     //第一条出边为 刚刚输入的这个边
    e_pos++;                            //下一个内存池
}
bool si = true; //是aov网
stack<int> st;
void dfs(int id)
{
    if (Nodes[id].mark == 1)
    {
        si = false;
        return;
    }
    if (Nodes[id].mark == 2)
        return;
    if (Nodes[id].mark == 0) //未访问
    {
        Nodes[id].mark = 1;
        Edge *e = Nodes[id].first;
        while (e != NULL)
        {
            dfs(e->v); //访问终点
            e = e->next;
        }
        //关于id的点全部访问完了 且还没重复
        st.push(id);
        Nodes[id].mark = 2;
    }
}
int main()
{
    cin >> m; 
    for (int i = 1; i <= m; i++)
    {
        int cnt;
        cin>>cnt;
        for(int j = 0;j<cnt;j++)
        {
            int v;// 有关系的任务
            cin>>v;
            addEdge(i, v);
        }
        
    }
    // dfs 遍历节点
    for (int i = 1; i <= m; i++)
    {
        dfs(i); //节点从 1 开始  从 3 开始的话  边 不足无法访问到所有节点
        for (int j = 1; j <= n; j++)
        {
            Nodes[j].mark = 0; //默认全部未遍历
        }
    }
    if(!si)
    {
        printf("g\n");
    }else{
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
    // if (si)
    // {
    //     printf("1");
    // }
    // else
    // {
    //     printf("0");
    // }
    return 0;
}
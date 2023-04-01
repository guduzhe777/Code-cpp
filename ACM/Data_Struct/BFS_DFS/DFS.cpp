#include<bits/stdc++.h>


using namespace std;
//邻接表建图
//DFS f为栈
//BFS f为队列
//DFS递归写法
//邻接表如何建图
//顶点 出边

//边  边存储信息更多：起点 终点 下一条边
struct Edge{
    int u,v;
    Edge* next;//下一条边
};
Edge epool[1001];//边的存储
struct Node{        //只存储第一条边
    Edge* first;//第一条出边
    int mark;//标记 此点是否标记
}npool[1001];
int pos;
//u v之间有边 （边存储 起点 终点 下一条边） 边都在池子中  
//对新边进行头插  新边的下一条边 为 原本出边
//头的出边为新来的边  因为 邻接表进行操作时候  边为指针，而边池都是 内存 所以取地址

// void add(int u,int v)
// {
//     epool[pos].u = u;
//     epool[pos].v = v;

//     epool[pos].next = npool[u].first;
//     npool[u].first = &epool[pos];
// }
void add(int u,int v)
{
    epool[pos].u = u;
    epool[pos].v = v;

    epool[pos].next = npool[u].first;
    npool[u].first = &epool[pos];//池子为内存池
    pos++;//边 放到下一个
}
int n,m;//n个点m条边

void dfs(int x)//邻接表 遍历所有节点
{
    if(npool[x].mark == 0)//未被处理
    {
        printf("%d ",x);
        npool[x].mark = 1;//处理了 
        Edge* e = npool[x].first;
        while(e != NULL)
        {
            dfs(e->v);//深度遍历 遍历下一个点
            e = e->next;//下一条出边
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
    }

    dfs(1);
    return 0;
}
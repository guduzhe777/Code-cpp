#include<bits/stdc++.h>
using namespace std;

//邻接表：
//分别存储边  点
//边的组成
//边的表示：v1 v2 len
//边的 下一个 还为 边  Edge.next
//点的组成：
//点的第一个出边
struct Edge{
    //边
    int u,v,len;//起点终点  长度
    Edge* next;//下一个出边
    //可以添加边的其他元素
}Epoor[10010];//边的内存池 可以放边 省着再创建空间 Epoor[i]  只能说第i条出边 其他不知道 
struct Node{
    int mark;//0:未被遍历  1正在遍历   2遍历完成
    Edge* first;//第一条出边        
      //可以添加点的其他元素
}Nodes[10010];//可以放点 省着再创建空间         Nodes[i]:  第i个顶点  顶点只含自己的第一条出边   继续 指向 第二条出边

int n,m,E_pos;//n 个 点 m 个 边 存放边的位置 
void addEdge(int u,int v,int len)
{
    Epoor[E_pos].u = u;         //边的 起点 终点 边的长度
    Epoor[E_pos].v = v;
    Epoor[E_pos].len = len;
                                //(1->3) ->(1->4)->NULL;邻接表就是这般存储
                                //u = 1; u这个起点 的first 指向 (1->3)
                                //新来的 u = 1,v = 2 那么(1->2) -> (1->3) ->(1->4)->NULL；  
    Epoor[E_pos].next = Nodes[u].first;//新来的边 指向 u的第一条出边 
    Nodes[u].first = &Epoor[E_pos];//自己变成了 第一条出边
    E_pos++;//这块内存池用完了
}
void dfs(int id)//依据一个 起点  + 出边 的终点 遍历完图 是否可以
{
    
    if(Nodes[id].mark == 0)//未处理
    {   
        printf("%d ",id);
        Nodes[id].mark = 1;// 处理了
        Edge* e = Nodes[id].first;//第一个出边
        while(e != NULL)
        {
            dfs(e->v);//遍历 终点
            e = e->next;//下一条出边
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
        int u,v,len;
        cin>>u>>v>>len;
        addEdge(u,v,len);
    }

    //遍历某个点 所有出边

    // Edge *e = Nodes[1].first;
    // printf("%d->%d",e->u,e->v);
    // e = e->next;//下一条边
    dfs(1);
    // while(e != NULL)
    // {
    //     printf("->%d->%d",e->u,e->v);
    //     e = e->next;//下一条边
    // }
    return 0;
}
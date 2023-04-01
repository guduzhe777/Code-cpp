#include<bits/stdc++.h>

using namespace std;



//邻接表建图

struct Edge{
    int u,v;
    Edge* next;
}epool[1010];
struct node{
    int mark;
    Edge* first;
}npool[1010];
int pos;
void add(int u,int v)
{
    epool[pos].u = u;
    epool[pos].v = v;

    epool[pos].next = npool[u].first;
    npool[u].first = &epool[pos];
    pos++;
}
queue<int> f;
void bfs(int x)
{
    f.push(x);
    while(!f.empty())
    {
        int nu = f.front();
        f.pop();
        printf("%d ",nu);//处理

        Edge* e = npool[nu].first;
        while(e != NULL)
        {
            if(npool[e->v].mark == 0)//未被处理
            {
                f.push(e->v);
                npool[e->v].mark = 1;//已经放入过了
            }
            e = e->next;
        }
    }
}
int n,m;

int main()
{
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    bfs(1);
    return 0;
}
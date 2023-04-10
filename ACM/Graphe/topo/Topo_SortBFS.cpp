#include<bits/stdc++.h>


using namespace std;

//邻接表
struct Edge{
    int u,v;
    Edge* next;
}epool[1010];

struct node{
    Edge* first;
    int mark;
}npool[1010];
bool dis[1010];
int n,m;//n个边 m个点
queue<int> f;
bool  si = true;;
void  topo_sort(int x)
{
    
    f.push(x);
    while(!f.empty())
    {
        
        int nu = f.front();
        f.pop();
        if(npool[nu].mark == 1)
        {
            si = false;//找到了正在进行 探索的点
            return;
        }

        npool[nu].mark = 1;//遍历中

        Edge* e = npool[nu].first;
        while(e != NULL)
        {
            if(!dis[nu])//未探索
            {
                f.push(nu);
                dis[nu] = true;///探索了

            }
            
            e = e->next;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {

    }
    return 0;
}
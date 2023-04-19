#include<bits/stdc++.h>

using namespace std;


const int N = 510;

vector<int> G[N];
int colors[N];
int v,e,k;// 顶点 边  颜色

bool si[N];//检测点是否放进去过。

//边少 邻接矩阵 500以内 必定邻接矩阵
//点少 vector 邻接表


bool bfs(int u)
{
    memset(si,0,sizeof(si));
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int father = q.front();
        q.pop();
        si[father] = true;
        for(auto &v:G[father])
        {
            if(colors[v] == colors[father])
            {
                return false;
            }
            if(!si[v])
            {
                q.push(v);
            }
            
        }
    }
    return true;
}
int main()
{
    cin>>v>>e>>k;

    for(int i = 0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
    }
    int n;
    cin>>n;
    set<int> col;//颜色数
    while(n--)
    {
        col.clear();
        for(int i = 1;i<=v;i++)
        {
            int color;
            cin>>color;
            col.insert(color);
            colors[i] = color;
        }
        if(col.size() != k)
        {
            printf("No\n");
        }else {
            bool si1 = true;
            for(int i = 1;i<=v;i++)
            {
                if(!bfs(i))
                {
                    si1 = false;
                    printf("No\n");
                    break;
                }
            }
            if(si1)
                printf("Yes\n");
        }
    }
    return 0;
}
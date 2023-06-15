#include<bits/stdc++.h>

using namespace std;

const int N = 20;
using PII = pair<int,int>;

vector<int> g[N];

int engry[N];
bool si[N]; // si[i] = 1 i 点已被激活
int t;
// PII max_Node,node;
int maxCnt,cnt;
void bfs(int u0)
{
    queue<int> q;
    q.push(u0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        si[u] = 1;
        //node.second++;// 放进去拿出来 时候就说明被点亮
        cnt++;

        int eng = engry[u];
        for(auto &v:g[u])
        {
            if(!si[v]&&eng>engry[v])
            {
                
                q.push(v);
            }
        }
    }
}
int main()
{

    scanf("%d",&t);
    int tem = t;
    while(tem--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&engry[i]);
            g[i].clear();
        }
        for(int i = 1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 1;i<=n;i++)
        {
            //node ={i,0};
            // memset(si,0,sizeof(si));
            // bfs(i);
            // if(node.second>max_Node.second)
            // {
            //     max_Node = node;
            // }
            cnt = 0;
            
            memset(si,0,sizeof(si));
            bfs(i);
            maxCnt = max(maxCnt,cnt);

        }
        //cout<<max_Node.first<<max_Node.second;
        printf("Case #%d: %d\n",t - tem,maxCnt);
        cnt = 0;
        maxCnt = 0;
        
    }



    return 0;
}
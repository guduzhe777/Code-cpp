#include<bits/stdc++.h>


using namespace std;

typedef pair<int,int> node;
const int N = 110;
vector<node> G[N];

//要完成一个点 需要在 前面点完成的基础下
//即拓扑

vector<int> zerodu;//入度为0点记录
int times[N];//某个点完成的最短时间
int du[N];//记录点的度
int n,m;
bool topo()
{
    queue<int> q;
    for(int i = 0;i<n;i++)
    {
        if(!du[i])
        {
            q.push(i);
            zerodu.push_back(i);
        }
    }
    while(!q.empty())
    {
        int father = q.front();
        q.pop();
        for(auto &[v,w]:G[father])
        {
            du[v]--;
            times[v] = max(times[v],times[father] + w);
            if(!du[v])
            {
                q.push(v);
                zerodu.push_back(v);
            }
        }
    }
    return zerodu.size() == n;
}
int main()
{
    cin>>n>>m;
    while(m--)
    {
        int x,y,len;
        cin>>x>>y>>len;
        G[x].push_back({y,len});
        times[y] = len;//初始化最少时间
        du[y]++;
    }

    if(topo())
    {
        int maxtime;
        for(int i = 0;i<n;i++)
        {
            maxtime = max(maxtime,times[i]);
        }
        printf("%d\n",maxtime);
    }else{
        printf("Impossible\n");
    }
    return 0;
}
[题目详情 - 7-25 小字辈 (pintia.cn)](https://pintia.cn/problem-sets/1628020702584594432/exam/problems/1628020809572896792)



**7-25 小字辈**

本题给定一个庞大家族的家谱，要请你给出最小一辈的名单。

### 输入格式：

输入在第一行给出家族人口总数 N（不超过 100 000 的正整数） —— 简单起见，我们把家族成员从 1 到 N 编号。随后第二行给出 N 个编号，其中第 i 个编号对应第 i 位成员的父/母。家谱中辈分最高的老祖宗对应的父/母编号为 -1。一行中的数字间以空格分隔。

### 输出格式：

首先输出最小的辈分（老祖宗的辈分为 1，以下逐级递增）。然后在第二行按递增顺序输出辈分最小的成员的编号。编号间以一个空格分隔，行首尾不得有多余空格。

### 输入样例：

```in
9
2 6 5 5 -1 5 6 4 7
```

### 输出样例：

```out
4
1 9
```

还是图**bfs，dfs** 

而处理变成了 

求深度:**dis[v] = dis[u] + 1**  :dis[v]:v点到起点的距离/v点的层数 u点同理 





~~~
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10,INF = 0x3f3f3f3f;
vector<int> st[N];
int dis[N];//dis[i] i点的深度
int n;
//bfs 求深度 即  dis[v] = dis[father] + 1;
int bfs(int u) //bfs 人家只看有边的/只看集合/只看树 图
{
    memset(dis,INF,sizeof(dis));
    queue<int> q;
    q.push(u);
    dis[u] = 1;
    int maxdist = 1;    //只有祖宗自己情况
    while(!q.empty())
    {
        int father = q.front();
        q.pop();
        for(auto v:st[father])
        {
            if(dis[v] == INF)
            {
                dis[v] = dis[father] + 1;
                q.push(v);
                if(dis[v]>maxdist)
                {
                    maxdist = dis[v];
                }
            }
        }
    }
    return maxdist;
}
int maxdis = 1;
vector<int> pson;
void dfs(int u,int deep)
{
    if(!st[u].size())
    {
        if(deep>maxdis)
       {
            maxdis = deep;
            pson.clear();
            pson.push_back(u);
       }else if(deep == maxdis)
       {
            pson.push_back(u);
       }
    }

    for(auto v:st[u])
    {
        dfs(v,deep+1);
    }
}
int main()
{
    int t;//祖宗
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x != -1)
        {
            st[x].push_back(i);
        }else {
            t = i;
        }
    }
    //bfs
    //int ret = bfs(t);//从祖宗开始
    //printf("%d\n",ret);
    // bool si = true;//第一个
    // for(int i = 1;i<=n;i++)
    // {
    //     if(dis[i] == ret)
    //     {
    //         if(si)
    //         {
    //             printf("%d",i);
    //             si = false;
    //         } 
    //         else{
    //             printf(" %d",i);
    //         }
    //     }
    // }
   
   //dfs
    dfs(t,1);
    printf("%d\n",maxdis);
    bool ok  = 1;
    for(auto v:pson)
    {
        if(ok)
        {
            ok = 0;
            printf("%d",v);
        }else{
            printf(" %d",v);
        }
    }
    return 0;
}
~~~


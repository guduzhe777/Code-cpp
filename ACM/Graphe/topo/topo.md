***bfs拓扑***

保存入度为0。去作用子节点。

最短时间保证所有入点全部完成.

1.队列保存 入度为0点；

2.每个点的最短工期是将其他入点全部做完后的时间，所以为 其他入点 到 该点 最大时间，保证全部做完

3.最后所有点 入度为0 则可以。



**结构：**

vector<int> G[N] 保存两个值，加权 需要 再添加一个 pair<int,int> 

x , y  x y之间权值 ;

G[x] 可以认为是x 集合  保存  y  与  x y之间的权值w 两个  所以 x集合中的元素为pair类型

[题目详情 - 7-13 最短工期 (pintia.cn)](https://pintia.cn/problem-sets/1639522212908261376/exam/problems/1639522261683830796)

**7-13 最短工期**

分数 25

全屏浏览题目切换布局

作者 陈越

单位 浙江大学

一个项目由若干个任务组成，任务之间有先后依赖顺序。项目经理需要设置一系列里程碑，在每个里程碑节点处检查任务的完成情况，并启动后续的任务。现给定一个项目中各个任务之间的关系，请你计算出这个项目的最早完工时间。

### 输入格式：

首先第一行给出两个正整数：项目里程碑的数量 *N*（≤100）和任务总数 *M*。这里的里程碑从 0 到 *N*−1 编号。随后 *M* 行，每行给出一项任务的描述，格式为“任务起始里程碑 任务结束里程碑 工作时长”，三个数字均为非负整数，以空格分隔。

### 输出格式：

如果整个项目的安排是合理可行的，在一行中输出最早完工时间；否则输出"Impossible"。

### 输入样例 1：

```in
9 12
0 1 6
0 2 4
0 3 5
1 4 1
2 4 1
3 5 2
5 4 0
4 6 9
4 7 7
5 7 4
6 8 2
7 8 4
```

### 输出样例 1：

```out
18
```

### 输入样例 2：

```in
4 5
0 1 1
0 2 2
2 1 3
1 3 4
3 2 5
```

### 输出样例 2：

```out
Impossible
```



裸工期，拓扑保证入度为0

~~~
////该点要完成 则 其他所有点都需要完成 
//则该点完成最短时间为 所有其他的入点全部完成才行 
//根本不在意顺序，只要保证 这个时间让其他入点都完成即可

#include<bits/stdc++.h>

using namespace std;
//简单的拓扑判断 即 dfs 看是否有环-----在遍历 正在进行遍历的点 
//到了bfs中 是 以最后的入度为0点的个数 
const int N= 110;

typedef pair<int,int> PII;
vector<PII> G[N];
int n,m;
vector<int> zerodu;
int rdu[N];
int dis[N];//dis[i] i点完成的最短时间 根本不在意顺序 只要保证 这个时间让其他入点都完成即可
bool toposort()//bfs 拓扑入度
{
    queue<int> q;
    for(int i = 0;i<n;i++)
        if(!rdu[i]) q.push(i);

    while(!q.empty())
    {
        int father = q.front();
        q.pop();
        zerodu.push_back(father);
        for(auto & [v,w] : G[father])
        {
            rdu[v]--;
            if(!rdu[v]) q.push(v);
            dis[v] = max(dis[v],dis[father]+w);
        }
    } 
    return zerodu.size() == n;//全部0度
}
int main()
{

    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        G[x].push_back({y,w});
        rdu[y]++;
    }
    if(toposort())
    {
        int max0 = 0;
        for(int i = 0;i<n;i++) max0 = max(max0,dis[i]);
        printf("%d\n",max0);
    }else{
        printf("Impossible\n");
    }

    return 0;
}
~~~








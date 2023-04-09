解剖B  F S/D F S ：

***BFS:***

**探索即将连接且未探索的加入队列**

**处理有许多种处理**



**过程：用一个点寻找和他连接的点。在计算机中用队列实现。**

**用BFS 分为 探索与处理过程**

**探索过程：放入连接的节点**

**处理：  你需要进行的操作**

有时候探索与处理放在一起。满足未探索条件即可



代码体现：图:[题目详情 - 7-10 列出连通集 (pintia.cn)](https://pintia.cn/problem-sets/1642514333126778880/exam/problems/1642514395693215753)

**7-10 列出连通集**

分数 25

全屏浏览题目切换布局

作者 陈越

单位 浙江大学

给定一个有*N*个顶点和*E*条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到*N*−1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

### 输入格式:

输入第1行给出2个整数*N*(0<*N*≤10)和*E*，分别是图的顶点数和边数。随后*E*行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

### 输出格式:

按照"{ *v*1 *v*2 ... *v**k* }"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

### 输入样例:

```in
8 6
0 7
0 1
2 0
4 1
2 4
3 5
```

### 输出样例:

```out
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
```

### 题解

裸题 求 连通情况 有边输出即可

图存储有四种：最好用还是vector<int> G[N]  G[i]: 与i连接的边 

**printf 处理**

~~~
#include <bits/stdc++.h>

using namespace std;
const int N = 11;
vector<int> G[N];

bool si[N]; //是否被探索
int n, m;
//递归的dfs 也是 探索 探索标记 处理
void dfs(int x)
{
	if(si[x]) return;
	si[x] = true;//探索
	
	printf(" %d",x);//处理
	
	for(auto &v:G[x])	//取和x连接的点 等待探索
	{
		if(!si[v])
		{
			dfs(v);
		}
	}
}
//栈的dfs
// void dfs(int x)
// {
// 	stack<int> st;
// 	st.push(x);
//     si[x] = 1;
// 	while(!st.empty())
// 	{
// 		int nu = st.top();
// 		st.pop();
		
// 		printf("%d ",nu);//--处理
		
// 		for(auto &v:G[nu])//探索其他
// 		{
// 			if(!si[v])
// 			{
// 			 	st.push(v);
// 			 	si[v] = true;
// 			}
// 		}
// 	}
// }
void bfs(int x)
{
	//探索与处理
	queue<int> q;
	q.push(x);
	si[x] = true;
	while(!q.empty())
	{
		int nu = q.front();
		q.pop();
		printf(" %d",nu);	//处理这个点 ---最简单方式 printf
		for(auto v:G[nu])
		{
			if(!si[v])
			{
				q.push(v);
                si[v] = true;
			}
		}
	}
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        sort(G[i].begin(), G[i].end());///以顺序遍历所有点
    }
    for (int i = 0; i < n; i++)
    {
        if (!si[i])
        {
            printf("{");
            dfs(i);
            printf(" }\n");
        }
    }
    memset(si,false,sizeof si);
    for (int i = 0; i < n; i++)
    {
        if (!si[i])
        {
            printf("{");
            bfs(i);
            printf(" }\n");
        }
    }
    return 0;
}
~~~



bfs应用：

**（边权相同）求深度处理**

特性：图也有层数，这个层数基于起点 与 起点连接的点。

而bfs会最快访问层数最少的点。

在边权相等情况下，到某个点的距离，可以认为是 某个点的深度即层数

[题目详情 - 7-13 喊山 (pintia.cn)](https://pintia.cn/problem-sets/1642514333126778880/exam/problems/1642514395693215756)



**7-13 喊山**

分数 30

全屏浏览题目切换布局

作者 陈越

单位 浙江大学

喊山，是人双手围在嘴边成喇叭状，对着远方高山发出“喂—喂喂—喂喂喂……”的呼唤。呼唤声通过空气的传递，回荡于深谷之间，传送到人们耳中，发出约定俗成的“讯号”，达到声讯传递交流的目的。原来它是彝族先民用来求援呼救的“讯号”，慢慢地人们在生活实践中发现了它的实用价值，便把它作为一种交流工具世代传袭使用。（图文摘自：http://news.xrxxw.com/newsshow-8018.html）

![img](https://images.ptausercontent.com/183)

一个山头呼喊的声音可以被临近的山头同时听到。题目假设每个山头最多有两个能听到它的临近山头。给定任意一个发出原始信号的山头，本题请你找出这个信号最远能传达到的地方。

### 输入格式：

输入第一行给出3个正整数`n`、`m`和`k`，其中`n`（≤10000）是总的山头数（于是假设每个山头从1到`n`编号）。接下来的`m`行，每行给出2个不超过`n`的正整数，数字间用空格分开，分别代表可以听到彼此的两个山头的编号。这里保证每一对山头只被输入一次，不会有重复的关系输入。最后一行给出`k`（≤10）个不超过`n`的正整数，数字间用空格分开，代表需要查询的山头的编号。

### 输出格式：

依次对于输入中的每个被查询的山头，在一行中输出其发出的呼喊能够连锁传达到的最远的那个山头。注意：被输出的首先必须是被查询的个山头能连锁传到的。若这样的山头不只一个，则输出编号最小的那个。若此山头的呼喊无法传到任何其他山头，则输出0。

### 输入样例：

```in
7 5 4
1 2
2 3
3 1
4 5
5 6
1 4 5 7
```

### 输出样例：

```out
2
6
4
0
```

~~~
题目分析：
	查询每个点能到达的最远点，因为边权相同 自然想到 bfs 深度即层数 
	bfs 求层数
~~~



~~~
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10,INF = 0x3f3f3f3f;

vector<int> G[N];//存图G[i]:与i连接的点.

int n,m,k;//声音连接 求 最远  即 最大深度
int dis[N];//到起点的最远距离
int bfs(int u)
{
	memset(dis,INF,sizeof(dis));//默认距离 不知道
	dis[u] = 0;
	int maxdist = 0,id = 0; //到起点最远距离
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		int nu = q.front();
		q.pop();
		for(auto &v:G[nu])
		{
			if(dis[v] == INF)
			{
				//这个点为处理过 探索
				q.push(v);
				dis[v] = dis[nu] + 1;//到起点距离
				if(dis[v]>maxdist)
				{
					maxdist = dis[v];
					id = v;
				}else if(maxdist == dis[v])
				{
					id = min(id,v);
				}
			}
		}
	}
	return id;//返回最远距离点 /  最深点
}
int main()
{	
	cin>>n>>m>>k;
	while(m--)
	{
		int x,y;//互相听到
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	while(k--)
	{
		int t;
		cin>>t;
		int id = bfs(t);//求最深的点
		printf("%d\n",id);
}
	return 0;
}
~~~






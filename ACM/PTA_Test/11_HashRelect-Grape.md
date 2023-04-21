~~~c++
//哈希映射
map<string,int> mpsi;//字符串 整数映射
					//用于图节点为字符串情况


~~~

~~~c++
//哈希映射 实际操作
int number2;
if(mpsi.count(s1))//已有编号
{
    number2 = mpsi[s1];
}else{//没有编号
    mpsi[s1] = ++cnt;//编号点
    number2 = mpsi[s1];
}
~~~



~~~c++
//set存图 
set<int> G[N];
//好处 可以随时删除 图中的节点  //节点标记不能相同
G[father].erase(x);//删除 与father连接 节点标记x 的节点  
				//复杂度o(logn) （堆排序） 

//节点父亲更新，节点需要更换情况 适合用set存； 

//若vector 存图
vector<int> G[N];
for(auto &v : G[father])
    if(v == x)
        break;//o(n)复杂度寻找
~~~

~~~c++
//更换图父亲节点过程:
	int fathers[N];//记录父亲
	set<int> G[N];
	G[fathers[x]].erase(x);		//离开家庭
	G[newfather].insert(x);		//加入家庭
	fathers[x]  = newfather;
//更新父亲 删除之前 加入新父亲  G[newfather].insert(x);
~~~

~~~c++
//图的遍历 对于节点可能不是我们需要计入的情况；
//比如 节点可能为管理中心 不计入人数 (如此题)
void dfs(int x)
{
    for(auto &v :G[N])
    {
        if(v<=n)	//节点不计入
            temp++;
        dfs(v);
    }
}
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int father = q.front();
        q.pop();
        for(auto v:G[father])
        {
            if(v<=n)
                temp++;
            q.push(v);//由于有向图且不会一个点有多个父亲，所以不必在意是否遍历过。
        }
    }
}
~~~

例题：

[题目详情 - 7-3 智能护理中心统计 (pintia.cn)](https://pintia.cn/problem-sets/1648179596815867904/exam/problems/1648179672531480576)

**7-3 智能护理中心统计**



智能护理中心系统将辖下的护理点分属若干个大区，例如华东区、华北区等；每个大区又分若干个省来进行管理；省又分市，等等。我们将所有这些有管理或护理功能的单位称为“**管理结点**”。现在已知每位老人由唯一的一个管理结点负责，每个管理结点属于唯一的上级管理结点管辖。你需要实现一个功能，来统计任何一个管理结点所负责照看的老人的数量。

注意这是一个动态问题，即随时可能有老人加入某个管理结点，并且老人是有可能从一个管理结点换到另一个管理结点去的。

### 输入格式：

输入在第一行中给出 2 个正整数：*N*（≤104）是老人的总数量，即老人们从 1 到 *N* 编号；*M*（≤105）是归属关系的总数。

接下来是 *M* 行，每行给出一对归属关系，格式为：

```
A B
```

表示 `A` 归属于 `B`。`A` 或 `B` 如果是某个管理结点，则用不超过 4 个大写英文字母表示其名称；如果是某位老人，则用老人的编号表示。这里每个 `A` 保证只有唯一的上级归属 `B`，且只有这个中心系统本身是没有上级归属的。此外，输入保证没有老人自己承担管理结点的角色，即 `B` 一定是一个管理结点，不可能是老人的编号。但一个管理结点既可以管辖下级结点，也可以直接护理一部分老人。

随后每行给出一个指令，格式为：

```
指令 内容
```

如果 `指令` 为 `T`，则表示有老人要入院或转院，`内容` 是某老人的编号和要去的管理结点的名称，以空格分隔；如果 `指令` 为 `Q`，则 `内容` 是一个管理结点的名称，意思是统计这个结点所负责照看的老人的数量；如果 `指令` 为 `E`，则表示输入结束。题目保证指令总数不会超过 100 个。

### 输出格式：

对每个 `T` 指令，将对应的老人转存到对应的管理结点名下；对每个 `Q` 指令，在一行中输出对应管理结点所负责照看的老人的数量。读到 `E` 指令就结束程序。

### 输入样例：

```in
10 23
EAST CNTR
ZJ EAST
SD EAST
WEST CNTR
SX WEST
HZ ZJ
JN SD
2 JN
8 JTH
6 XAHP
4 ZDYH
5 ZDYH
ZDYH HZ
HUZ ZJ
JX ZJ
1 JX
3 JN
WZ ZJ
XAHP XIAN
XIAN SX
YL SX
JTH XIAN
7 XAHP
Q EAST
T 1 YL
Q EAST
Q SX
T 8 ZDYH
Q HZ
Q HUZ
T 10 XAHP
Q CNTR
E
```

### 输出样例：

```out
5
4
4
3
0
9
```







~~~
#include <bits/stdc++.h>

using namespace std;

map<string, int> mpsi;
map<int, string> mpis;//用编号找 字符串
int n, m;
int cnt;


const int N = 2e5 + 10;
set<int> G[N]; //存图

int fat[N];//标记父亲

int ans = 0;
void dfs(int u)
{
    for(auto &v : G[u])
    {
        if(v<=n)
            ans++;
        dfs(v);
    }
}
int main()
{
    cin >> n >> m;
    cnt = n;
    while (m--)
    {
        string s1, s2;
        int number1, number2;
        cin >> s1 >> s2;
        if (isdigit(s1[0]))
        {
            number1 = stoi(s1);
        }
        else
        {
            //哈希映射
            if (mpsi.count(s1))//有编号
            {
                number1 = mpsi[s1];
            }
            else
            {
                mpsi[s1] = ++cnt;
                mpis[cnt] = s1;
                number1 = cnt;
            }
        }
        if(mpsi.count(s2))
        {
            number2 = mpsi[s2];
        }else{
            mpsi[s2] = ++cnt;
            mpis[cnt] = s2;
            number2 = cnt;
        }
        fat[number1] = number2;
        G[number2].insert(number1);//存图
    }
    char op;
    while(cin>>op&&op != 'E')
    {
        if(op == 'T')
        {
            //入院/转院
            int x;//老人
            string s1;//管理中心
            cin>>x>>s1;
            int number2 = mpsi[s1];
            if(fat[x])//转院
            {
                int father = fat[x];
                G[father].erase(x);
                G[number2].insert(x);
                fat[x] = number2;
            }else{//入院/
                G[number2].insert(x);
                fat[x] = number2;
            }
        }else{
            //查看节点老人
            string s1;
            cin>>s1;
            int number2 = mpsi[s1];
            
            dfs(number2);
            printf("%d\n",ans);
            ans = 0;
        }
    }
    return 0;
}
~~~


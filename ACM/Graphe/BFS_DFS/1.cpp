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
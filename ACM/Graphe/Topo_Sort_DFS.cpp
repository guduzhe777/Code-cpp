#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v;
    Edge *next;
} epool[1010];
struct node
{
    Edge *first;
    int mark; //探索。
} npool[1010];

int n, m;
int pos;

void add(int u, int v)
{
    epool[pos].u = u;
    epool[pos].v = v;
    epool[pos].next = npool[u].first;
    npool[u].first = &epool[pos];

    pos++;
}
bool si = true; //可以实现
stack<int> f;
//处理
int operat[1010]; // operat[i] = 0/1/2;// 未处理 正在处理  处理完了
//探索
void topo(int x)
{
    f.push(x);
    while (!f.empty())
    {
        
    
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    topo(1);

    return 0;
}
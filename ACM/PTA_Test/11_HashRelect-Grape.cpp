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
                ans++;
            q.push(v);//由于有向图且不会一个点有多个父亲，所以不必在意是否遍历过。
        }
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
            
            //dfs(number2);
            bfs(number2);
            printf("%d\n",ans);
            ans = 0;
        }
    }
    return 0;
}
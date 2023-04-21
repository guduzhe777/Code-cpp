#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
map<int, vector<int>> mp; // x y
double st[N][N];          //关系度 st
int n, m;


set<string> u; //存储已经 出现过的人
//回顾 哈希映射
map<string, int> relect;

bool gender[N]; //记录男女

bool cmp(int a, int b)
{
    return a > b;
}

struct cmp1
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
void out(int x)
{
    if (gender[x])
        cout << x;
    else
    {
        cout << "-" << x;
    }
}
int v[N];
int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            string x;
            cin >> x;
            int z;
            if (isdigit(x[0]))
            {
                z = stoi(x);
                gender[z] = 1; //男
            }
            else
            {
                z = abs(stoi(x));
                gender[z] = 0; //女
            }
            v[j] = z;
        }
        for (int x = 0; x < k; x++) //一张照片 人们的亲密度
        {
            for (int y = 0; y < k; y++)
            {

                if (v[x] == v[y])
                    continue;
                // s  t两个编号
                st[v[x]][v[y]] += 1.0 / k;
                st[v[y]][v[x]] += 1.0 / k;
            }
        }
    }
    int x, y;
    cin >> x >> y; //输入情侣 找亲密度最大
    x = abs(x);
    y = abs(y);
    double maxst_x = 0, maxst_y = 0;
    for (int i = 0; i < n; i++)
    {
        if (gender[x] != gender[i] && maxst_x < st[x][i])
        {
            maxst_x = st[x][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (gender[y] != gender[i] && maxst_y < st[y][i])
        {
            maxst_y = st[y][i];
        }
    }
    if (maxst_x == st[x][y] && maxst_y == maxst_x)
    {
        out(x);
        cout << " ";
        out(y);
    }
    else
    {
        priority_queue<int, vector<int>, cmp1> q;
        for (int i = 0; i < n; i++)
        {
            if (gender[x] != gender[i] && maxst_x == st[x][i])
            {
                out(x);
                cout << " ";
                out(i);
                printf("\n");
            }
        }
        // while (q.size())
        // {
        //     int top = q.top();
        //     q.pop();
        //     out(x);
        //     cout << " ";
        //     out(top);
        //     printf("\n");
        // }

        for (int i = 0; i < n; i++)
        {
            if (gender[y] != gender[i] && maxst_y == st[y][i])
            {
                out(y);
                cout << " ";
                out(i);
                printf("\n");
            }
        }
        // while (q.size())
        // {
        //     int top = q.top();
        //     q.pop();
        //     out(y);
        //     cout << " ";
        //     out(top);
        //     printf("\n");
        // }
    }
    return 0;
}
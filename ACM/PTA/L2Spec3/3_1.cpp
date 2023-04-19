#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mst(a, b) memset((a), (b), sizeof(a))
const int maxn = 10005;

int n, m;
int vis[maxn];
int pre[maxn], num[maxn];  //父亲节点
int tao[maxn], area[maxn]; //套数  面积

struct node
{
    int id, num, tao, area; //编号  人口  套数  面积
} a[maxn];

bool cmp(node a, node b)
{
    if (a.num * b.area == a.area * b.num)
        return a.id < b.id;
    return a.area * b.num > a.num * b.area;
}

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        pre[i] = i; //父亲为自己
        num[i] = 1; //自己家庭中 人口数量
    }
}

int find(int x) // find函数：
{
    int t, r = x;
    while (x != pre[x])
    {
        x = pre[x];
    } //寻找x 祖宗
    while (r != x)
    {
        t = pre[r];
        pre[r] = x;
        r = t;
    }         //将祖宗变 所有 父亲 爷爷们的父亲
    return x; //返回祖宗 即 现在的父亲
}

void join(int a, int b)
{
    vis[a] = vis[b] = 1;
    int A = find(a);
    int B = find(b);
    if (A == B)
        return;
    if (A < B)
    {
        pre[B] = A;
        num[A] += num[B];
        tao[A] += tao[B];
        area[A] += area[B];
        // num[B]=tao[B]=area[B]=0;
    }
    else
    {
        pre[A] = B;
        num[B] += num[A];
        tao[B] += tao[A];
        area[B] += area[A];
        // num[A]=tao[A]=area[A]=0;
    }
}

int main()
{
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tmp[10];
        int a, b, c, k;
        scanf("%d%d%d%d", &a, &b, &c, &k);
        vis[a] = 1;                 //父亲标记
        for (int j = 0; j < k; j++) // k个孩子
            scanf("%d", &tmp[j]);   // tmp[j]  = k 孩子编号k
        int x, y;
        scanf("%d%d", &x, &y);                 //房产套数 总面积
        tao[find(a)] += x, area[find(a)] += y; //将 套数 面积加到自己祖先名下
        if (b != -1)
            join(a, b); //将 b 即 母亲加到 a 即父亲 下
        if (c != -1)
            join(a, c);
        for (int j = 0; j < k; j++)
            join(a, tmp[j]);
    } //将孩子 老婆的房子 套数 面积 都搞到a祖宗上面
    int cnt = 0;
    for (int i = 0; i < maxn; i++)
    {
        if (find(i) == i && vis[i]) //使用标记  i点被 使用 具有该编号
        {
            a[cnt].id = i;      //家庭成员中 最小的编号
            a[cnt].num = num[i]; 
            a[cnt].tao = tao[i];
            a[cnt++].area = area[i];
        }
    }
    sort(a, a + cnt, cmp); //将节点 排序
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        printf("%04d %d %.3f %.3f\n", a[i].id, a[i].num, a[i].tao * 1.0 / a[i].num, a[i].area * 1.0 / a[i].num);
    }
}
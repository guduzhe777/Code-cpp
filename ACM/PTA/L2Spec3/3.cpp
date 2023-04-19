#include <bits/stdc++.h>

using namespace std;

//编号 父母编号  孩子数 孩子编号 套数 总面积
//统计 编号最小的 人口  套数  面积

//家庭信息首先按人均面积降序输出，若有并列
//，则按成员编号的升序输出。
int i = 0;
const int N = 1e4 + 10;
int peonum[N], tao[N], area[N];

int pre[N];
bool vis[N]; //是否作为 使用
void init()
{
    for (int i = 0; i <= N; i++)
    {
        pre[i] = i; //初始化 最小编号为自身
        peonum[i] = 1;//自己家人口数量
    }
}
int find(int x)
{
    if(x == 16787215)
    {
        printf("0\n");
    }
    if (pre[x] == x)
        return x;
    pre[x] = find(pre[x]);
    //找祖宗 在此题中 即 编号最小那个
    return pre[x];
}
void union0(int a, int b)
{
    vis[a] = vis[b] = 1;
    // if(a == b)
    // {
    //     //怎么可能sb
    // }
    int A = find(a),B = find(b);
    
    if (A == B)
        return;
    if (A < B)
    {
        pre[B] = A;
        peonum[A] += peonum[B];
        tao[A] += tao[B];
        area[A] += area[B];
        // peonum[B]=tao[B]=area[B]=0;
    }
    else
    {
        pre[A] = B;
        peonum[B] += peonum[A];
        tao[B] += tao[A];
        area[B] += area[A];
        // peonum[A]=tao[A]=area[A]=0;
    }
}
struct node{
    int id,peonum,tao,area;

}famliy[N];
int n;

//家庭信息首先按人均面积降序输出，
//若有并列，则按成员编号的升序输出。
bool cmp(node &a,node &b)
{

    if(1.0 * a.area/a.peonum > 1.0 * b.area/b.peonum) return true;
    else if(1.0 * a.area/a.peonum == 1.0 * b.area/b.peonum)
   {
        if(a.id<b.id) return true;
   }
    return false;
}
int main()
{
    init();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        vis[a] = 1;
        for(int i = 0;i<k;i++)
        {
            int x;
            cin>>x;
            union0(a,x);//初始化 自己一个人 人口为1 加入后 自动更新。
        }
        // cin>>tao[a]>>area[a];
        int x,y;
        cin>>x>>y;
        tao[find(a)] += x, area[find(a)] += y;
        if(b != -1)
            union0(a,b);
        if(c != -1)
            union0(a,c);
        
    }
    int pos = 0;
    for(i = 0;i<N;i++)
    {
        if(find(i) == i&&vis[i])
        {
            ////人口 房产套 面积
            famliy[pos] = {i,peonum[i],tao[i],area[i]};
            pos++;
        }
    }
    sort(famliy,famliy + pos,cmp);
    
    //得到 最小编号 的集合 信息
    //sort
    //输出
    printf("%d\n",pos);
    for(int i = 0;i<pos;i++)
    {
        auto &[id,peonums,taos,areas] = famliy[i];
        printf("%04d %d %.3lf %.3lf\n",id,peonums,1.0 * taos/peonums,1.0 * areas/peonums);
    }
    return 0;
}
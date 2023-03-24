//并查集 
//理解： 
//数组fa[i]  i的父亲为fa[i]
//将有关系的 设为父亲
//为了保证链条不是太长，我们将 自己的 父亲 爷爷 等向上的父亲 都设为祖先，设为祖先好查；
//我们 放祖先的时候可能 长链子放，but在查询的时候 我们会把某个节点的 父亲，爷爷 老爷爷们的父亲更新为祖先
//
//并查集对于  已知 每个人的关系，若a  b 为朋友  b c 为朋友 那么 a c也为朋友
//这类传递性的关系 修改， 
//那么 处理这类 传递性关系 
//写法：
//init   find    union ： 
//初始化：
//
#include<bits/stdc++.h>

using namespace std;
const int N  = 110;
int st[N][N];
int fa[N];//某个人的父亲 -- 
int n,m,k;//宾客数量， 关系数  k查询数量
int init(int n)//初始化
{
    for(int i = 1;i<=n;i++)
    {
        fa[i] = i;//父亲是自己
    }
}
int find(int u)//查找 u的祖先 把u的父亲 爷爷们的父亲也设置为 u的祖先 把 u 祖先的父亲 设置为v的祖先
{
    if(u == fa[u])
    {
        return u;//自己是自己的祖先
    }else{
        fa[u] = find(fa[u]);    //将自己的父亲设置为自己的祖先
        return fa[u];
    }
}
void merge(int u,int v)//将u的祖先的父亲设置为v的祖先
{   
    int fa_u = find(u);
    int fa_v = find(v);
    fa[fa_u] = fa_v;
}
int main()
{
    cin>>n>>m>>k;
    init(n);
    for(int i = 0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        st[x][y] = st[y][x] = z;
        if(z == 1) merge(x,y);  //如果 二者为朋友 那么 联系一起
    }
    while(k--)  //k次询问
    {
        int x,y;
        cin>>x>>y;
        if(st[x][y] == 1) printf("No problem\n");//两个人是朋友
        else if(st[x][y] == -1) //如果两个人 不好但是 有 相同朋友  
        {
            if(find(x) == find(y)) printf("OK but...\n");
            else{//没有共同好友
                printf("No way\n");
            }
        } else{//两个没有关系  
            if(find(x) == find(y)) printf("No problem\n");//有共同好友
            else{
                printf("OK\n");//没有共同好友 与 敌人
            }
        }
    }
    return 0;
}
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
//线段树
//
const int N = 100010;
int n,m;
int k,a,b;
int w[N];

struct{
    int l,r;
    int sum;//   
}tree[4 * N];
void pushup(int u)//用孩子更新父亲
{
	//以信息为例子
	tree[u].sum = tree[u<<1].sum + tree[u<<1|1].sum;
}
void build(int u,int l,int r) //指向该区域  
{
	if(l == r)  tree[u] = {l,r,w[l]};//该区域 保存的线段 边界	左界 = 右界 只有一个值 和为 w[l]
	else{
		tree[u] = {l,r};//该区域 保存的线段 边界 更新完 l r了 继续更新 孩子的
						//but 自己的信息需要孩子 才能更新
		int mid = l + r >>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);//对左右孩子初始化
		pushup(u);//用左右孩子更新 父亲
	}
}
int query(int u,int l,int r)//以某个点开始  求 左右区间的和
{
	if(tree[u].l>=l&&tree[u].r<=r) return tree[u].sum;//返回 该区域的和
	int mid = tree[u].l + tree[u].r>>1;
	//if(l<=mid) return query(u>>1,l,mid);
	//if(r>mid) return query(u>>1|1,mid+1,r);
	int sum = 0;//暂时保存该区域的和
	// if(l<=mid)	sum += query(u>>1,l,r);//为什么 到 r 而不是 mid 
	// if(r>mid) sum += query(u>>1|1,l,r);//我认为这俩一样的 r 的时候mid 也是 可以直接返回
	//放到孩子中
    if(l<=mid)	sum += query(u<<1,l,r);//为什么 到 r 而不是 mid 
	if(r>mid) sum += query(u<<1|1,l,r);//我认为这俩一样的 r 的时候mid 也是 可以直接返回
    return sum;//两区域和求取完毕
}
void modify(int u,int x,int v) //根节点  x 位置 增值v//寻找到 x位置  然后 修改 最后更新父亲
{
	if(tree[u].l == tree[u].r)  tree[u].sum += v;//只有一个值 和加个v
	else{//儿子更新
		int mid = tree[u].l + tree[u].r>>1;
		if(x<=mid) modify(u<<1,x,v); //二分寻找位置  位置在mid 左边那么 在左边寻找
		else{
			modify(u<<1|1,x,v);
		}
		pushup(u);//儿子去更新父亲
	}
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        
    }
	build(1,1,n);
    while(m--)
    {
        scanf("%d%d%d",&k,&a,&b);
        if(!k) //a b区间的和
        {
            printf("%d\n",query(1,a,b));
        }else{
            modify(1,a,b);
        }
    }
    return 0;
}
***线段树***

思路：将 1-----n 区间   持续二分（mid = r+l>>1)   至 只有一个点 (l = r) 

对每个 区间用 线段树保存

~~~c++
struct Node{
	int l,r;//左右 区域    
    int sum;//这个是 你需要的信息 这个题是求 区间和s
}tree[N];	//线段树占空间 大约4 *  n
~~~



几个核心函数

1. 初始化线段树函数：分别初始化 l  r  sum(信息（这个信息为sum）)

   1. ~~~
      void build(u,l,r) //指向该区域  
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
      ~~~

2. 更新函数 子孩子 更新  父亲 的函数:

   1. ~~~
      pushup(u)//用孩子更新父亲
      {
      	//以信息为例子
      	tree[u].sum = tree[u<<1].sum + tree[u<<1|1].sum;
      }
      ~~~

3. 整合区域信息函数： 以整合 求和函数为例  作用即是  求某个区域的和

   1. ~~~
      int query(u,l,r)//以某个点开始  求 左右区间的和
      {
      	if(tree[u].l>=l&&tree[u].r<=r) return tree[u].sum;//返回 该区域的和
      	int mid = tree[u].l + tree[u].r>>1;
      	//if(l<=mid) return query(u>>1,l,mid);
      	//if(r>mid) return query(u>>1|1,mid+1,r);
      	//当l <= mid时，r也可能比mid小，此时如果把r更新成mid，那就会错误地把要查询的区间变长。
      	int sum = 0;//暂时保存该区域的和
      //当l <= mid时，r也可能比mid小，此时如果把r更新成mid，那就会错误地把要查询的区间变长。!!!
      	if(l<=mid)	sum += query(u>>1,l,r);//为什么 到 r 而不是 mid 
      	if(r>mid) sum += query(u>>1|1,l,r);//我认为这俩一样的 r 的时候mid 也是 可以直接返回
      	return sum;//两区域和求取完毕
      }
      ~~~

4. 修改函数 增值函数 u,x,v 树根节点   x 位置  增值v

   1. ~~~
      modify(int u,int x,int v) //寻找到 x位置  然后 修改 最后更新父亲
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
      ~~~

   2. 
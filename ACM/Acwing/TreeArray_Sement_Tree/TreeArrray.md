## 1264. 动态求连续区间和

分析：

前缀和 不支持边修改 边查询 

我们可以利用一维前缀和 求 前缀和 降低复杂度  o(n) + o(b - a)-->> o(n) + o(1)

# 树状数组

图用于 想 add 更新过程  query 求和过程

![31e23bc7b41ec145edb45cee8b55855.png](https://cdn.acwing.com/media/article/image/2020/01/13/7416_68861e9035-31e23bc7b41ec145edb45cee8b55855.png)

1. 什么是？
   1. 用一种 树的结构 存储 数组 元素和 核心为*** lowbit ***寻找 父子节点（创造时用的*** lowbit***）  
   2. 

1. 核心函数

   1.  **lowbit **:求末尾几个0 若 没0 返回1  核心作用寻找父子节点

      1. ~~~
         int lowbit(int x)//末尾几个0  寻找父子节点作用 末尾没0 返回1
         {
             return x&-x;
         }
         ~~~

   2. ***add(int x,int v)***:从第x个位置开始 依***lowbit***向后更新 父节点

      1. ~~~
         //从下标x 开始 向后更新父节点
         void add(int x,int v)
         {
             for(int i = x;i<=n;i += lowbit(i)) tree[i] += v; //从子到父更新 树状数组
         }
         ~~~

   3. ***query(int x)***:从下标x（包含x）开始 利用*** lowbit ***向前求和

      1. ~~~
         int query(int x) //依靠树状数组 从后向前 求 前缀和
         {
             int res = 0;
             for(int i = x;i>0;i -= lowbit(i)) res += tree[i];
             return res;
         }
         ~~~

2. 产生tree数组过程：

   1. 假定 原数组为0   依次 加入数值  那么相应  树状数组  会 自动更新 数值  在修改位置（i位置） 向后 利用***lowbit ***更新父节点




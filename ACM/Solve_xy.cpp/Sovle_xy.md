

#### 解决 ax + by = c 求解 x y问题   





暴力无非

~~~
for
	for
		a x + b y = c
~~~

基于裴蜀定理

a x + b y = c  这个c 一定是 gcd(a,b) 倍数  证明略

a x + b y = gcd(a,b) 

扩展欧几里得：

一直取余   到a  =  数字       b = 0  

0. 关键：

   1. 逻辑：到最底层 返回x y  参与x y计算 返回最大公约数

   2. 要素：

      1. 最底层的x y 

      2. 等式求上一层

      3. //如何用底层求上一层：

         1. ~~~
            确定等式：
            x y应该是上一层的 x y：
            int Euclidexpand(int a,int b,int &x,int &y) // 引用 可以改变值
            确定等式：
            y = x - (a/b) * b * y;      //这一层的y  利用等式 + 上一层的x y
                    x = temp;           //这一层的x;     利用等式 + 上一层的x y
                    
                    
                    
            //所以就求出来了 我们怎么想？ 第一层和第二层即可 简单 而且和其他逻辑一样
            到最底层 返回x y  参与x y计算 返回最大公约数
            ~~~

1. 如何实现 x y更新：
   1. 利用 最底层值  + 第一层 第二层 关系（推出每一层关系） + &可以改变值（不在乎形参）
   2. 找到最底层 修改x y 返回上一层  y =  x =  就修改了  返回上一层 继续修改  

![Screenshot_20221024_131416_com.jideos.jnotes](E:\Admin\下载\LANDrop\Screenshot_20221024_131416_com.jideos.jnotes.jpg)
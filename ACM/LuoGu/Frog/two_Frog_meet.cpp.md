两只青蛙 很简单的 关系式 求解二元一次方程嘛





###  求的和需要的之间的转化

我们本来要解的方程式是

ax+by = c

但是我们解的方程式是ax+by = d

在数学上就是：

5x + 3y = 1

求解5 x + 3 y = 2

5 * (2x) + 3 * (2y) = 2

求2x即可

所以对应任意我们求的 

ax+by = c	（c为d的倍数）

我们只能求

ax+by = d （c为d的倍数）

变化一下权重即可

t * c /d 那么就变成了这个整体了！！！

且只是 直线上下移动了  不改变直线方向向量

~~~
		while(t<0)
        {
            t += obs(b);
        }
        t = t%b;
~~~

1. 为什么需要转化
   1. 求的ax+by = d   需要的 ax+by = c  权重转化一下就行了   在求的时候 c必须是d 的倍数
2. 如何转化：
   1. 我们求的是整体x  a后面的整体 等于多少！！！  所以 x  * c / d就是整体了
   2. a（x * c / d) + b(y *c / d) = c  a后面的整体为多少。 

​	
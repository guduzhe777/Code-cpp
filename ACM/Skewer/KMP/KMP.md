#### kmp

kmp最关键的是j = next[j]  一般没人写。。。。

##### 核心原理： 

1. 每次都是找该串的最大 次级大  次次大  次次次大。。。。相同前后缀长度 利用前后缀 可以直接把前缀 挪到 后缀来比较串
2. 次级大存在于最大之中  且被保存在最大的前缀部分后一个记作t指向的元素 对应 next[t]之中

j始终指向最大相同的前缀尾部

i指向被比较的元素

1. 前后缀是什么
   1. 前：不含尾元素 的 串
   2. 后缀：不含首元素的串
2. 为什么次级大被保存在 j指向元素的 next[j]中
   1. 次级大存在于最大之中  且被保存在最大的前缀部分后一个记作t指向的元素 对应 next[t]之中
3. 次级大存在于最大之中  且被保存在最大的前缀部分后一个记作t指向的元素 对应 next[t]之中 为什么？
   1. 次级大存在最大之中  可以画图解决：
      1. ![1666422514297](E:\Admin\文档\Tencent Files\205303538\FileRecv\MobileFile\1666422514297.jpg)
   2. 恰好发现  最大前缀的后一个元素t 的next[t] 储存的就是前面最大相同前后缀的数量 也是 次级大 前缀的下一个元素  恰好 和i元素比较 是否相等
      1. 不等：由次级大  找次次  
      2. 相等：++i = ++j 相同个数  与 下次开始比的下标

​	



#### //子串是否重复问题



如果存在一个子串 可以多次重复构成 该串

那么 可以认为一堆相同的箱子（子串） 构成一个串 s  那么s + s的串 一定存在 s串 想一个一个箱子

所以就变成了  一个串之中  除了头部 尾部 元素 外 判断是否存在 子串s问题

（要是包含头部 尾部 一定有箱子可以组成 s 因为就是 s + s）

在一个串之中查找是否存在子串 是KMP的本领

#### kmp 是 什么

寻找这个元素前面 串的 最大相同 前后缀

当串 比较不同时候 直接拿前缀的后一个元素来比较

#### 如何写：

i 最大保存next[i+1]

1. next

   1. 明确 i指向 比较元素  j 指向前缀表的后一个元素

   2. 最大相同 数保存在 下一个元素对应next中 

   3. next[i]不含i元素的最大相同 直接拿来用

   4. ~~~
      next:
      j = -1;
      i = 0;
      next[0] = -1;
      next[1] = 0;
      //如果最大不同 那么寻找次级大。。。。  
      //如果和第一个也不同 j = next[0] 那么 赋值 0  该串的最大相同为0
      while(i<len)
      {
      	if(j == -1 || s[i] == s[j])
      	{
      		next[++i] = ++j;
      	}
      	else{
      		j = next[j];//既是最大相同数量 又指向 前缀尾部的后一个元素
      	}
      }
      ~~~

   5. 

2. 利用next

   1. 相同 那么 ++

   2. 不同 找来新的来比较

   3. 注意： 当开头不同 i = next[i]  i = -1  也要++

      1. ```
         while(i<len1&&j<len2)
         {
         	if(s[i] == s[j]||j == -1)//特殊情况  第一个和这个也不同（j = next[j] j = -1 那么都加加）
         	{
         		++i;
         		++j;
         	}
         	else{
         		j = next[j];//不同的时候  最大相同前缀替换 就来了 
         	}
         }
         ```

      2. 



#### string.len 为无符号数字  一般不直接比较 强转换再比较

~~~
 	 	int s_len = s.length();
        int ss_len = ss.length();	
        while((i<s_len)&&(j<ss_len-1))
~~~





"ababcabcababcabc"

"ababcabc"
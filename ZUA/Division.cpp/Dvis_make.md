//!如果循环之中改变i i会永远被改变



#### //产生全排列数字 

//并不是一个一个循环产生 太麻烦

//可以在取值范围内放进同一个数组内 然后判断数组每一个元素都不同

//（基于同一个数组 用 每个元素不同 利用双指针利于计算）大大节省了时间复杂度 

~~~
//放进数组
while (x / 10)
        {
            arr[j] = x % 10;
            x /= 10;
            j++;
        }
~~~

~~~
//双指针判断数组中的每个元素都不同
int dis(long long arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] == arr[j]) //凡是有相等
            {
                return 0;
            }
        }
    }
    return 1;
}
~~~

 #### //标记位常用于  后续需要 用到 该条件 是否成立的情况 



~~~
//判断是否全部不相等  如果真的全不相等那么
for (int k = 0; k < 10; k++)
            {
                for (int t = k + 1; t < 10; t++)
                {
                    if (arr[t] == arr[k])
                    {
                        sign = 0; //说明存在相等  那么这一组不行 开新的 标记+退出一次  标记再退出一次 
                        break;
                    }
                }
            }
            
             if (sign) //如果真的全不相等那么
            {
            	printf("hello");
            }
~~~

#### 最后输出 只输出一次的（例如次数）

1. 对于最后输出的 如次数  我们一般保存 然后最后输出  如果后续还跟着东西 那么  这部分东西 也需要保存起来  最后一起输出

   1. ~~~
      
      if(k * (x + y) == x * y)
                      {
                          cnt++;
                          a[i] = x;
                          b[i] = y;
                          i++;        //找到了那么保存把
                      }
      保存起来最后输出   //因为次数这种只最后输出一次的影响
      ~~~

   2. 


~~~
if(array[i])  a = array[i];
        else  continue;
~~~

```
//五层for 使得每一个数字都来自数组
第一个需要注意判断为0不输入 重新给他选择
if(array[i])  a = array[i];
        else  continue;
```

~~~
sprintf(buf, "%d%d%d%d%d", x, y, z, 100*a+10*b+c, 10*d+e);
                        //该函数的作用是：将想向屏幕输出的内容原封不动，从地址buf开始，输入到buf[]数组中，
                        //并将内容原封不动转化为字符串，不需要转化成ASCII
                        //所以常用sprintf来把整数打印到字符串中

~~~

~~~
//比较求出来一大堆的数字  是否 和输入有所不同
if(strchr(str, buf[m]) == NULL) {ok = 0; break;}   // 有一个buf 有 但是str没有对应那么返回0  ------比较数组不同的时候 字符串真是个好东西
~~~

~~~
if(split[i] == array[j])  {flag = 1; break;}
//有相同的就赋值然后退出循环
~~~


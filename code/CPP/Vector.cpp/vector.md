

### Vector内存相关

![image-20221016192007403](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221016192007403.png)

~~~
	v1之中没有元素的时候 他的begin()为0！
	vector<int>::iterator it = v1.begin();
    printf("%x ",it);
~~~

### vector是什么 

单端动态容器他是个容器！

~~~c++
vector<int>cnt(0); 
cnt++;
~~~

这是错误的  cnt是装int类型的容器 不是int类型

### 一些细节

#####  第n次满了之后 添加值的时候才会增加到 2^n-1空间 

1. 规律：尺寸前有多少次满了 5前有 0 1 2 4 四次满了 所以再添加回到2^4-1 = 8

   1. capa：0开始 添加就是 第一次满了之后2^1-1 = 1

   2. capa：1  size = 1 第二次满了 添加 2^2-1 = 2

      

#### //容器嵌套

1. //每个容器都有自己的迭代器 迭代器指向元素 类似指针！用它需要解引用* *it就是v1

~~~
 vector<vector<int>>::iterator it ; //每个容器都有自己的迭代器 迭代器指向元素 类似指针！用它需要解引用* 才可以访问到元素  it = vv.begin() *it就是v1
    // for(it = vv.begin();it != vv.end();it++) 
    // {
    //     vector<int>::iterator mit;
    //     for(mit = (*it).begin();mit != (*it).end();mit++)
    //     {
    //         cout << (*mit) <<"  ";
    //     }
    //     cout <<endl;
    // }
~~~



2. vector< >  为类模板 / 容器模板  vector<容器存储的类型 >  

~~~ 
vector<vector<int>>vv;  容器存储的是vector<int>
~~~

3. 迭代器访问嵌套容器
   1. 基本
      1. 迭代器类似指针  *解引用才能访问到内部元素
      2. *it  解引用一层迭代器 到 下一层   ( * it)到了一层容器 对于容器继续迭代 (    *   it ) .begin() 指向容器的第一个
      3. 对于2层 解引用两层就到了具体元素了 n-----n
      4. 迭代器类似指针  可以借助指针与内存空间想象判断
   2. 遍历过程：
      1. 迭代指向第一个  一直到最后一个 确保该容器每一个都被访问到
      2. 解引用 (*it)深入下去 到达第一个元素  也是容器   命名新的迭代器指向第一个  最后 是end 
      3. 解引用 进入容器内元素  为值 那么可以打印了
      4. 指针指向容器  一层  解引用  便为容器中的值

``` 
 // for(it = vv.begin();it != vv.end();it++) 
    // {
    //     vector<int>::iterator mit;
    //     for(mit = (*it).begin();mit != (*it).end();mit++) //2.
    //     {
    //         cout << (*mit) <<"  ";
    //     }
    //     cout <<endl;
    // }
```

4. swap  匿名对象假对象 缩小无用空间 

~~~
vector<int>(v1) 创造假对象 拷贝v1有效值
.swap(v1); 与v1交换
v4.swap(v1);//一般v4 v1全部交换 容量也会交换  匿名对象不会
~~~


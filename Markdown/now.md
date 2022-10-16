1. vector

   1. 初始化字段？

   2. ~~~c++
      使用初始化列表来初始化字段
      Line::Line( double len): length(len)
      {
          cout << "Object is being created, length = " << len << endl;
      }
      
      Line::Line( double len)
      {
          length = len;
          cout << "Object is being created, length = " << len << endl;
      }
      ~~~

   3. **析构函数**

      1. 析构函数名字必须和类名一致

      2. 它会在每次删除所创建的对象时执行。

      3. ![img](https://img-blog.csdn.net/20180801190541868?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzMzNzU3Mzk4/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

         从这里也可以发现，此时析构函数并没有被执行，它在system之后，return之前执行

   4. 

2. python 语法

3. 大物做题

4. 离散视频

5. 线代技巧方法
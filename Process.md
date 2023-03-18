字符数组存储0-----f 进行十六进制输出

直接转化hex 进制 uppercase 大写 lowercase

~~~
#include <bits/stdc++.h>

using namespace std;
long long a;
char Hex[20] = "0123456789ABCDEF";
int b[10100];
int main()
{
    cin >> a;
    cout << hex << uppercase << a;
    return 0;
}
~~~

### Cout使用

[(24条消息) c++ 总结之 cout输出_陌^_^路的博客-CSDN博客](https://blog.csdn.net/weixin_60634144/article/details/126257256)

0 1 1 2 3 5 8 13 21 34 

（1 + 1 ） % 10

7-18

[题目详情 - 7-18 逆序对 (pintia.cn)](https://pintia.cn/problem-sets/1611620996711464960/exam/problems/1611623301280165905)

取余具有分配律 

斐波那契  模的和 的 模 == 和的模 所以 对于 每一项   

7-19 字符与最值的对应

[题目详情 - 7-19 大写字母的序列 (pintia.cn)](https://pintia.cn/problem-sets/1611620996711464960/exam/problems/1611623301280165906)





7-21

bool boolArray[16] = {1}; // 这种方式只会将第一个bool值初始化为true，其他都是false。

全部初始化



~~~~~
bool boolArray[16] = {0};
~~~~~



~~~
bool boolArray[16];
memset(boolArray, 1, 16 * sizeof(bool));
~~~

7-25 爱是晒 如果m是合数必定由 比自身小的数字组成  x  *  y = m 由x即可筛去

y也可以筛去  所以 i 到 n^1/2即可筛去了

 利用 i 对 0-n中是i的倍数 进行删除

for( i * i in 0 -n)

for(j in i ---- n  j += i)



pair vector 联合 储存pair数组   pair可以存储 整体信息

~~~
vector<pair<char,int>> ans;
    for (int i = 0, cnt = 0; i < N; i++)
       if (word[i] && i!=' ') {
           ans.push_back({i, word[i]});
       } 
~~~





数组与下标 下标含义的对应

7-36 输入计算后  变成 索引

~~~
//对输入进行计算后索引

//对数字进行索引

#include<bits/stdc++.h>

using namespace std;
const int N = 110;
string fa;//保存字符串
int w[11];//索引对应后 保存
int main()
{
    while(cin>>fa)
    {
        for(int i = 0;i<fa.length();i++)
        {
            w[fa[i] - '0']++;    
        }
        for(int i = 0;i<=9;i++)
        {
            cout<< i << ":"<<w[i]<<endl;
        }
        memset(w,0,11 * sizeof(int));
    }
    return 0;
}
~~~

7-37

行数与输出关系 这里需要深度探究一下

如何推的  一个一个符号输出  与  行数



7-39

pair如何使用

~~~
pair<int,string> p(2,"was");
pair.first pair.second = "are";
~~~

作用：

对于一对相关系的数据可以进行存储

比如 一段序列的最小值与最小值的下标

7-40 

对于 非方阵如何转职输出 

方阵利用 列不变 行变   非方阵也是这样? 对行列输出 进行m n限制~!

1. 行不动 / 列不动 决定了 如何输出 
2. 行数 列数  决定了边界是多少 



~~~
#include<bits/stdc++.h>
//对于任意阵  不仅仅是方阵来说

using namespace std;
const int N = 1010;
int m,n;
int f[N][N];
int main()
{
    cin>>m>>n;
    for(int i = 0;i<m;i++)
        for(int j = 0;j<n;j++)
            cin>>f[i][j];

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            printf("%4d",f[j][i]);
        }
        printf("\n");
    }
    return 0;
}
~~~





7-42 排序后 二分搜索数字  从左到右依次搜索 

n  *  log n + n * n   

集合 唯一性 类似排列 

$O(n\log(n)+n^2)$

$O(n \log(n) + n^2)$

7-43

五子棋好题    

边界j + 4 < N 最大 N-1 

1. 基于 五子棋排列成五个的方式  进行判断 边界
   1. 如果斜左上 那么  i - 4>=0 j+4<N  斜左上排列方式 是i - 4 >= 0 j+4<N
2. 字符串输入 切记回车！！！ getchar()

7-48 字符排队：

~~~
bool cmp(string a, string b)
{
	return strcmp(a.c_str(), b.c_str()) < 0;
}
前一个 字典序 小于 后一个 
决定小于0  那么  就是升序
~~~

**7-44 莫尔斯码（Morse Code）**

1. 写法细节：
   1. pair二元组存储  莫斯科 字符关系
   2. while()等待保存 保存字符 余下为 小判断

**7-45 部分排序**

冒泡排序的细节

~~~
for	比较次数    长度n  n - 1次 
	for 下标  开始下标也很重要！！！容易出错  结束下标  取极限默认 j  j + 1  比较 最大 n - 2 
~~~

**7-49 汉诺塔问题**

~~~
void obs(int n,char ch1,char ch2,char ch3) //含义 n个盘子 移动
里面包含 //把 n-1 个移动到暂时地方
obs(n-1,ch1,ch3,ch2); 
move(ch1,ch2);//移动
void obs(int n,char ch1,char ch2,char ch3) //再继续移动 n - 1个
~~~

***2022年团体程序设计天梯赛***

1. 一维数据存储二维空间
   1. i行 存储范围： ( i -1 ) *  m  + 1   (i  - 1) * m  + m  (i = (c-1) * m  + 1,j = 1  , j<=m; i++,j++ )
      1. j = 1, (c-1) * m  + j j<=m;j++
   2. j列 存储范围：(j  j + m   j + 2 m ..... j + (n - 1) * m ) ( i =  c  j = 0, j<n;j++, i += m )



~~~
if(!t)// 0 行改变
        {
            //如何在一维中访问 二维存储的数据呢
            //行 i 行 (i - 1) * m   (i - 1) 行
            for(int i = (c-1)*m + 1,j = 1;j<=m;i++,j++) //一行m个元素 访问 m 个元素即可
            {
                //c行进行修改
                state[i] = true;//可以被放技能
                
            }

        }else{
            //访问列  c列  c += m  对于 c列 向下 都 迭代加 m
            for(int i = c,j = 1;j<=n;i += m,j++) //2行 最多加 1 次  n行加n - 1次  j起记录次数作用  j 为1 时候 + 0个m
            {
                state[i] = true;//  j最后为n 加n - 1个m 到第n行
            }
        }
~~~

时间转化 时分秒

~~~
sscanf(string,"%d:%d:%d - %d:%d:%d");
sscanf(s.c_str(),"%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
~~~

一天的时间是独立的

所以我们可以用数组对时间进行标记啊

~~~
for(int i = 0;i<86400-1;i++)
{
			
}

~~~

对左闭右开  利于标记 最后一个  

~~~
for(int i = sum1;i<sum2;i++)
{
	
}
~~~

然后变成了数组模型





序列  数字出现次数用数组保存  那么 其前缀和 就是  小于h[i] 的个数  

线段树，树状数组可以更新前缀和i 

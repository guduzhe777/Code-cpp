#include <iostream>
#include<string.h>
//
using namespace std;

int main()
{
    //核心原理：  每次都找到该串（不含有该元素的前面所有！）的最大 次大 次次大。。。的最大相同前后缀长度
    //判断 该元素 与 前缀后面的那个是否相等 相等那么++  不等 找次大（下一级的最大）
    //看这个次大的 前缀后面元素 和这个元素是否相等
    // but import：！！！：最大里面含有次大   通过最大的前缀部分 后面那个元素 找到次大的前缀！（画个图）
    //画个图自然可以看出来
    //最大的前缀部分 中的最大（次级大） 被保存在 前缀最大部分 后一个元素下标t next[t]之中了
    //你问我  他是最大前缀的最大了  但是他是 整个串的次级大么？   你能不能找到比他大   比最大小的？  你说能
    //不可能的！   我保存的就是最大的！
    char arr[21];
    char most[31];
    int next[22];
    int n = 0, m = 0;
    scanf("%s%s",most,arr);
    n = strlen(arr);
    m = strlen(most);
   //长度为n
    //该元素前面的最大相同前后缀长度 保存在后面一个

    next[0] = -1;
    next[1] = 0;
    int i = 1, j = 0;
    while (i < n)
    {
        if (j == -1 || arr[i] == arr[j])
        {
            next[++i] = ++j; //认为 1.前缀 有几个相同   2.下一次比较的位置
        }
        else
        {
            j = next[j]; ///画个图 最大前缀 后缀中含有次级大  次级大被保存在 next[t]中 (前缀的后一个)
        }
    }
    int s = 0, t = 0;
    while ((s < m)&&(t<n))
    {
        
        if (t == -1 ||most[s] == arr[t])
        {
            s++;
            t++;
        }
        else
        {
            t = next[t];
           
        }
    }
    if(t == n)
    {
        printf("Yes");
        
    }
    else{
        printf("No");
    }
    return 0;
}
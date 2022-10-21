#include<iostream>
#include<vector>
using namespace std;
//创造数 
//计算数字多个数字  判断是不是在数组的的数字之中
int isin(int mul,int arr[],int len)
{
    //普通的两个数组个元素比较
    int tem[11],n = 0,flag = 0;//0 为目前没有对应
    while(mul / 10)
    {
        tem[n] = mul%10;
        mul /= 10;
        n++;
    }
    tem[n] = mul;
    for(int i = 0;i<n;i++)//每一个值看原数组有没有对应
    {
        flag = 0;//0 为目前没有对应 
             
        for(int j = 0;j<len;j++)
        {
            if(arr[j] == tem[i]){
                flag = 1;break;
            } 
        }
        if(flag == 0)   //确实一个也没有找到
        {
            return 0;
        }
    }
    return 1;
}

void test0()
{
    int a,b,c,d,e,arr[11],i = 0,mul1,mul2,mul3,n = 0;
    // while((i<11)&&(scanf("%1d",&arr[i])))//输入数字???为什么不行
    // {
    //     i++;
    // }
    for(i=0; ; i++)
    {
        if(scanf("%1d",&arr[i]))  n++;
        else  break;
    } 
    for(int j = 0;j<i;j++)
    {
        if(arr[j]) a = arr[j];//第一个数字不能为0
        else continue;  //不然重新为第一个赋值
        for(int k = 0;k<i;k++)
        {
            b = arr[k];
            for(int s = 0;s<i;s++)
            {
                c = arr[s];
                for(int m = 0;m<i;m++)
                {
                    if(arr[m]) d = arr[m];//第一个数字不能为0
                    else continue;  //不然重新为第一个赋值    
                    for(int n = 0;n<i;n++)      //取得数字
                    {
                        e = arr[n];
                        //开始计算  判断数字是否属于原本集合中的   
                        mul1 = (a * 100 + b * 10 + c) * e;
                        mul2 = (a * 100 + b * 10 + c) * d;
                        mul3 = (a * 100 + b * 10 + c)  * (d * 10 + e);
                        if((isin(mul1,arr,i))&&(isin(mul2,arr,i))&&(isin(mul3,arr,i)))
                        {
                            printf("a:%d b：%d c:%d d：%d e:%d mul1:%d mul2:%d mul3:%d数字匹配集合\n",a,b,c,d,e,mul1,mul2,mul3);
                        }
                    }    
                }
            }
        }
    }
}

void test1()
{
    int m,n;
    while(cin >> n>>m)//先输入个头
    {
        int sign = 0;//在寻找的过程开始未找到
        for(int x = 0;x<=n;x++)//鸡子的数量 寻找的过程
        {
            if(4 * n-2 * x == m)
            {
                sign = 1;//找到了
                cout << x << " "<< n - x<<endl;
            }
        }
        if(!sign)
        {
            cout << "No answer"<<endl;
        }
    }

}
int main()
{   
    //test0();
    test1();
    return 0;
}
//思路一，方法一:用数组实现
//整体思路：从所给集合中挑取三位数乘两位数，进行判断；  参考代码的思路是穷举出所有三位数乘两位数的情况在进行判断
//步骤如下：①确定abc和de--这就是那个五重循环 ②判断x,y,z是否满足要求
//注意，输入时，输完数字，要ctrl+Z 再按回车才能输入
// #include<stdio.h>
// int IsIn(int x, int array[], int n);
// int main()
// {
//     int a, b, c, d, e, n = 0, count = 0, array[10];
//     for(int i=0; ; i++)
//     {
//         if(scanf("%1d", &array[i]))  n++;
//         else  break;
//     }
//     for(int i=0; i<n; i++)
//     {
//         if(array[i])  a = array[i];
//         else  continue;
//         for(int j=0; j<n; j++)
//         {
//             b = array[j];
//             for(int k=0; k<n; k++)
//             {
//                 c = array[k];
//                 for(int s=0; s<n; s++)
//                 {
//                     if(array[s])  d = array[s];
//                     else  continue;
//                     for(int t=0; t<n; t++)
//                     {
//                         e = array[t];
//                         int x = (100*a + 10*b + c) * e;
//                         int y = (100*a + 10*b + c) * d;
//                         int z = (100*a + 10*b + c) * (10*d + e);
//                         if(IsIn(x, array, n) && IsIn(y, array, n) && IsIn(z, array, n))
//                         {
//                             printf("<%d>\n", ++count);
//                             printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", 100*a+10*b+c, 10*d+e, x, y, z);
//                             /*
//                             printf("  %d", 100*a+10*b+c);
//                             printf("X  %d\n", 10*d+e);
//                             printf("-----\n");
//                             if(!x)  printf("    0\n");
//                             else
//                             {
//                                 if(x / 1000 == 0)  printf("  %d\n", x);
//                                 else  printf(" %d\n",x);
//                             }
//                             if(y / 1000 == 0)  printf(" %d\n", y);
//                             else  printf("%d\n",y);
//                             printf("-----\n");
//                             if(z / 10000 == 0)  printf(" %d\n", z);
//                             else  printf("%d\n", z);
//                             printf("\n");
//                             */
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     printf("The number of solution is %d", count);
//     return 0;
// }

// int IsIn(int x, int array[], int n)
// {
//     int split[5], flag = 0;
//     split[0] = array[0];
//     split[1] = array[1];
//     if((x % 100) && (x / 1000 == 0))
//     {
//         split[2] = x / 100;  split[3] = x / 10 % 10;  split[4] = x % 10;

//     }
//     else if((x % 1000) && (x / 10000 == 0))
//     {
//         split[1] = x / 1000;  split[2] = x / 100 % 10;  split[3] = x / 10 % 10;  split[4] = x % 10;
//     }
//     else
//     {
//         split[0] = x / 10000;  split[1] = x / 1000 % 10;  split[2] = x / 100 % 10;  split[3] = x / 10 % 10;  split[4] = x % 10;
//     }
//     for(int i=0; i<5; i++)
//     {
//         flag = 0;
//         for(int j=0; j<n; j++)
//         {
//             if(split[i] == array[j])  {flag = 1; break;}
//         }
//         if(flag == 0)  return 0;
//     }
//     return 1;
// }

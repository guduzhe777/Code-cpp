#include<iostream>
#include<math.h>

using namespace std;


int main()
{
    int Old_Base,New_Base,num,arr[101],i = 0,sum = 0;
    cin>>Old_Base>>num>>New_Base;
    // //2022（9） 模10  乘 9^0 除 10  乘 9^1   2 .... 变成十进制
    // //
    // //其他>>>>>>十进制  各位 数字 乘以权重过程  

    // for(i = 0;num != 0;i++)     //转化为10进制
    // {
    //     sum += num % 10 * pow(Old_Base,i);
    //     num /= 10;
    // }

    // //sum 十进制
    // i= 0;
    // //模  下一个 

    // //十进制>>>>>>其他进制  求 余数过程

    // while(sum != 0) //转化为New_Base 新进制 
    // {
    //    arr[i++] = sum % New_Base;
    //    sum /= New_Base;
    // }
    // for(int j = i - 1;j>=0;j--)
    // {
    //     cout<<arr[j];
    // }
    for(i = 0;num != 0;i++)     //转换十进制
    {
        sum += num % 10 * pow(9,i);
        num /= 10;
    }
    i = 0;
    while(sum != 0) //求余数 转换其他进制
    {
        arr[i++] = sum % New_Base;
        sum /= New_Base;

    }
    for(int j = i - 1;j>=0;j--)
    {
        cout<<arr[j];
    }
    return 0;
}
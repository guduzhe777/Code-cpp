#include<iostream>

//一个数组 中两个数 求和 等于 target  
//有序
//无序

using namespace std;

//无序
 //1.暴力 无序
    //i j 指向前后 
    //输入 元素个数  数组值 target
//map记录  判断 target - x 在不在map中
//有序
//二分查找 target - x
//双指针  一个从左一个从右 中间靠拢
//＞ 则 r 左移动
int main()
{
   
    int n,target;
    cin >> n >> target;

    int arr[n];
    for(int i = 0;i< n ;i++)
    {
        cin >>arr[i];
    }
    for(int i = 0;i<n - 1 ;i++)
    {
        for(int j = i + 1 ;j < n;j++)
        {
            if(arr[i] + arr[j] == target)
            {
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    return 0;
}
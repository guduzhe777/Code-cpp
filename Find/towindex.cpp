#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

//双指针删除指定元素
//一快一慢 返回长度  遍历一次数组 从数组开始 如果找到 留下等待替换  没找到同时加加且替换  尽可能移动最少的元素  找到就被移动
int cmpint(const void* str1,const void* str2)
{
   return -(*((int*)str1)- *((int*)str2));
}
//默认降序
class solution{
    public:
        vector<int> arr();
        int deleVial_Same(int arr[],int vial,int n)
        {
            int slowindex = 0,fastindex = 0;
            for(fastindex = 0;fastindex<n;fastindex++)
            {
                if(vial != arr[fastindex])  //找到了
                {
                    arr[slowindex++] = arr[fastindex];//等待替换更好的 且 长度可以知道 
                }
            }
            return slowindex;//返回长度 （前面的元素个数）
        }
        //双向指针 一左一右目的寻找不同相同 交换  
        int deleVial_Diff(int arr[],int vial,int n)
        {
            int l = 0,r = n - 1;
            //一左寻找相同  一右寻找不同 交换 开始继续下一个   结束条件就是找完了 l>r/l<=r  了白 至于等于与否看自己思路
            while(l<=r)
            {
                while((l<=r)&&(vial != arr[l]))
            {
                ++l;
            }
            while((l<=r)&&(vial == arr[r])) //你和我相同？  直接跳过 
            {
                --r;
            }
            if(l<r)
            {
                arr[l++] = arr[r--];
            }
            }
            return l;//长度 前面元素个数
        }
        //双指针 有序数组的平方排序 基于有序：双向指针 保证了全为正 左负右正的情况 且 n
        //暴力：平方排序
        void Multwo_SortA(int arr[],int n)
        {
            for(int i = 0;i<n;i++)
            {
                arr[i] *= arr[i];
            }
            int sz = sizeof(arr[0]);
            qsort (arr, n,sz ,cmpint);
            
        }
        //双向 有序 确保时刻  比较为最大。
        vector<int> Multwo_SortB(int arr[],int n)
        {
            vector<int> results(n);
            int i = 0,j = n-1,k = 0;

            while(i<=j)
            {
                if(arr[i] * arr[i]<arr[j]*arr[j])
            {
                results[k++] = arr[j] * arr[j];
                j--;
            } else{
                results[k++] = arr[i] * arr[i];
                i++;
            }
            }
            return results;
        }
};

int main()
{
    int arr[101],n,target;
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
   // cin >>target;
    solution s;
    
    //int len = s.deleVial_Same(arr,target,n);
    //int len = s.deleVial_Diff(arr,target,n);
    vector<int> results(n);
    results = s.Multwo_SortB(arr,n);
    s.Multwo_SortA(arr,n);
    for(int i = 0;i<n;i++)
    {
        //cout << results[i]<<endl;
        cout << arr[i]<<endl;
    }
 
    return 0;
}
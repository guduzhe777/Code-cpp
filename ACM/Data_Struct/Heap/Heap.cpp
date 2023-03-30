#include<bits/stdc++.h>

using namespace std;

int arr[10] = {8,6,2,4,5,1,7,2,9,10};
void heapify(int* arr,int n,int i)//i：需要维护的父节点
{
    int larger = i;//假设最大为父亲
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;//儿子们
    //找出最大
    if(lchild<n&&arr[larger]<arr[lchild])//有孩子 然后 维护 这三个节点
    {
        //swap(arr[lchild],arr[larger]);
        larger = lchild;
    }
    if(rchild<n&&arr[larger]<arr[rchild])
    {
        //swap(arr[rchild],arr[lchild]);
        larger = rchild;
    }//有孩子维护三个节点
    if(larger != i)//最大不是父亲
    {
        swap(arr[larger],arr[i]);//最大值放到 父节点
        heapify(arr,n,larger);//larger 现在指向原本最大的 不过 被交换了的节点
        //维护 后续子节点
    }
}
void heap_sort(int arr[],int n)//无序数组 ，长度
{
    //建堆
    for(int i = (n - 1 - 1)/2;i>=0;i--) //-1 是 数组最后一个下标， -1 是2*i+1 2*i+2
    {
        heapify(arr,n,i);//建堆
    }
    ///排序  ： 堆 根节点（最大值） 放到 最后 后维护 堆
    for(int i = n - 1;i;i--)//i：最后一个元素下标
    {
        swap(arr[i],arr[0]);
        heapify(arr,i,0);//从第一个开始 （其他已经是大顶堆）维护大顶堆
    }
}
int main()
{
    for(int i = 0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    cout<<endl;
    heap_sort(arr,10);
    for(int i = 0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}




#include<iostream>


using namespace std;
void merge(int arr[],int TempArr[],int left,int mid,int right)
{
    //同一层的排序 
    //左半区 右半区元素比较  放入 最后  对最后的归并  最后放在原数组
    //左半部分第一个  右半部分第一个  临时数组指向 分别用于比较保存
    //左半部分第一个
    int l_pos = left; 
    //右半部分第一个 
    int r_pos = mid + 1;
    //临时数组指向 
   /// int pos = 0; 从分区的最左边开始！！！
   int pos = left; //从分区的最左边开始！！！
    while((l_pos<=mid)&&(r_pos<=right))
    {
        if(arr[l_pos]<=arr[r_pos])  //这样不会造成 r_pos = len 可能不稳定 假如就两个元素且相等 小于号 会造成r_pos=len然后跳出循环
        {
            TempArr[pos++] = arr[l_pos++];
        } 
        else{
            TempArr[pos++] = arr[r_pos++];    
        }      
    }
    //一区终于放完  我们继续归并 可能左 / 右
    //我们继续归并 左
    while(l_pos<=mid)
    {
        TempArr[pos++] = arr[l_pos++];
    }
    //我们继续归并 右
    while(r_pos<=right)
    {
        TempArr[pos++] = arr[r_pos++];
    }
    //归并完成 复制到原数组
   // pos = 0;//不一定一直是0  而是 左半部分第一个
    while(left<=right)
    {
       //arr[left++] = TempArr[left++];
       arr[left] = TempArr[left];
       left++;
    }

}
//int *TempArr 与 int TempArr[]接收内存空间区别
void MergeSort(int arr[],int TempArr[],int left,int right)
{
    //判断左边大于右边
    //一直划分 直到 只剩下一个 ×
    //一直左，右边各自划分
    //合并
    if(left < right)  
    {
        int mid = (left + right)/2;

    //左边划分
    MergeSort(arr,TempArr,left,mid);//左边
    MergeSort(arr,TempArr,mid+1,right);//右边 
    //合并及排序
    merge(arr,TempArr,left,mid,right);
    }
}
void Msort(int arr[],int len)
{
    //归并排序
    //临时数组保存
    //
    //int * TempArr = (int *)sizeof(len * sizeof(int));///自动给我分配 Len * int个空间 且独立？
    int TempArr[len];
    MergeSort(arr,TempArr,0,len - 1);
}
int main()
{
    int arr[10] = {5,4,8,6,9,10,56,7,2,3}; 
    int sz = sizeof(arr) / sizeof(int);
    Msort(arr,sz);
    for(int i = 0;i<10;i++)
    {
        cout << arr[i] <<endl;
    }

    return 0;
}
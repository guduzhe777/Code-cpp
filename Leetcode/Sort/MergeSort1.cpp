#include<iostream>

using namespace std;

//归并排序 分割 临时储存 赋值
//左，右分割 到仅剩下一个 下标来表示   
//归并
// 排序+归并
//两个简单数组基于下标比较（r l来作为结束条件）  放入 临时数组中 
//继续放到临时数组中（下标作为判断条件）
//最后临时数组赋值到数组中
//数组  临时数组   左  右下标
void Merge(int arr[],int TempArr[],int left,int mid,int right)  //mid作用：在哪里分割下标 临界//归并
{
    int l_pos = left,r_pos = mid+1,pos = left;//上面传入为界限作用 这里为移动赋值作用
    while((l_pos<=mid)&&(r_pos<=right))
    {
        if(arr[l_pos]<arr[r_pos])
        {
            TempArr[pos++] = arr[l_pos++];
        }
        else{
            TempArr[pos++] = arr[r_pos++];
        }
    }
    while(l_pos<=mid)
    {
        TempArr[pos++] = arr[l_pos++];
    }
    while(r_pos<=right)
    {
        TempArr[pos++] = arr[l_pos++];
    }
    while(left<=right)
    {
        arr[left] = TempArr[left];
        left++; 
    }
}
void MergeSort(int *arr,int *TempArr,int left,int right)
{
    if(right - left + 1 == 5)
    {
        int mid = (left + right)/2;
        MergeSort(arr,TempArr,left,mid);    //右分割
        MergeSort(arr,TempArr,mid + 1,right);//左，右分割 到仅剩下一个 下标来表示
        Merge(arr,TempArr,left,mid,right);  //mid作用：在哪里分割下标 临界//归并
    }
    else{
        
    }
}
void MSort(int arr[],int len)
{
    int *TempArr = (int *)malloc(len * sizeof(int));//继续放到临时数组中（下标作为判断条件）
    MergeSort(arr,TempArr,0,len - 1);
}
int main()
{   
    int n;
   cin >>n;
    int arr[101];
    for(int i =0;i<n;i++)
    {
        cin >>arr[i];
    }
    MSort(arr,n);
    for(int i =0;i<n;i++)
    {
        cout <<arr[i];
    }

    return 0;
}
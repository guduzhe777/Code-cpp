#include<bits/stdc++.h>

using namespace std;
//归并： 先分 再和
//l mid  mid+ 1 right 两个区间 
//对新的有序区间 进行一个一个比较
//临时数组保存后  赋值到  输入数组
const int N = 1e5+10;
int num[N];
int n;
void  mege_And(int num[],int tem_arr[],int l,int mid,int r)
{
    int l_pos = l,r_pos = mid+1;//起始点
    int pos = l;
    
    while((l_pos<=mid)&&(r_pos<=r))
    {
        if(num[l_pos]<=num[r_pos])
        {
            tem_arr[pos++] = num[l_pos++];//左边小
        }else{
            tem_arr[pos++] = num[r_pos++];//右边小
        }
    }
    //比完了  余下的依次补上去
    while(l_pos<=mid)
    {
        tem_arr[pos++] = num[l_pos++];
    }
    while(r_pos<=r)
    {
        tem_arr[pos++] = num[r_pos++];
    }
    //全部放完 归还到 数组之中
    while(l<=r)
    {
        num[l] = tem_arr[l];
        l++;
    }
}
void merge_Dvid(int num[],int l,int r)
{
    if(l<r)
    {
        int mid = (r-l)/2 + l;
        
        int tem_arr[N];
        merge_Dvid(num,l, mid);
        merge_Dvid( num, mid+1, r);
        mege_And(num,tem_arr,l,mid,r);
        
    }
}
void merge_Sort(int num[],int len)
{
    merge_Dvid(num,0,len-1);
}
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    
    merge_Sort(num,n);
    for(int i = 0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;
}
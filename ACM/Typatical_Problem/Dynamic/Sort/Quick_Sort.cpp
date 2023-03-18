#include<bits/stdc++.h>


using namespace std;

int arr[10] = {6,4,8,10,8,7,2,1,11,3};

void Qucik_Sort(int arr[],int l,int r)
{
    int base = arr[l],l_pos = l,r_pos = r;
    if(l_pos>=r_pos) return; //左边大于右边 返回
    while(l_pos<r_pos)
    {
        //以左为基准
        
        while(r_pos>l_pos&&arr[r_pos]>=base)
        {
            r_pos--;
        }
        while(l_pos<r_pos&&arr[l_pos]<=base)
        {
            l_pos++;
        }
        if(l_pos<r_pos)
        {
            int tem = arr[l_pos];
            arr[l_pos] = arr[r_pos];
            arr[r_pos] = tem;
        }
    }
    //到了 l = r 基数位置找到了  左边都是比他大的 右边都是比他小的
    arr[l] = arr[l_pos];//找到 左边 都比他小 右边都比他大
    arr[l_pos] = base;
    for(int i = 0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    Qucik_Sort(arr,l,l_pos-1); //该点的左 
    Qucik_Sort(arr,l_pos+1,r);//该点的右边
}
int main()
{
    Qucik_Sort(arr,0,9);
    for(int i = 0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}
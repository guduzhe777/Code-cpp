#include<iostream>

using namespace std;
int min(int x,int y)
{
	return (x<y)?x:y;
}
void mergesort(int arr[],int left,int l_end,int r_end)
{
	int temparr[101],l_pos = left ,r_pos = l_end +1,pos = left;
	while((l_pos<=l_end)&&(r_pos<=r_end))
	{
		if(arr[l_pos]<arr[r_pos])
		{
			temparr[pos++] = arr[l_pos++]; 	
		}
		else{
			temparr[pos++] = arr[r_pos++];
		}
	}
		while((l_pos<=l_end))
	{
		temparr[pos++] = arr[l_pos++]; 	
	}
		while((r_pos<=r_end))
	{
			temparr[pos++] = arr[r_pos++];
			
	}
	while(left<=r_end)
	{
	arr[left] =	temparr[left];
	left++;
	}
}

void merge(int arr[],int left,int mid,int right)
{
    //同一层的排序 
    //左半区 右半区元素比较  放入 最后  对最后的归并  最后放在原数组
    //左半部分第一个  右半部分第一个  临时数组指向 分别用于比较保存
    //左半部分第一个
    int l_pos = left; 
    //右半部分第一个 
    int r_pos = mid + 1;
    //临时数组指向 
    int TempArr[101];
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
int main()
{
	//倍增下标 访问数组元素
	//记录每次半数列多少个合并  curr
	//记录开始 left += 2*curr(在操作中一个left对应2 * curr空间) 记录左尾部   记录右尾部  排序合并
	 //
	 int n,arr[101];
	 cin >>n;
	for(int i =0;i<n;i++)
	{
		cin >> arr[i];
		}	
	int left,curr,r_end,l_end;//开始下标  多少个元素  左右结尾
	
	for(curr = 1;curr<=n-1;curr = 2 * curr)
	{
		for(left = 0;left<=n-1;left += 2 * curr)
	{
			//开始计算
			//左结尾  右结尾 防止结尾越界 当访问超过元素个数 直接到最后一个元素 并入即可
			l_end = min(left + curr -1,n-1);
			r_end = min(left + 2 * curr -1,n-1);			
			mergesort(arr,left,l_end,r_end);
	}
	}
	for(int i =0;i<n;i++)
	{
		cout<< arr[i];
		}	
	return 0;
}
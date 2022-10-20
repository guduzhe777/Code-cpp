#include<iostream>




using namespace std;

int max(int x,int y)
{
    return x>y?x:y;
}

int part_find_max(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid = (l + r)/2;
        int ret1 = part_find_max(arr,l,mid);
        int ret2 = part_find_max(arr,mid+1,r);
        return max(ret1,ret2);      //分治到倒数第二低  开始计划怎么写
    }
    else{               //递归终止条件
        return arr[l];
    }
}
//分治 大
void test0()
{
    int cnt;
    scanf("%d",&cnt);
    while(cnt--)
    {
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i = 0;i<n;i++)
        {
            cin >> arr[i];
        }
        int ret = part_find_max(arr,0,n-1);
        printf("%d\n",ret);
    }
}
int obs(int n)
{
    if(n == 1||n == 2)
    {
        return 1;
    }
    return obs(n - 2) + obs(n-1);  //由前两个求出来的
}
//斐波那契
void test1()
{
    int cnt;
    cin >>cnt;
    while(cnt--)
    {
        int n;
        cin >>n;
        int ret = obs(n);
        printf("%d\n",ret);
    }
}
//same 约
int same_yue(int x,int y)
{
    //
    int tem = 0;
   
    do{
        tem = x % y;
        x = y;
        y = tem;
     }
     while(tem);
     return x;
}
//same 约
void test2()
{
    int cnt;
    cin >>cnt;
    while(cnt--)
    {
        int m,n;
        cin >>m >>n;
        int ret = same_yue(m,n);
        printf("%d\n",ret);
    }
} 
//分治 求最小  分分分 最后 每一步都最小  递归
int min(int x,int y)
{
    return x<y?x:y;
}
int part_find_min(int arr[],int l,int r)
{
    if(l < r)
    {
        int mid = (l + r) /2;
        int ret1 = part_find_min(arr,l,mid);
        int ret2 = part_find_min(arr,mid + 1,r);   //一直分分分  分到最后两个开始计算大小然后返回让两个值再比再返回
        return min(ret1,ret2);
    }   
    else{
        return arr[l];
    }
}
//min
void test3() //一直分分分  分到最后两个开始计算大小然后返回让两个值再比再返回
{
    int n,m,arr[101];
    cin >>n;
    while(n--)
    {
        cin >>m;
        for(int i = 0;i<m;i++)
        {
            cin >>arr[i];
        }
        int ret = part_find_max(arr,0,m-1);   //采取最右边可以取到
        cout << ret <<endl;     
    }   
}
//分治 大和小
void test4()
{
    int n,m,arr[101];
    cin >>n;
    while(n--)
    {
        cin >>m;
        for(int i = 0;i<m;i++)
        {
            cin >>arr[i];
        }

        int ret1 = part_find_max(arr,0,m-1);   //采取最右边可以取到
        int ret2 = part_find_min(arr,0,m-1); 
        cout << ret1 <<" " << ret2 <<endl;     
    }   
}
void merge(int arr[],int l ,int mid,int r,int Temarr[])
{
    //两个数列进行比较
    int l_pos = l,r_pos = mid + 1,pos = l;//你要知道进来的值不一定下标是0 ！！！ 另一半呢第一个不是0 且你需要赋值一一对应
    //这边的数列有多少个值 那么进入tem里面就有多少  所以你需要从开始下标开始一一赋值
    while((l_pos<=mid)&&(r_pos<=r))
    {
        if(arr[l_pos]<arr[r_pos])
        {
            Temarr[pos++] = arr[l_pos++];
        }
        else{
            Temarr[pos++] = arr[r_pos++];
        }
    }
    while(l_pos<=mid)
    {
        Temarr[pos++] = arr[l_pos++];
    }
    while(r_pos<=r)
    {
        Temarr[pos++] = arr[r_pos++];
    }
    while(l<=r)
    {
        arr[l] = Temarr[l];
        l++;
    }
}
 void Merge_Sort(int arr[],int l,int r,int Temarr[])
 {
    if(l<r)
    {
        int mid = (l+r) / 2;
        Merge_Sort(arr,l,mid,Temarr);
        Merge_Sort(arr,mid+1,r,Temarr);
        merge(arr,l,mid,r,Temarr);
    }
    else{
        return;
    }
 }
//归并求第k小的值

void  test5()
{
    int n,m,arr[101],k;
    cin >>n;
    cin >>m>>k;
    while(n--)
    {
        
        for(int i = 0;i<m;i++)
        {
            cin >>arr[i];
        }
        int Temarr[101];
        Merge_Sort(arr,0,m-1,Temarr);
        cout << arr[k-1]<<endl;
    }   
}

int main()
{
    //test0();
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    return 0;
}
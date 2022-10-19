#include<iostream>




using namespace std;

int max(int x,int y)
{
    return x>y?x:y;
}
int partit(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid = (l + r)/2;
        int ret1 = partit(arr,l,mid);
        int ret2 = partit(arr,mid+1,r);
        return max(ret1,ret2);      //分治到倒数第二低  开始计划怎么写
    }
    else{               //递归终止条件
        return arr[l];
    }
}

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
        int ret = partit(arr,0,n-1);
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

int main()
{
    //test0();
    //test1();
    test2();
    return 0;
}
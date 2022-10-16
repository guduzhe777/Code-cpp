#include <iostream>


//暴力 从2 - 根n  看有没有因数  如果没有 那么后半部分没有乘的数 所以没有
//i * i 更好表示  且等于号 防止25 这类情况
int isPrime(int n)
{
    int i,j;

    for(int i = 2;i * i <=n;i++)
    {
        if(n % i == 0)
        {
            return 0;   //不是素数
        }
    }
    return 1;//是素数

}
bool isEratosPrime(int n)
{
    int i,j;
    bool arr[n];    //默认false  为素数
    arr[1] = true;
    for(int i = 2;i<n;i++)  
    {
        if(!arr[i])     //防止多次筛  所以用素数筛  且 素数筛可以全部筛完
        {
            for(int j = i * i;j<=n; j+= i)      //i * i开始 去除已经晒出来的 为什么替换i 因为 只有i * i无法被替换前面那个数一直是2  
            {
                arr[j] = true;
            }
        }


    }
    return !arr[n];   //素数返回true

}
void PrintEratosPrime(int n)
{
    int i,j;
    bool arr[n];    //默认false  为素数
    arr[1] = true;
    for(int i = 2;i<n;i++)  
    {
        if(!arr[i])     //防止多次筛  所以用素数筛  且 素数筛可以全部筛完
        {
            for(int j = i * i;j<=n; j+= i)
            {
                printf("%d ",j);
            }
        }


    }
    

}
int main()
{
    int n;
    scanf("%d",&n);
    // if(isEratosPrime(n))
    // {
    //     printf("Yes");
    // }
    // else{
    //     printf("No");
    // }
    PrintEratosPrime(n);        //确实可以把合数全部晒出来
    return 0;
}
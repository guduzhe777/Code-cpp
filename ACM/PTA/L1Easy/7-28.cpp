#include<bits/stdc++.h>

using namespace std;
const int N = 10;
int f[N];
int a;
int i;
int sum = 0;//输入的求和
int main()
{
    while(scanf("%d",&a) != EOF)
    {
        sum = 0;//输入的求和
        for( i = 0;a != 0;i++)
        {
            f[i] = a % 10;
            a /= 10;
        }
        printf("%d ",i);//位数
        for(int j = i-1;j>=0;j--)
        {
            printf("%d ",f[j]);//每一位输出
            sum = f[i - j - 1]+ sum * 10;
        }
        printf("%d\n",sum);
        
    }
    
    
    return 0;
}
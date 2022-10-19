#include<iostream>




using namespace std;




int main()
{
    int n = 0,sum = 1,cnt = 0;
    scanf("%d",&cnt);
    while(cnt--)
    {
        scanf("%d",&n);    
        for(int i =1;i<=n;i++)
        {
            sum *= i;
        }
        printf("%d\n",sum);
        sum = 1;
    }

    return 0;
}
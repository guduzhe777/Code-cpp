#include<bits/stdc++.h>

using namespace std;
char ch;
int n;
int main()
{
    while(cin>>ch>>n)
    {
        for(int j = 1;j<=n;j++)
        {
             for(int i = 0;i<n-j;i++)
            {
                printf(" ");
            }
            for(int i = 1;i<=2 * j - 1;i++)
            {
                printf("%c",ch);
            }
            printf("\n");
        }
        for(int i = 1;i<n;i++)
        {
            for(int j = 1;j<=i;j++)
            {
                printf(" ");
            }
            for(int j =1;j<=2 * (n-i) - 1;j++)
            {
                printf("%c",ch);
            }
            printf("\n");
        }
        
    }
    //帅不帅 有声音 这是一次够无语的交易
    return 0;
}
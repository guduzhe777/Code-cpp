#include<bits/stdc++.h>
using namespace std;
string f;

int main()
{
    cin>>f;    
    int sum = 0;
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<8;j++)
        {
            sum += (f[i * 8 + j] - '0') <<(7-j);
        }
        printf("%d",sum);
        sum = 0;
        if(i != 3)
        {
            printf(".");
        }
    }
    
    return 0;
}
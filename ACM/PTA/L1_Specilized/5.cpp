#include<bits/stdc++.h>

using namespace std;



bool prime(int n)
{
    if(n == 1||n %2 == 0&&n != 2) return 0;
    else{
        for(int i = 3;i<=(int)sqrt(n);i += 2)
        {
            if(n % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int cnt = 0;
    for(int i = 2;i<=100;i++)
    {
        if(prime(i))
        {
            cnt++;
            printf("%6d",i);
        }
        if(cnt == 10)
        {
            cnt = 0;
            printf("\n");
        }
    }
    return 0;
}
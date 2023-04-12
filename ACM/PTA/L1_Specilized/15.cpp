#include<bits/stdc++.h>

using namespace std;

int n;
bool prime(int n)
{
    if(n == 1|| n%2 == 0&& n!=2) return 0;
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
    cin>>n;
    if(n>0&&prime(n))
    {
        printf("Yes\n");
    } else{
        printf("No\n");
    }
    return 0;
}
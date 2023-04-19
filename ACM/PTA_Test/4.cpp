#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mul;
ll a,b;
int main()
{

    cin>>a>>b;
    mul  = a + b;
    for(int i = mul - 1;i>1;i--)
    {
        mul *= i;  
    }
    printf("%lld",mul);
    return 0;
}
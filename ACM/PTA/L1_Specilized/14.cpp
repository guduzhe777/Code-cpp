#include<bits/stdc++.h>

using namespace std;

int n;
int main()
{
    cin>>n;
    n = abs(n);
    
    int a = log10(n);
    printf("%d\n",n != 0?a+1:1);
    return 0;
}
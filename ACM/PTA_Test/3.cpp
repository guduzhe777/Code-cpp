#include<bits/stdc++.h>

using namespace std;
int a,b;
int main()
{
    cin>>a>>b;
    int max_dog = max(a,b);
    int max_peo = a + b;
    printf("%d %d\n",max_dog<0?0:max_dog,max_peo <0?0:max_peo);
    if(a > b)
    {
        printf("T_T\n");
    }else if(a == b)
    {
        printf("-_-\n");
    }else{
        printf("^_^\n");
    }
    return 0;
}
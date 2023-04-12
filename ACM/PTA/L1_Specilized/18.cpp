#include<bits/stdc++.h>

using namespace std;

int a,b,x,y;
int main()
{
    while(cin>>a>>b>>x>>y)
    {
        if(pow(x,2)/pow(a,2) + pow(y,2)/pow(b,2)>1)
        {
            printf("out ellipse\n");
        }else{
            printf("in ellipse\n");
        }
    }

    return 0;
}
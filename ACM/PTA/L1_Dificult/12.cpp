#include<bits/stdc++.h>

using namespace std;
double n,h;
int main()
{

    cin>>h>>n;
    if(n == 0)
    {
        printf("0.0 0.0\n");
    }else if(n == 1)
    {
        printf("%.1lf %.1lf\n",h,h/pow(2,n));   
    }else{
        double sum = 3 * h - h/pow(2,n-2);
        h = h / pow(2,n);
        printf("%.1lf %.1lf\n",sum,h);
    }
    
    return 0;
}
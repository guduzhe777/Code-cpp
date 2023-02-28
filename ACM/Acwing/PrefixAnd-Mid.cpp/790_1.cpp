#include<bits/stdc++.h>

using namespace std;
double n;
int main()
{
    double l = -10000,r = 10000;
    double mid = (r-l)/2+l;
    scanf("%lf",&n);
    while(r - l>1e-8)
    {
        mid = (r-l)/2+l;
        if(mid * mid * mid == n)
        {
            break;
        }
        if(mid * mid * mid > n)
        {
            r = mid;
        }
        if(mid * mid * mid < n)
        {
            l = mid;
        }
    }
    printf("%lf",mid);
    return 0;
}
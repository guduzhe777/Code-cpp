#include<bits/stdc++.h>

using namespace std;

double r,h;
double cylinder(double r,double h)
{
    return acos(-1) * r * r * h;
}
int main()
{
    cin>>r>>h;

    double ret = cylinder(r,h);
    printf("%.3lf\n",ret);
    return 0;
}
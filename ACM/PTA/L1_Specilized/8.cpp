#include<bits/stdc++.h>

using namespace std;
#define deg(x) cout << #x << " = " << x << " ; "
double e;
double funpi(double e)
{
    double sum = 1;
    int si = 1;
    double n = 1;
    int cnt = 0;
    while(1.0/n >=e)
    {
        cnt++;
        n = 2 * cnt + 1;
        si = - si;
        sum += si * 1.0/n;
        
    }
    return sum;
}
int main()
{
    cin>>e;
    double ret = funpi(e);
    printf("pi = %.6lf",4.0 *ret);
    return 0;
}
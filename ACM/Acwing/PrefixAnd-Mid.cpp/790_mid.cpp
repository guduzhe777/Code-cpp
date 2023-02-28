#include<bits/stdc++.h>


using namespace std;
double n;
int main()
{
    scanf("%lf",&n);
    double l = -10000,r = 10000,m;
    while(r - l >1e-8)//在 r l 中选一个值  且这个值 
    {
        //结束条件？ 两个数字去逼近 这个符合条件的m   
        //10.000000001 10.0000001   他们之间的数字一定 精确到了 1e-6!
        //他们之间的范围 若<1e-8 他们精确到了 1e-8 输出他们之间的数字 精确到1e-8
        m = (r - l) /2 + l;
        if(m * m * m >= n) r = m;
        else{
            l = m;
        }
    }
    printf("%lf",m);
    return 0;
}
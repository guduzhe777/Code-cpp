#include<bits/stdc++.h>

using namespace std;
//因为条件是 看半径取值
//又因为 除法会导致0的出现，所以应该先除以b立即判断！  即： r /= b 紧接着 while(r)! 
//又因为

int t;
int r,a,b;
double ans;

int main()
{
    
    cin>>t;
    for(int cases = 1;cases<=t;cases++)
    {
        cin>>r>>a>>b;
        ans = 0;
        //ans = acos(-1) * r * r + acos(-1) * (a * r) * (a * r);
       // r *= a;
       // r /= b;
        while(r)
        {
            //先除以b 判断 再乘以a
            ans += acos(-1) * r * r;
            r *= a;
            ans += acos(-1) * r* r;
            r /= b;
        }
        printf("Case #%d: %.6lf\n",cases,ans);
    }


    return 0;
}
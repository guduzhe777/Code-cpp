#include<bits/stdc++.h>


using namespace std;


int main()
{

    // int a,b,n;
    // cin>>a>>b>>n;
    // //以 周  五天   两天  分别界定  而不是暴力模拟 太过复杂

    // int wek = 5 * a + 2 * b;//一周刷题量
    // int ans = n / wek * 7;//以周计算完  * 7 天  
    // n %= wek;
    // int wekday = 5 * a;
    
    // if(n <= wekday)
    // {
    //     ans += n / a + (n % a>0);       //n / a 先取出一般多少  余下的有剩余 + 1  
    //     //解决 计算 一天做多少事 最后一天是否做 (n / b + (n % b > 0);) n = 29 b = 20
    // }
    // else{
    //     n -= wekday;     
    //     // ans += 6 + (n> b);

    //     ans += 5 + n / b + (n % b > 0);
    // }
    long long a,b,n;
    int ans,reder;
    cin>>a>>b>>n;
    long long k = a * 5 + b * 2;
    ans += (n / k) * 7;//以整体为界 得到 周次  再求余下 
    reder = n % k;
    if(reder <= a * 5)
    {
        ans += reder / a + (reder % a != 0);
    }
    // else{
    //     reder -= a * 5;
    //     ans += 5 + (reder / b) + (reder % b != 0);
    // }
    //改进：已经确定有第6天  大于b 则第二天 
    else{
        reder -= a * 5;
        ans += 6 + (reder > b);
    }

    cout<<ans<<endl;
    return 0;
}
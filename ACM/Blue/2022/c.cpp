#include<bits/stdc++.h>


using namespace std;


int main()
{

    int a,b,n;
    cin>>a>>b>>n;
    //以 周  五天   两天  分别界定  而不是暴力模拟 太过复杂

    int wek = 5 * a + 2 * b;//一周刷题量
    int ans = n / wek * 7;//以周计算完  * 7 天  
    n %= wek;
    int wekday = 5 * a;
    
    if(n <= wekday)
    {
        ans += n / a + (n % a>0);       //n / a 先取出一般多少  余下的有剩余 + 1  
        //解决 计算 一天做多少事 最后一天是否做 (n / b + (n % b > 0);) n = 29 b = 20
    }
    else{
        n -= wekday;     
        // ans += 6 + (n> b);

        ans += 5 + n / b + (n % b > 0);
    }
    return 0;
}
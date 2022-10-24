#include<iostream>

typedef long long ll;
using namespace std;

class solution{

public:

    long long fastpow1_recur(ll a,ll b)
    {
        if(b == 0)
        {
            return 1;
        }
        ll ret = fastpow1_recur(a,b/2); 
        if(b%2 == 1)
        {
            return ret * ret * a;
        }
        else{
            return ret * ret;
        }
    }

    ll fastpowBin(ll a,ll b,ll m)//基于二进制为1 含有权重  与 移位权重增加 求幂
    {
        ll mul = 1;
        while(b)
        {
            if(b&1) //二进制下含有 权重
            {
               // mul = (a % m) * (mul % m) ;
                mul =  fast_mulBin(a,mul,m);
            }
            b = b>>1; //b 向右移动一位 b不变  只能a变  恰好在 幂处 所以乘以自身就是 起到了 b 2 倍作用 
            a = fast_mulBin(a,a,m);
        }
        return mul;
    }
    //加 减 乘  除法之前先取模  和 取模完后 加 减 乘  除法 得到一样  不信 找几个数字 

    ll fast_mulBin(ll a,ll b,ll m)////基于二进制为1 含有权重  与 移位权重增加 求幂 乘法之前先取模 
    {
        ll res = 0;
        while(b)
        {
            
            if(b&1)
            {
                res = (res % m)  + (a % m);
            }
            b = b>>1;  //该位权重 * 2 but b不能变  所以用 a 来变 b * a 移动后 b * (2 * a)
            // a = (2 * a);  == a +a 
            a = (a % m)  + (a % m);
        }
        return res;
    }
};



int main()
{

    //快速幂 a^b = a^b/2 * a^b/2 but 计算机中是b/2会向下取余所以 需要我们判断为奇/偶
    ll a,b,m;
    cin >>a>>b>>m;
    solution s;
    ll ret = s.fastpowBin(a,b,m);
    cout <<ret <<endl;
    return 0;
}
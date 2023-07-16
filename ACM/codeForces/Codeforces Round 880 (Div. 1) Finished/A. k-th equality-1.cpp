



//通过一个a  根据a + b = c  b范围 比+1+1迭代要好得多
//等式类型（不一定是严格四则运算等式） 根据 几个条件推导 要求的东西 
//这个即根据等式 + 每个数字范围
//a有范围 + a + b = c等式  枚举a范围 在等式条件 + a有确定值 看b的范围
#include<bits/stdc++.h>

using namespace std;


int t;
int a,b,c;
typedef long long ll;
ll k;

void sovle()
{
    cin>>a>>b>>c>>k;
    bool si = false;
    for(int i = pow(10,a-1);i<pow(10,a);i++)
    {
        //取交集 防止了a b大 c小情况 
        int min0 = max(pow(10,b-1),pow(10,c-1) - i);
        int max0 = min(pow(10,b) - 1,pow(10,c) - 1 - i);
        if(min0>max0) continue; //
        ll have = max0 - min0 + 1;//左右都闭
        if(k<=have)
        {
            //找到了值
            cout<<i<<" + "<<min0 + k-1<<" = "<<i + min0 + k-1<<"\n";
            si = true;
            break;
        }
        k -= have;//如果大于 相减
    }
    if(!si) cout<<"-1\n";
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
        sovle();


}
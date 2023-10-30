
//抓住细丝末节矛盾 进行操作  
//这类最多 最少 不是 化成函数 就是 硬猜
//分析：
//这道题 你能觉察到 二三在两边 更好，能够防止阻塞1  有 2 3 在子序列 很难保证 mex 为 素数
//所以 最有可能的将他们分散 即 放在两边 保证 子序列含有他俩最少 就一个！！！
//子序列 没有1 无法堵住素数
//1应该在中间，不知道为什么  但是感觉能够更多的堵住更多素数
//证明1在中间mex最多：函数 
//前面k中选择 后面 n-k-1 减去 1情况 
//假设 2 3 在两边 那么 k(n - k - 1) - mex(a1 a2....an) not prime
//k属于0 - n-1 明显 负二次函数 （n-1）/2时候最大 
//所以 2 3 在外面 1在中间 其他随便填
//主要矛盾写完
//<3情况各自分析
#include<bits/stdc++.h>

using namespace std;

int t;
int n;
void solve()
{
    cin>>n;
    if(n == 1) cout<<"1"<<endl;
    else if(n == 2) cout<<"2 1"<<endl;
    else if(n>=3){
        int x = 3;
        int a[n];
        memset(a,0,sizeof a);
        a[0] = 2;
        a[n-1] = 3;
        a[(n-1)/2] = 1;
        for(int i = 0;i<n;i++)
        {
            if(a[i] == 0)
            {
                a[i] = ++x;
            }
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }

}
int main()
{

    cin>>t;
    while(t--)
        solve();
    


    return 0;
}
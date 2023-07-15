

// x | y = x 不会使 x 没0的地方变成1  即 不会使 0 变成 x的路上 在不该出现 1 的地方变成1
//不会使 0->x路上 出现不该出现的1
//或：有1不会消失 检测不该出现1的地方 出现1
//x & y != y  
//与：有0不会消失 检测不该出现0的地方出现0
#include<bits/stdc++.h>

using namespace std;



int t;
int n,x;
const int N = 1e5+10;
int a[N];
void sovle()
{
    cin>>n>>x;
    long long ans = 0;
    for(int k = 1;k<=3;k++)
    {
        for(int i = 0;i<n;i++) 
            cin>>a[i];
        
        for(int i = 0;i<n;i++)
        {
            if((x|a[i]) != x ) break;
            ans |= a[i];
        }
    }
    cout<<(ans == x?"YES":"NO")<<"\n";
    

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
        sovle();


    return 0;
}
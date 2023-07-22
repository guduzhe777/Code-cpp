


#include<bits/stdc++.h>

using namespace std;

//分而治之 两个要求 分开操作
//
int t;
int n;
int a,b;
void sovle()
{
    cin>>n;
    a = b = 0;
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x == -1) a++;
        else b++;
        
    }
    if(a>b) ans = (a-b)/2 + ((a-b) % 2);
    else{
        ans = 0;
    }
    ans += (a - ans) % 2; 
    cout<<ans<<"\n";
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
#include<bits/stdc++.h>

using namespace std;

int n;
const int N = 21;
int dp[N];
int main()
{
    cin>>n;
    dp[1] = 1;
    for(int i = 2;i<=n;i++)
    {
        dp[i] = i * dp[i-1];
       
    }
    int sum = 0;
    for(int i = 1;i<=n;i++)
    {
        sum += dp[i];
    }
    cout<<sum<<endl;
    
    return 0;
}
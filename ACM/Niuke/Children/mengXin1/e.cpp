#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+10;
int n,m;
int sum;
int ans;
int a[N];
int main()
{
    cin>>n>>m;
    int j = 0;
    for(int i = 0;i<n;i++)
    {
        
        cin>>a[i];
        sum += a[i];
        if(sum == m)
        {   
            ans++;
        }else{
        while(j<=i && sum>m)
        {
            sum -= a[j];
            j++;
        }
        if(sum == m)
        {
            ans++;
        }
        }
        
    }
    cout<<ans;

    return 0;
}
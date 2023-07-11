#include<bits/stdc++.h>

using namespace std;

int t;
int ans;
int a,b;
int n;
int main()
{

    cin>>t;
    for(int i = 0;i<t;i++)
    {
        cin>>n;
        ans = 0;
        for(int i = 0;i<n;i++)
        {
            cin>>a>>b;
            if(a<=b)
            {
                ans++;
            }
        }
        cout<<n-ans<<endl;
    }

    return 0;
}
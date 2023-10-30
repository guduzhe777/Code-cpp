#include<bits/stdc++.h>

typedef long long ll;
int t;
int n,m;
ll ans1,ans2;

using namespace std;

void sovle()
{
    ans1 = 0,ans2 = 0;
    cin>>n>>m;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        ans1 += x;
    }
    for(int i = 0;i<m;i++)
    {
        int x;
        cin>>x;
        ans2 += x;
    }
    if(ans1>ans2) cout<<"Tsondu\n";
    else if(ans1<ans2) cout<<"Tenzing\n";
    else std::cout<<"Draw\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
        sovle();




    return 0;
}
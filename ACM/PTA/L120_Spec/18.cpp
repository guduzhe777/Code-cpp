#include<bits/stdc++.h>

using namespace std;



int n;
bool si[11];
int num[11];
void dfs(int x)
{
    if(x == n + 1)
    {
        bool fir = true;
        for(int i = 1;i<=n;i++)
        {
           printf("%d",num[i]);
        }
        cout<<"\n";
    }
    for(int i = 1;i<=n;i++)
    {
        if(!si[i])
        {
            si[i] = true;
            num[x] = i;
            dfs(x+1);
            si[i] = false;
        }
    }
}
int main()
{
    cin>>n;
    dfs(1);
    return 0;
}
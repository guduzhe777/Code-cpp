#include<bits/stdc++.h>
using namespace std;


int n,m;
const int N = 100010;
bool sign[N] = {false};
void dfs(int x)
{
    if(x == 0)
    {
        for(int i = 1;i<=n;i++)
        {
            if(sign[i])
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
        return;
    }
    sign[x] = false;
    dfs(x-1);
    sign[x] = true;
    dfs(x-1);
    

}
int main()
{
    cin>>n;//n 个选不选

    dfs(n);
    return 0;
}
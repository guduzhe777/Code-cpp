#include<bits/stdc++.h>

using namespace std;

int n;
const int N = 20;
bool f[N];

void obs(int x)
{
    if(x>n)
    {
        for(int i = 1;i<=n;i++)
        {
            if(f[i])
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
        return;
    }
    f[x] = true;//选
    obs(x+1);
    f[x] = false;//不选
    obs(x+1);
}
int main()
{
    cin>>n;
    obs(1);

    return 0;
}
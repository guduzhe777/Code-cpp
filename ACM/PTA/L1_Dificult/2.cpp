#include<bits/stdc++.h>

using namespace std;

const int N = 1E5+10;
bool si[N];
int n;
void prime(int n)
{
    for(int i = 2;i<=n;i++)
    {
        if(!si[i])
        {
            for(int j = i + i;j<=n;j += i)
            {
                si[j] = true;
            }
        }
    }
}
int cnt;
int main()
{
    cin>>n;
    prime(n);
    for(int i = 2;i<=n;i++)
    {
        if((i+2<=n)&&!si[i]&&!si[i+2])//同为素数
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
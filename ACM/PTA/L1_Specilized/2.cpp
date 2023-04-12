//每个素数输出占6列

#include<bits/stdc++.h>

using namespace std;
const int N  = 2e5+10;
bool si[N];

int n;
void prime(int n)
{
    for(int i = 2;i<=n;i++)
    {
        if(!si[i])
        {
            for(int j = 2 * i;j<=n;j += i)
            {
                si[j] = true;
            }
        }
    }
}
int main()
{
    cin>>n;
    prime(n);
    int cnt = 0;
    for(int i = n - 1;i>=2;i--)
    {
        if(!si[i])
        {
            cnt++;
            printf("%6d",i);
        }
        if(cnt == 10)
        {
            return 0;
        }
    }

    return 0;
}
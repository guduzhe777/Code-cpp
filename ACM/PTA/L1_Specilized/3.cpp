#include<bits/stdc++.h>

using namespace std;

int n;
int main()
{
    cin>>n;
    int cnt = 0;
    for(int i = 1;i<=n;i++)
    {
        if(i % 7 == 0||i % 10 == 7)
        {
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
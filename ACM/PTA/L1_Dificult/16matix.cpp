#include<bits/stdc++.h>


using namespace std;

int n;
int sum;
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            int x;
            cin>>x;
            if(i == n - j||i == n||j == n - 1)
            {
                continue;
            }
            sum += x;
        }
    }
    printf("%d\n",sum);
    return 0;
}
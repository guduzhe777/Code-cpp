#include<bits/stdc++.h>


using namespace std;
const int size = 5010;
int arr[size][size] = {0};
int N,R;
int x,y,w;
int min(int a,int b)
{
    return a<b?a:b;
}
 int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    cin>>N>>R;
    while(N--)
    {
        cin>>x>>y>>w;
        x++;
        y++;
        arr[x][y] += w;
    }
    R = min(R,5001);
    for(int i = 1;i<=5001;i++)
    {
        for(int j = 1;j<=5001;j++)
        {
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    //越界问题？ 越界肯定炸不到价值最高！！！
    int ans = 0;
    for(int i = R;i<=5001;i++)
    {
        for(int j = R;j<=5001;j++)
        {
            ans = max(ans,arr[i][j] - arr[i][j-R] - arr[i-R][j]+arr[i-R][j-R]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
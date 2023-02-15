#include<bits/stdc++.h>

using namespace std;

int R,N,ans = 0;
int stand = 5001;
const int size1 = 5010;
int arr[size1][size1] = {0};
int main()
{
    int x,y,w;
    cin>>N>>R;

    
    while(N--)
    {
        cin>>x>>y>>w;
        arr[++x][++y] += w;

    }
    R = min(5001,R);//当R太大 会造成 之间输出0 ！！！   所以判断一下 
    for(int i = 1;i<=5001;i++)
    {
        for(int j = 1;j<=5001;j++)
        {
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    for(int i = R;i<=5001;i++)
    {
        for(int j = R;j<=5001;j++)
        {
            ans = max(ans,arr[i][j] - arr[i][j-R] - arr[i-R][j] + arr[i-R][j-R]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
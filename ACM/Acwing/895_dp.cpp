#include<bits/stdc++.h>

using namespace std;


int N;
const int sz = 1010;
int num[sz],f[sz];
int main()
{
    cin>>N;
    for(int i = 1;i<=N;i++)
    {
        cin>>num[i];
    }
    for(int i = 1;i<=N;i++)
    {
        f[i] = 1;//假设只有一个值 
        for(int j = 1;j<i;j++)
        {
            if(num[j]<num[i])
            {
                f[i] = max(f[i],f[j] + 1);//原本到他最长 与 前面某个 +  1
            }
        }
    }
    int res = 0;
    for(int i = 1;i<=N;i++)
    {
        res = max(res,f[i]);
    }
    cout<<res<<endl;
    return 0;
}
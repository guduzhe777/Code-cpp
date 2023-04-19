#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
int si[N];
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    while(q--)
    {
        int t,c;
        cin>>t>>c;
        if(!t)//行
        {
            for(int i = 0,j = c - 1;i<m;i++)
            {
                si[i+j * m] = true;//被选择
            }
        }else{
            for(int j = c-1;j<n * m;j += m)
            {
                si[j] = true;
            }
        }
    }
    int cnt = 0;
    for(int i = 0;i<N;i++)
    {
        if(si[i])
        {
            cnt++;
        }
    }
    printf("%d\n",n*m - cnt);
    return 0;
}
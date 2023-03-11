#include<bits/stdc++.h>

using namespace std;
const int N = 100010;
int f[N];
int n,m,a,b,k;//数的个数和操作次数。 
//  k=0 表示求子数列[a,b]的和；k=1 表示第 a个数加 b
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
        scanf("%d",&f[i]);
    while(m--)
    {
        cin>>k>>a>>b;
        if(k)//k为1 
        {
            f[a] += b;
        }
        int sum = 0;
        if(!k)
        {
            for(int j = a;j<=b;j++)
            {
                sum += f[j];
            }
            cout<<sum<<endl;
        }
        
    }
    return 0;
}
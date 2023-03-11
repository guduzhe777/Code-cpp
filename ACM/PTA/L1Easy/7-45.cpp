#include<bits/stdc++.h>

using namespace std;

int n,r;
const int N = 210;
int f[N];
int tem;
void Bubble_Sort(int* f,int l,int r0)
{
    //次数
    //位置
    for(int i = 1;i<r0 - l;i++)
    {
        for(int j = l;j<r0 - i;j++)
        {
            if(f[j]>f[j+1])
            {
                tem = f[j];
                f[j] = f[j+1];
                f[j+1] =tem;
            }
        }
    }
}
int main()
{
    cin>>n>>r;
    
    for(int i= 0;i<n;i++)
        scanf("%d",&f[i]);
    Bubble_Sort(f,r,n-r);
    for(int i = 0;i<n;i++)
    {
        cout<<f[i]<<" ";
    }
    return 0;
}
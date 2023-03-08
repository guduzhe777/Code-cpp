#include<bits/stdc++.h>

using namespace std;
int n;
int  a[101],b[101],c[101];
int res;
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)  
        cin>>a[i];
    for(int i = 0;i<n;i++)  
        cin>>b[i];
    for(int i = 0;i<n;i++)  
        cin>>c[i];
    for(int i = 0;i<n;i++)  
        for(int j = 0;j<n;j++)  
            for(int k = 0;k<n;k++)  
                if((a[i]<b[j])&&(b[j]<c[k])) res++;
    cout<<res;
    return 0;
}
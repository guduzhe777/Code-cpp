#include<bits/stdc++.h>

using namespace std;

int a[21],b[21],c[21];
int n,m;
int k = 0;//保存不同
int main()
{
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i = 0;i<m;i++)
    {
        cin>>b[i];
    }
    int i,j;
    for( i = 0;i<n;i++)
    {
        for( j = 0;j<m;j++)
        {
            if(a[i] == b[j])
            {
                break;
            }
        }
        if(j == m)//不存在相等情况
        {
            c[k++] = a[i];
        }
    }
    for(i = 0;i<m;i++)
    {
        for(j = 0;j<n;j++)
        {
            if(b[i] == a[j])
            {
                break;
            }
        }
        if(j == n)
        {
            c[k++] = b[i];
        }
    }
    printf("%d",c[0]);
    for(i = 1;i<k;i++)
    {
        for(j = 0;j<i;j++)
        {
            if(c[i] == c[j])
            {
                break;
            }
        }
        if(j == i)//如果前面没有i
        {
            printf(" %d",c[i]);//   
        }
    }
    return 0;
}
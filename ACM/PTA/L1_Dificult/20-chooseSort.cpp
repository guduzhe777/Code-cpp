#include<bits/stdc++.h>

using namespace std;


//选择排序
int n;
const int N = 1e3;
int f[N];

int main()
{

    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>f[i];
    }
    for(int i = 0;i<n - 1;i++)
    {
        int maxpos = i;
        for(int j = i + 1;j<n;j++)
        {
            if(f[maxpos] < f[j])
            {
                maxpos = j;
            }
        }
        if(maxpos != i)
        {
            swap(f[maxpos],f[i]);
        }
    }
    bool fir = true;
    for(int i = 0;i<n;i++)
    {
        if(fir)
        {
            fir = 0;
            printf("%d",f[i]);
        }
        else{
            printf(" %d",f[i]);
        }
    }
    return 0;
}
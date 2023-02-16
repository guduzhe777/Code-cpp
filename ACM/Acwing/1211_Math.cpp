#include<bits/stdc++.h>

using namespace std;
int obs(int a)
{
    return a>0?a:-a;
}
int main()
{   
    int n,arr[60],x;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];        
    }
    int left_r = 0,right_l = 0;
    for(int i = 1;i<n;i++)
    {
        if(arr[i]>0&&obs(arr[i])<obs(arr[0])) left_r++;
        if(arr[i]<0&&obs(arr[i])>obs(arr[0])) right_l++;
    }
    if((arr[0]>0&&right_l == 0)||(arr[0]<0&&left_r== 0)) cout<<1<<endl;
    else{
        cout<<left_r + right_l + 1<<endl;
    }
    return 0;
}
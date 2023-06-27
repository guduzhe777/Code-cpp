#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+10;
int n;
int top;
int stk[N];
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        //左边第一个 大于x
        while(top && stk[top] <= x) top--;
        if(top) cout<<stk[top]<<' ';
        else {
            cout<<-1<<' ';
        }

        stk[++top] = x;
    }



    return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+10;
int n;
int top;
int stk[N];
int main()
{
    cin>>n;
    stk[++top] = -1e9;  //哨兵 到了最左/最右边边一定达到目的
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;

        while(stk[top] >= x) top--;
        if(stk[top]<=-1e6)
        {
            cout<<-1<<' ';
        }else{
            cout<<stk[top]<<' ';
        }

        stk[++top] = x;
    }



    return 0;
}
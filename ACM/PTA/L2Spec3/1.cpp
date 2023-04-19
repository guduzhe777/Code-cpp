#include<bits/stdc++.h>


using namespace std;

int n,m;
struct cmp1{
    bool operator() (int &a,int &b)
    {
        return a<b;
    }
};  
priority_queue<int,vector<int>,cmp1 > q;
int main()
{
    cin>>n>>m;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    m = min(n,m);
    bool fir = true;
    for(int i = 0;i<m;i++)
    {
        int frt = q.top();
        q.pop();
        if(fir)
        {
            fir = false;
            cout<<frt;
        }else{
            cout<<" "<<frt;
        }
    }
    return 0;
}
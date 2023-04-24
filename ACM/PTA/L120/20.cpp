#include<bits/stdc++.h>

using namespace std;


int n;
typedef pair<int,int> pii;
struct cmp{
    bool operator() (int a,int b)
    {
        
    }
};
map<int,int> mp;//标签与点赞数
int main()
{
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        for(int i = 0;i<k;i++)
        {
            int x;
            cin>>x;
            mp[x]++;
        }
    }
    pii max0;
    for(auto & v:mp)
    {
        if(v.second>max0.second||(v.second == max0.second&&v.first>max0.first))
        {
            max0 = v;
        }
    }
    cout<<max0.first<<" "<<max0.second<<endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n;
struct peo
{
    string s;
    int birthday;
    string phone;
};

vector<peo> peos;
bool cmp(peo &p1,peo &p2)
{
    return p1.birthday<p2.birthday;
}
int main()
{
    cin>>n;
    
    for(int i = 0;i<n;i++)
    {
        string s1,s2;
        int x;
        cin>>s1>>x>>s2;
        peos.push_back({s1,x,s2});
    }
    sort(peos.begin(),peos.end(),cmp);
    for(auto &[u,v,w]:peos)
    {
        cout<<u<<" "<<v<<" "<<w<<"\n";
    }
    return 0;
}
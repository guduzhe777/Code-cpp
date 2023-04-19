#include<bits/stdc++.h>


using namespace std;


struct peo{
    string name;
    int heigth,weight;
};


map<int,vector<peo> > mp;
int n;
bool cmp(peo &a,peo &b)
{
    if(a.heigth>b.heigth) return true;
    return false;
}
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int x;
        string s;
        int height,weight;
        cin>>x>>s>>height>>weight;
        mp[x].push_back({s,height,weight});
    }
    
    for(auto &v : mp)//v为 vector
    {
        sort(v.second.begin(),v.second.end(),cmp);
        printf("%06d ",v.first);
        cout<<v.second[0].name<<" ";
        printf("%d %d\n",v.second[0].heigth,v.second[0].weight);
    }
    return 0;
}
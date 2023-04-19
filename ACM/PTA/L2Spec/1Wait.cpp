#include<bits/stdc++.h>

using namespace std;


typedef pair<int,string> PIS;
vector<PIS> v;
bool cmp(PIS &a,PIS &b)
{
    if(a.second.size()<b.second.size())
    {
        return a.second.size()<b.second.size();
    }
    return a.first<b.first;//顺序
}
int main()
{

    int cnt = 0;
    while(1)
    {
        string s;
        cin>>s;
        if(s == "#")
        {
            break;
        }
        
        v.push_back({cnt,s});
        cnt++;
    }
    sort(v.begin(),v.end(),cmp);
    for(auto &str : v)
    {
        cout<<str.second<<" ";
    }
    return 0;
}
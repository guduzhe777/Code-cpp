#include<bits/stdc++.h>


using namespace std;
map<int,int> mp;
vector<int> v(1,0);
int n,m;
int main()
{
    cin>>n>>m;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
        push_heap(v.begin() + 1,v.end(),greater<int>() );
    }
    
    for(int i = 1;i<=n;i++)
        mp[v[i]] = i;
    while(m--)
    {
        bool si = false;//默认命题错误
        int x,y;
        cin>>x;
        string s;
        cin>>s;
        if(s == "is")
        {
            cin>>s;
            if(s == "a")
            {
                cin>>s;
                cin>>s;
                cin>>y;
                if(mp[x]/2 == mp[y])
                {
                    si =true;
                }
            }else{
                cin>>s;
                if(s == "root")
                {
                    if(mp[x] == 1)
                    {
                        si = true;
                    }
                }else{
                    cin>>s;
                    cin>>y;
                    if(mp[x] == mp[y]/2)
                    {
                        si = true;
                    }
                }
            }
        }else{
            
            cin>>y;
            if(mp[x] /2 == mp[y] / 2)
            {
                si = true;
            }
        }
        if(si)
        {
            printf("T\n");
        }else{
            printf("F\n");
        }
        getline(cin,s);
    }
    
    return 0;
}
//两个数组不同的元素
//去重两个数组  防止 前面有 后面 没有的情况存在

#include<bits/stdc++.h>

using namespace std;

unordered_set<int> st1,st2;
int n,m;
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        st1.insert(x);
    }
    cin>>m;
    for(int i = 0;i<m;i++)
    {
        int x;
        cin>>x;
        st2.insert(x);
    }
    for(auto v:st1)
    {
        auto pos = st2.find(v);
        if(pos == st2.end())
        {
            st2.insert(v);
        }else{
            st2.erase(pos);
        }
    }
    bool fir = 1;
    for(auto v:st2)
    {
        if(fir)
        {
            fir = 0;
            printf("%d",v);
        }else{
            printf(" %d",v);
        }
    }
    return 0;
}
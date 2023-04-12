//两个数组去重
//输出不相同的元素 一次
//防止多个不相同 set   st1: 3   3  st2:8 8  输出一次3即可
//


#include<bits/stdc++.h>

using namespace std;

unordered_set<int> st1,st2;
vector<int> c;//保存1/2中有 2/1没有
int main()
{
    int n,m;
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
    for(auto &v:st1)
    {
        auto pos = st2.find(v);
        if(pos == st2.end()) c.push_back(v);
    }
    for(auto &v:st2)
    {
        auto pos = st1.find(v);
        if(pos == st1.end()) c.push_back(v);
    }
    bool fir = true;
    for(auto v:c)
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
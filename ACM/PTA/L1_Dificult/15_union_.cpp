#include<bits/stdc++.h>

using namespace std;
//并集：1/2中有1/2中没有 for 1  看2有没有 2 看1中有没有 防止重复情况 双指针 防止前面出现过
int c[21];
unordered_set<int> a,b;
int n,m;
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        a.insert(x);

    }
    cin>>m;
    for(int i = 0;i<m;i++)
    {
        int x;
        cin>>x;
        b.insert(x);
    }
    int k = 0;
    for(auto v:a)
    {
        auto pos = b.find(v);
        if(pos == b.end())
        {
            c[k++] = v;
        }
    }
    for(auto v:b)
    {
        auto pos = a.find(v);
        if(pos == a.end())
        {
            c[k++] = v;
        }
    }
    
    printf("%d",c[0]);
    for(int i = 1;i<k;i++)
    {
        bool si = false;//默认这个数字未输出
        for(int j = 0;j<i;j++)
        {
            if(c[i] == c[j])
            {
                si = true;
                break;
            }
        }
        if(!si)
        {
            printf(" %d",c[i]);
        }
    }
    return 0;
}
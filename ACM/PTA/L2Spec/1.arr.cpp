#include<bits/stdc++.h>

using namespace std;



string s[25];
bool cmp(string a,string b)
{
    return a.size()<b.size();
}
int main()
{
    string s1;
    cin>>s1;
    int i  = 0;
    while(s1 != "#")
    {
        s[i++] = s1;
        cin>>s1;
    }
    stable_sort(s,s+i,cmp);
    for(int j = 0;j<i;j++)
    {
        cout<<s[j]<<" ";
    }
    return 0;
}
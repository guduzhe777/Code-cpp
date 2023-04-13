#include<bits/stdc++.h>

using namespace std;



string s[25];
bool cmp(string s1,string s2)
{
    return s1.length()<s2.length();
}
int main()
{

    int n = 0;
    while(1)
    {
        getline(cin,s[n]);
        if(s[n] == "#")
        {
            break;
        }
        n++;

    }
    sort(s,s+n,cmp);
    for(int i = 0;i<n;i++)
    {
        cout<<s[i]<<" ";
    }
    return 0;
}
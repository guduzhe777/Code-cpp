#include<bits/stdc++.h>

using namespace std;

int n;
string s[210];

int main()
{
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i =0;i<n;i++)
    {
        string str = s[i].substr(6,5);
        cout<<"6"<<str<<"\n";
    }
    return 0;
}